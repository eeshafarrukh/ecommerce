#pragma once
#include "sj.h"

#include "Loginform.h"
#include "startform.h"
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Windows::Forms;
bool usertype = 0;
void main()
{
	
	//Boutique mainboutique;
	//mainboutique.operation();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	sdaproject::startform startForm;
	startForm.ShowDialog();
	
	
	
	int desig;
	int cus;
	cout << "**************Weclome to S&J Boutique*************\n";

	
	if (usertype == 0)
	{
		SalesA sa;
		FloorM fm;
		int choice;
		cout << "**************Employee*************\n";
		cout << "1:Mark Attendance\n2:Scan RFID\nEnter choice: ";
		cin >> choice;
		if (choice == 1)
		{
			sa.markAttendane();
		}
		else if (choice == 2)
		{
			fm.scanRFID();
		}

	}
	else if (usertype == 1)
	{
		int choice;
		Customer c1;
		cout << "**************S&J BOUTIQUE*************\n";
		cout << "1:Checkout\n2:Get Loyalty Card\n3:Get Discount\nEnter choice: ";
		cin >> choice;
		if (choice == 1)
		{

			c1.checkOut();
		}
		else if (choice == 2)
		{
			c1.getLoyaltyCard();
		}
		cin >> cus;
	}
	system("pause");
}
