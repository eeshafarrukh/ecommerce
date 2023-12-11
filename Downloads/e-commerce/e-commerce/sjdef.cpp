
#include <iostream>
#include <fstream>
#include <string.h>
#include "sj.h"
#include <sstream>
#include <string>
#include <string.h>
#include <chrono>
#include <ctime>
using namespace std;
bool isnumber(string str) {
    // initializing int type variables to
    // perform operations
    int index, check = 0;
    // for loop to traverse the whole string
    for (index = 0; str[index]; index++) {
        // for loop to traverse the whole string
        for (index = 0; str[index]; index++) {
            // if condition to check if the string is Alphabet
            if ((str[index] >= '0' && str[index] <= '9')) {
                check++;
            }
            else {
                check = 0;
                break;
            }
        }

        if (check != 0) {
            return true;
        }
        else {
            return false;
        }
    }
}
void paymentprocess()
{
    int choice;
    char order;
    cout << "Select Mode for delivery:";
    cout << "Enter 1 for COD" << endl
        << "2 for Bank Transfer";
    cin >> choice;
    cout << "Enter Y to place your order: ";
    cin >> order;
    if (order == 'Y')
        cout << "Thankyou for placing an order. Your order has been recieved. Here is your order number #" << 1 + rand() % 1000;

}
bool phonenolength(string str) //to check the length of the entered phone number
{
    int length = str.size();
    if (length == 11)
        return true;
    else
        return false;
}
bool isAlphabet(string str) {
    // initializing int type variables to
    // perform operations
    int index, check = 0;
    // for loop to traverse the whole string
    for (index = 0; str[index]; index++) {
        // for loop to traverse the whole string
        for (index = 0; str[index]; index++) {
            // if condition to check if the string is Alphabet
            if ((str[index] >= 'A' && str[index] <= 'Z') ||
                (str[index] >= 'a' && str[index] <= 'z') || (str[index] == 32)) {
                check++;
            }
            else {
                check = 0;
                break;
            }
        }

        if (check != 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

int applydiscountcode(int amount)
{
    string disccode, filecode;
    int percentage = 0;
    float deduct = 0;
    bool codefound = false;

    //allows user to enter the discount code
    cout << "Enter discount code: ";
    cin >> disccode;


    //for reading file 
    ifstream file;

    // open the file
    file.open("discountcodes.txt");


    if (file)
    {
        //reading from file
        while (file >> filecode >> percentage)
        {
            //disocunt code found
            if (disccode == filecode)
            {
                //to check existence pf code
                codefound = true;

                //calculating new amount after discount is applied
                cout << "Your current amount is " << amount << endl;
                deduct = percentage / static_cast<float>(100);
                amount = amount - (amount * deduct);
                cout << "Your discount code was applied. New amount is " << amount << endl;

                break;
            }
        }

        //check for discount entered not found
        if (codefound == false)
        {
            cout << "Your discount code entered does not exist" << endl;
        }

        //closing file
        file.close();

        return amount;
    }


    return amount;
}
void customerdetailsverification()
{
    string fname, lname, address, city, country, number, email;
    cout << "Billing Details " << endl;
    cout << "First name: ";
    getline(cin, fname);
    cout << "Last name: ";
    getline(cin, lname);
    cout << "Address: ";
    getline(cin, address);
    cout << "City: ";
    getline(cin, city);
    cout << "Phone Number: ";
    getline(cin, number);
    cout << "Email (optional): ";
    getline(cin, email);
    //if any alphabet found in name, city, country or any required field left empty

    while (fname.empty() != false && isAlphabet(fname) != true)
    {
        if (fname.empty() == true)
        {
            cout << "First Name cannot be left empty. Please enter the correct details:";
            getline(cin, fname);
        }
        if (isAlphabet(fname) == false)
        {
            cout << "First Name cannot contain numbers: ";
            getline(cin, fname);
        }
    }
  while (lname.empty()!= false && isAlphabet(lname) != true)
  {
      if (lname.empty() == true)
      {
          cout << "Last Name cannot be left empty. Please enter the correct details:";
          getline(cin, lname);
      }
       if (isAlphabet(lname) == false)
       {
           cout << "Last Name cannot contain numbers. Please enter Last Name again:  ";
           getline(cin, lname);
       }
   }
   while (address.empty() != false)
   {
       if (address.empty() == true)
       {
           cout << "Field address cannot be left empty. Please enter the correct details:";
           getline(cin, address);
       }
   }
   while (city.empty() != false && isAlphabet(city) != true)
   {
       if (city.empty() == true)
       {
           cout << "City cannot be left empty. Please enter the correct details:";
           getline(cin, city);
       }
       if (isAlphabet(city) == false)
       {
           cout << "City cannot contain numbers. Please enter details again: ";
           getline(cin, city);
       }
   }

    if (number.empty() == true)
    {
        cout << "Field Phone Number cannot be left empty. Please enter the correct details:";
        getline(cin, number);
    }

    if (phonenolength(number) == false)
    {
        cout << "Phone number length is not valid. Please enter correct contact details: ";
        getline(cin, number);

    }

    if (isnumber(number) == false)
    {
        cout << "Number cannot contain alphabets or any characters. Please enter phone details: ";
        getline(cin, number);
    }

    while (number.empty() == true || phonenolength(number) == false || isnumber(number) == false)
    {
        cout << "Please enter phone number again: ";
        cin >> number;

        if (number.empty() == true)
        {
            cout << "Field Phone Number cannot be left empty. Please enter the correct details:";
            getline(cin, number);
        }

        if (phonenolength(number) == false)
        {
            cout << "Phone number length is not valid. Please enter correct contact details: ";
            getline(cin, number);

        }

        if (isnumber(number) == false)
        {
            cout << "Number cannot contain alphabets or any characters. Please enter phone details: ";
            getline(cin, number);
        }
    }

    char choice;
    cout << "Enter Y to Proceed to Payment: ";
    cin >> choice;
    if (choice != 'Y')
    {
        cout << "Sorry! We cannot proceed until Y is not pressed";
    }
    else
    {
        paymentprocess();
    }
}

User::User()
{

}

User::~User()
{

}

Boutique::Boutique()
{

}
//Boutique* Boutique::operation()
//{
//	if (instance == NULL)
//		instance = new Boutique();
//	return instance;
//} 
Boutique::~Boutique()
{

}

Customer::Customer()
{

}

Customer::~Customer()
{

}

void Customer::displayPurchaseHistory(int CID)
{

}

void FloorM::scanRFID()
{
    int rfid;
    int srfid = 0;
    string firstname, lastname, cardType;
    int loyPoints = 0;
    bool found = false;

    ifstream fin;
    fin.open("rfid.txt", ios::in);

    int choice;
    cout << "Choose: " << endl <<
        "1: Entrance" << endl << "2: Checkout" << endl;
    cin >> choice;

    cout << "Enter Customer RFID(only authorised for store managers): ";
    cin >> rfid;
    if (fin.is_open())
    {
        while (fin >> srfid >> firstname >> lastname >> loyPoints >> cardType)
        {
            if (srfid == rfid)
            {
                found = true;
                cout << "Customer Found" << endl;
                cout << "Customer Name: " << firstname << " " << lastname << endl;
                cout << "Loyalty Points: " << loyPoints << endl;
                cout << "Loyalty Card Type: " << cardType << endl;
            }
        }
        fin.close();

        if (found == false)
        {
            cout << "Customer not found in the database." << endl;
        }
    }
    int crfid = 0;
    crfid = rfid;

    if (choice == 2)
    {
        int amount = 0;
        int newpoints = 0;
        string newcardtype;
        cout << "Enter order amount: ";
        cin >> amount;
        int cpoints = 0;
        loyPoints = cpoints;
        string ctype;
        ctype = cardType;

        if (amount < 10000)
        {
            newpoints = cpoints + 50;
        }
        else if (amount >= 10000)
        {
            newpoints = cpoints + 100;
        }
        else if (amount >= 20000)
        {
            newpoints = cpoints + 200;
        }
        else if (amount >= 30000)
        {
            newpoints = cpoints + 300;
        }
        else if (amount >= 40000)
        {
            newpoints = cpoints + 400;
        }
        else if (amount >= 50000 && amount < 100000)
        {
            newpoints = cpoints + 500;
        }
        else if (amount >= 10000)
        {
            newpoints = cpoints + 1000;
        }

        if (cpoints < 500)
        {
            newcardtype = "silver";
        }
        else if (cpoints >= 500 && cpoints<1000)
        {
            newcardtype = "gold";
        }
        else if (cpoints > 1000)
        {
            newcardtype = "platinum";
        }
        string fn, ln;
        ofstream fout("rfid.txt");
        while (fin >> rfid >> firstname >> lastname >> loyPoints)
        {
            if (rfid == crfid)
            {
                fn = firstname;
                ln = lastname;
                fout << crfid << fn << ln << newpoints << newcardtype << endl;

                cout << "Database updated." << endl;
            }
            fin.close();

            if (found == false)
            {
                cout << "Customer not found in the database." << endl;
            }
        }
    }
}

void Customer::signIn()
{

}

void Customer::sighUp()
{

}
void Customer::getLoyaltyCard()
{
    ifstream fin;
    fin.open("rfid.txt", ios::in);
    int rfid;
    int srfid;
    int loyPoints = 0;
    bool found = false;
    string cType;
    string firstname, lastname, cardType;
    cout << "Enter Customer RFID: "; //done by scanning card
    cin >> rfid;
    if (fin.is_open())
    {
        while (fin >> srfid >> firstname >> lastname >> loyPoints >> cardType)
        {
            if (srfid == rfid)
            {

                found = true;
              
                cout << "Customer Name: " << firstname << " " << lastname << endl;
                cout << "Loyalty Points: " << loyPoints << endl;
                cout << "Loyalty Card Type: " << cardType << endl;
                if (loyPoints >= 0 && loyPoints < 500)
                {
                    cType = "SILVER";
                }
                else if (loyPoints >= 500 && loyPoints < 1000)
                {
                    cType = "GOLD";
                }
                else if (loyPoints >= 1000)
                {
                    cType = "Platinum";
                }

            }

        }
        cout << "\nCard Type: " << cardType;
        fin.close();
    }
  

}

void Customer::addtoCart()
{

}

void Customer::checkOut()
{
    
    
    customerdetailsverification();
    fstream checkout;
    checkout.open("orderlist.txt", ios::in); //open a file to perform read operation using file object
    if (checkout.is_open()) {   //checking whether the file is open
        string info;
        while (getline(checkout, info)) { //read data from file object and put it into string.
            cout << info << " "; //print the data of the string
        }
        checkout.close(); //close the file object.
    }
   
   
}

void Customer::makePay()
{

}

NewC::NewC()
{

}

NewC::~NewC()
{

}

OldC::OldC()
{

}

OldC::~OldC()
{

}

Guest::Guest()
{

}

Guest::~Guest()
{

}

Staff::Staff()
{

}

Staff::~Staff()
{

}

InventoryM::InventoryM()
{

}

InventoryM::~InventoryM()
{

}

void InventoryM::manageInventory()
{

}

FloorM::FloorM()
{

}

FloorM::~FloorM()
{

}

void FloorM::trackAttendance(int SID)
{

}

void FloorM::processReturns()
{

}

void FloorM::editShift(int SID)
{

}

BranchM::BranchM()
{

}

BranchM::~BranchM()
{

}

void BranchM::viewCustomerInfo(int CID)
{

}

void BranchM::directSalesAgent(int SID)
{

}

void BranchM::createAcc()
{

}

void BranchM::modifyAcc()
{

}

void BranchM::generateProgReport()
{

}

StoreAdmin::StoreAdmin()
{

}

StoreAdmin::~StoreAdmin()
{

}

void StoreAdmin::manageUsers()
{

}

void StoreAdmin::generateTaxReport()
{

}

void StoreAdmin::editOutlets()
{

}

SalesA::SalesA()
{

}

SalesA::~SalesA()
{

}

void SalesA::scanLoyaltyCard()
{

}

void SalesA::markAttendane()
{
	string filename = "attendace.txt";

	ofstream outfile;

	// opening file using ofstream
	outfile.open(filename, ios::app);
	if (outfile)
	{

		char emppresent[50];
		auto s = std::chrono::system_clock::now();
		auto ls = std::chrono::system_clock::to_time_t(s);
		char buffer[70];
		ctime_s(buffer, sizeof(buffer), &ls);
		cout << buffer;

		//outfile << buffer;
		string emp, space = { " " };
		int n;
		cout << "How many employees are present today? ";
		cin >> n;


		outfile << buffer;
		for (int i = 0; i < n; i++)
		{
			cout << "Enter ID of employee number " << i + 1 << ":\n";
			cin >> emp;
			outfile << emp << " ";
		}

		outfile << endl;

		cout << "Attendace marked!\n";
		outfile.close();

	}
	else
	{
		cout << "File not open.\n";
	}


}




LoyaltyC::LoyaltyC()
{

}

LoyaltyC::~LoyaltyC()
{

}

void LoyaltyC::updatePoints()
{

}

void LoyaltyC::updateCardType()
{

}

Discounts::Discounts()
{

}

Discounts::~Discounts()
{

}

double Discounts::calcDiscount()
{
	double disc=0.8;
	return disc;
}

extPaymentSystem::extPaymentSystem()
{

}

extPaymentSystem::~extPaymentSystem()
{

}

void extPaymentSystem::processPayment()
{

}