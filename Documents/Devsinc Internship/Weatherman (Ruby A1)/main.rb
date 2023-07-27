# frozen_string_literal: true
require 'colorize'
module Helper
  def update_min_temp(date, current_min_temp, min_temp)
    if min_temp[0] > current_min_temp
      min_temp[0] = current_min_temp
      min_temp[1] = date
    end
    min_temp
  end
  def update_max_temp(date, current_max_temp, max_temp)
    if max_temp[0] < current_max_temp
      max_temp[0] = current_max_temp
      max_temp[1] = date
    end
    max_temp
  end

  def update_max_humidity(date, current_max_humidity, max_humidity)
    if max_humidity[0] < current_max_humidity
      max_humidity[0] = current_max_humidity
      max_humidity[1] = date
    end
    max_humidity
  end

  def max_tempr(current_mean_temp, high_mean_temp)
    return current_mean_temp if high_mean_temp < current_mean_temp
  end

  def low_tempr(current_mean_temp, low_mean_temp)
    return current_mean_temp if low_mean_temp > current_mean_temp
  end

  def total_humid(total_humidity, total_days)
    total_humidity / total_days
  end
end

class Weatherman
  include Helper

  def given_year(year, base_dir)
    file_pattern = File.join(base_dir, "#{base_dir}_#{year}_*.txt")
    matching_files = Dir.glob(file_pattern)
    max_temp = [-100, '']
    min_temp = [100, '']
    max_humidity = [-100, '']

    matching_files.each do |path|
      File.open(path, 'r') do |file|
        file.each_line.with_index do |line, index|
          next if index.zero?

          date, current_max_temp, _, current_min_temp, _, _, _, current_max_humidity = line.split(',')
          current_max_temp = current_max_temp.to_i
          current_min_temp = current_min_temp == '' ? max_temp[0] : current_min_temp.to_i
          current_max_humidity = current_max_humidity.to_i
          max_temp = update_max_temp(date, current_max_temp, max_temp)
          min_temp = update_min_temp(date, current_min_temp, min_temp)
          max_humidity = update_max_humidity(date, current_max_humidity, max_humidity)
        end
      end
    end

    "Highest: #{max_temp[0]}C on #{max_temp[1]} \nHumid: #{max_humidity[0]}% on #{max_humidity[1]}
Lowest: #{min_temp[0]}C on #{min_temp[1]}"
  end

  def given_month(year, month, base_dir)
    high_mean_temp = -100
    low_mean_temp = 100
    total_humidity = 0
    total_days = -1
    file_pattern = File.join(base_dir, "#{base_dir}_#{year}_#{month}.txt")
    matching_file = Dir.glob(file_pattern)
    path = matching_file[0]

    File.open(path, 'r') do |file|
      file.each_line.with_index do |line, index|
        next if index.zero?

        _, _, current_mean_temp, _, _, _, _, _, current_mean_humidity = line.split(',')
        current_mean_temp = current_mean_temp.to_i
        current_mean_humidity = current_mean_humidity.to_i
        total_humidity += current_mean_humidity
        total_days += 1
        high_mean_temp = max_tempr(current_mean_temp, high_mean_temp)
        low_mean_temp = low_tempr(current_mean_temp, low_mean_temp)
      end
    end

    average_humidity = total_humid(total_humidity, total_days)
    "Highest Average: #{high_mean_temp}C  \nLowest Average: #{low_mean_temp}C
Average Humidity: #{average_humidity}%"
  end

  def print_temp(day, current_max_temp, current_min_temp)
    num_red_signs = current_max_temp
    num_blue_signs = current_min_temp
    red_signs = '+'.colorize(:red) * num_red_signs
    blue_signs = '+'.colorize(:blue) * num_blue_signs
    # puts "#{day} #{red_signs} #{current_max_temp}C"
    # puts "#{day} #{blue_signs} #{current_min_temp}C"
    puts "#{day} #{blue_signs}#{red_signs} #{current_min_temp}C-#{current_max_temp}C "
  end

  def create_bar_chart(year, month, base_dir, mon)
    months = %w[January February March April May June July August September October
                November December]

    file_pattern = File.join(base_dir, "#{base_dir}_#{year}_#{month}.txt")
    matching_file = Dir.glob(file_pattern)
    path = matching_file[0]
    puts "#{months[mon]} #{year}"

    File.open(path, 'r') do |file|
      file.each_line.with_index do |line, index|
        next if index.zero?

        date, current_max_temp, _, current_min_temp = line.split(',')
        current_max_temp = current_max_temp.to_i
        current_min_temp = current_min_temp.to_i
        year, month, day = date.split('-').map(&:to_i)
        print_temp(day, current_max_temp, current_min_temp)
      end
    end
  end
end

months = %w[Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec]
option = ARGV[0]

case option
when '-e'
  year = ARGV[1]
  base_dir = ARGV[2]
  puts Weatherman.new.given_year(year, base_dir)
when '-a'
  date = ARGV[1]
  base_dir = ARGV[2]

  year, mon = date.split('/')
  mon = mon.to_i
  mon -= 1

  puts Weatherman.new.given_month(year, months[mon], base_dir)

when '-c'
  date = ARGV[1]
  base_dir = ARGV[2]

  year, mon = date.split('/')
  mon = mon.to_i
  mon -= 1
  Weatherman.new.create_bar_chart(year, months[mon], base_dir, mon)
end
