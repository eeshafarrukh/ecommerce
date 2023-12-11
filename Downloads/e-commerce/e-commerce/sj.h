#pragma once
#include <iostream>
#include <string.h>
using namespace std;
using namespace System;
public ref class User
{
	
public:
	int id;
	String^ name;
	String^ email;
	String^ phone;
	String^ address;
	String^ password;

	User();
	~User();

};

class Boutique
{
private:
	int BID;
public:
	Boutique();
	static Boutique* operation();
	static Boutique* instance;
	~Boutique();
	
};

public ref class Customer : public User
{
private:
	int CID;

public:
	void displayPurchaseHistory(int CID);

	void signIn();
	void sighUp();
	void addtoCart();
	void getLoyaltyCard();
	void checkOut();
	void makePay();
	Customer();
	~Customer();
};

public ref class NewC : public Customer
{
public:
	NewC();
	~NewC();
};

public ref class OldC : public Customer
{
public:

	OldC();
	~OldC();
};

public ref class Guest : public Customer
{
public:
	Guest();
	~Guest();
};

public ref class Staff : public User
{
	
private:
	int SID;
public:
	Staff();
	~Staff();
};

public ref class InventoryM : public Staff
{
public:

	InventoryM();
	~InventoryM();
	void manageInventory();
};

public ref class FloorM : public Staff
{
public:

	FloorM();
	~FloorM();
	void trackAttendance(int SID);
	void processReturns();
	void scanRFID();
	void editShift(int SID);

};

public ref class BranchM : public Staff
{
public:
	BranchM();
	~BranchM();
	void viewCustomerInfo(int CID);
	void directSalesAgent(int SID);
	void createAcc();
	void modifyAcc();
	void generateProgReport();
};

public ref class StoreAdmin : public Staff
{public:
	StoreAdmin();
	~StoreAdmin();
	void manageUsers();
	void generateTaxReport();
	void editOutlets();

};

public ref class SalesA : public Staff
{
public:

	SalesA();
	~SalesA();
	void scanLoyaltyCard();
	void markAttendane();
};

class LoyaltyC
{

private:
	int points;
	string cardType;
public:
	void updatePoints();
	void updateCardType();
	LoyaltyC();
	~LoyaltyC();
};

class Discounts
{
	
private:
	string eventType;
	int discVal;
public:
	double calcDiscount();
	Discounts();
	~Discounts();
};

class extPaymentSystem
{
	
private:

public:
	void processPayment();
	extPaymentSystem();
	~extPaymentSystem();
};