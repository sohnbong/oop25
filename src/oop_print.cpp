// This sample code shows the example of
// (i)    encapsulation (private, protected, public)
// (ii)   inheritance
// (iii)  polymorphism
//           - overriding (dynamic binding)
//           - virtual function
// (iv)   copy constructor (e.g. Account(const Account& a); , ...)
// (v)    const member function, container class (AccManager class)

////////////////////////// main.cpp     ///////////////////////////
#include "AccManager.h"

// main function
int main()
{
	AccManager accmgr;
	int choice;

	while(1)
	{

		accmgr.menuDisplay();
		cin >> choice;

		switch(choice)
		{
		case 1:
			accmgr.openAccount();
			break;
		case 2:
			accmgr.deposit();
			break;
		case 3:
			accmgr.withdraw();
			break;
		case 4:
			accmgr.checkAllCustomerBalance();
			break;
		case 5:
			return 0;
		default:
			cout << "Your selected number is wrong!!" << endl;
			break;
		}
	}

	return 0;
}

////////////////////////// AccManager.h ///////////////////////////
#ifndef _ACCMANAGER_H_
#define _ACCMANAGER_H_
#include "Account.h"

// AccManager Class declaration
class AccManager 
{
private:
	Account *arrAccount[100];
	int index;
public:
	// Very Important to initialize index variable
	AccManager():index(0){};
	~AccManager(){};
	void menuDisplay() const;
	void menuAccount() const;
	void openAccount();
	void deposit();
	void withdraw();
	void checkAllCustomerBalance() const;
};

#endif

////////////////////////// Account.h //////////////////////////////
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Account Class declaration
class Account
{
protected:
	int accountId;
	char *customerName;
	double balance;
public:
	Account(){};
	Account(int _accountId, char *_customerName, double _balance);
	Account(const Account& a);
	~Account();
	virtual void addBalance(double _money);
	void minusBalance(double _money);
	// Accessor member function
	int getAccountId() const;
	const char* getCustomerName() const;
	virtual double getDonation() const;
	virtual double getBalance() const;
};

#endif

////////////////////////// CreditAccount.h ////////////////////////////
#ifndef _CREDITACCOUNT_H_
#define _CREDITACCOUNT_H_
#include "Account.h"

// CreditAccount Class declaration
class CreditAccount : public Account
{
public:
	CreditAccount(){};
	~CreditAccount(){};
	CreditAccount(int _accountId, char *_customerName, double _balace):Account(_accountId, _customerName, _balace){};
	void addBalance(double _money);
};

#endif

////////////////////////// DonationAccount.h ////////////////////////////
#ifndef _DONATIONACCOUNT_H_
#define _DONATIONACCOUNT_H_
#include "Account.h"

// Donation Class declaration
class DonationAccount : public Account
{
private:
	double amountDonation;
public:
	DonationAccount(){};
	~DonationAccount(){};
	DonationAccount(int _accountId, char *_customerName, double _balance, double _donation);
	void addDonation(double _donation);
	void addBalance(double _money);
	double getDonation() const;
};

#endif

//////////////////////////////////////////////////////////////////////
////////////////////////// AccManager.cpp ////////////////////////////
nclude "AccManager.h"
#include "CreditAccount.h"
#include "DonationAccount.h"

// Control Class - AccManager definition
void AccManager::menuDisplay() const
{
	cout << "+---------------------------------+" << endl;
	cout << "|      MANAGE BANK ACCOUNT        |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "| 1. OPEN ACCOUNT                 |" << endl;
	cout << "| 2. DEPOSIT                      |" << endl;
	cout << "| 3. WITHDRAW                     |" << endl;
	cout << "| 4. CHECK ALL CUSTOMER'S BALANCE |" << endl;
	cout << "| 5. QUIT                         |" << endl;
	cout << "+---------------------------------+" << endl;
	cout << "Select number ? "; 
}

void AccManager::menuAccount() const
{
	cout << "+---------------+" << endl;
	cout << "|    ACCOUNT    |" << endl;
	cout << "+---------------+" << endl;
	cout << "| 1. GENERAL    |" << endl;
	cout << "| 2. CREDIT     |" << endl;
	cout << "| 3. DONATION   |" << endl;
	cout << "+---------------+" << endl;
	cout << "Which would you like to open account ? ";
}


void AccManager::openAccount()
{
	int id;
	char name[30];
	double deposit;
	double donation;
	int number;

	cout << endl << "WELCOME TO MY BANK !!" << endl;
	cout << "< OPEN ACCOUNT >" << endl;

	cout << "MAY I HAVE YOUR CREATE ACCOUNT NUMBER ? (4 digit, eg.1111) ";
	cin >> id;
	cout << "MAY I HAVE YOUR NAME ? ";
	cin >> name;
	cout << "HOW MUCH DO YOU WANT TO DEPOSIT ? ";
	cin >> deposit;


	menuAccount();
	cin >> number;

	switch(number)
	{
	case 1:
		cout << "!!! Thank you for opening General Account !!!" << endl;
		arrAccount[index] = new Account(id, name, deposit);
		break;
	case 2:
		deposit = deposit + (deposit * 0.01);
		cout << "!!! Thank you for opening Credit Account !!!" << endl;
		arrAccount[index] = new CreditAccount(id, name, deposit);
		break;
	case 3:
		donation = deposit * 0.01;
		deposit = deposit - donation;
		cout << "!!! Thank you for opening Donation Account !!!" << endl;
		arrAccount[index] = new DonationAccount(id, name, deposit, donation);
		break;
	default:
		cout << "Select number error!!!!" << endl;
		break;
	}

	cout << endl;
	cout << ". YOUR ACCOUNT  : " << arrAccount[index]->getAccountId() << endl;
	cout << ". YOUR NAME     : " << arrAccount[index]->getCustomerName() << endl;
	cout << ". YOUR BALANCE  : " << arrAccount[index]->getBalance() << endl << endl; 

	index++;
	
}

void AccManager::deposit()
{
	int n;
	int flag = 0;
	int number;
	int depositMoney;

	cout << endl << "WELCOME TO MY BANK!!" << endl;	
	cout << "< DEPOSIT >" << endl;

	cout << "WHAT IS YOUR ACCOUNT NUMBER ? ";
	cin >> number;
	for(int i = 0; i < index ; i++)
	{
		if(arrAccount[i]->getAccountId() == number)
		{
			cout << ". YOUR ACCOUNT  : " << arrAccount[i]->getAccountId() << endl;
			cout << ". YOUR NAME     : " << arrAccount[i]->getCustomerName() << endl;
			cout << "IS TAHT RIGHT (Yes-1 / No-2) ? ";
			cin >> n;
			if(n==1)
				flag = 1;	
		}

		if(flag == 1)
		{
			cout << "HOW MUCH DO YOU WANT TO DEPOSIT ? ";
			cin >> depositMoney;
	
			arrAccount[i]->addBalance(depositMoney);

			cout << ". YOUR ACCOUNT  : " << arrAccount[i]->getAccountId() << endl;
			cout << ". YOUR NAME     : " << arrAccount[i]->getCustomerName() << endl;
			cout << ". YOUR BALANCE  : " << arrAccount[i]->getBalance() << endl;
			return;
		}
	}
	cout << "Your account number is wrong !!" << endl;
}

void AccManager::withdraw()
{
	int n;
	int flag = 0;
	int number;
	int withdrawMoney;

	cout << endl << "WELCOME TO MY BANK!!" << endl;	
	cout << "< WITHDRAW >" << endl;

	cout << "WHAT IS YOUR ACCOUNT NUMBER ? ";
	cin >> number;
	for(int i = 0; i < index ; i++)
	{
		if(arrAccount[i]->getAccountId() == number)
		{
			cout << ". YOUR ACCOUNT  : " << arrAccount[i]->getAccountId() << endl;
			cout << ". YOUR NAME     : " << arrAccount[i]->getCustomerName() << endl;
			cout << "IS TAHT RIGHT (Yes-1 / No-2) ? ";
			cin >> n;
			if(n==1)
				flag = 1;	
		}

		if(flag == 1)
		{
			cout << "HOW MUCH DO YOU WANT TO WITHDRAW ? ";
			cin >> withdrawMoney;
	
			arrAccount[i]->minusBalance(withdrawMoney);

			cout << ". YOUR ACCOUNT  : " << arrAccount[i]->getAccountId() << endl;
			cout << ". YOUR NAME     : " << arrAccount[i]->getCustomerName() << endl;
			cout << ". YOUR BALANCE  : " << arrAccount[i]->getBalance() << endl;
			return;
		}
	}
	cout << "Your account number is wrong !!" << endl;
}

void AccManager::checkAllCustomerBalance() const
{
	cout << endl << "WELCOME TO MY BANK !!" << endl << endl;
	cout << "< CHECK ALL CUSTOMER'S BALANCE >" << endl;
	cout << "--------------------------------" << endl;
	for(int i = 0; i < index; i++)
	{
		cout << ". ACCOUNT   : " << arrAccount[i]->getAccountId()<< endl; 
		cout << ". CUSTOMER  : " << arrAccount[i]->getCustomerName() << endl;
		cout << ". BALANCE   : " << arrAccount[i]->getBalance() << endl;
		if(arrAccount[i]->getDonation() > 0)
			cout << ". DONATION  : " << arrAccount[i]->getDonation() << endl;
		cout << "--------------------------------" << endl;
	}
}

////////////////////////// Account.cpp ////////////////////////////
#include "Account.h"

// Account Class - definition
Account::Account(int _accountId, char *_customerName, double _balance)
{
	customerName = new char[strlen(_customerName) + 1];
	strcpy(customerName, _customerName);
	accountId = _accountId;
	balance = _balance;
}
// Copy Constructor
Account::Account(const Account& a)
{
	customerName = new char[strlen(a.customerName) + 1];
	accountId = a.accountId;
	balance = a.balance;
}
Account::~Account()
{
	if(customerName != NULL)
	{
		delete []customerName;
		customerName = NULL;
	}
}
void Account::addBalance(double _money)
{
	balance += _money;
}
void Account::minusBalance(double _money)
{
	balance -= _money;
}
int Account::getAccountId() const
{
	return accountId;
}
const char* Account::getCustomerName() const
{
	return customerName;
}
double Account::getBalance() const
{
	return balance;
}
double Account::getDonation() const
{
	return 0;
}

////////////////////////// CreditAccount.cpp ////////////////////////////
#include "CreditAccount.h"

// CreditAccount Class definition
void CreditAccount::addBalance(double _money)
{
	double amountMoney;
	double interest;
	
	interest = _money * 0.01;
	amountMoney = _money + interest;

	balance += amountMoney;	
	
	cout << ". YOUR DEPOSIT  : " << _money << endl;
	cout << ". YOUR INTEREST : " << interest << endl;
}

////////////////////////// DonationAccount.cpp ////////////////////////////
#include "DonationAccount.h"

// DonationAccount Class definition
DonationAccount::DonationAccount(int _accountId, char *_customerName, double _balance, double _donation)
:Account(_accountId, _customerName, _balance)
{
	amountDonation = _donation;
};
void DonationAccount::addDonation(double _donation)
{
	amountDonation += _donation;
}
void DonationAccount::addBalance(double _money)
{
	double amountMoney;
	double donation;

	donation = _money * 0.01;
	addDonation(donation);
	amountMoney = _money - donation;
	
	balance += amountMoney;
	
	cout << ". YOUR DEPOSIT  : " << _money << endl;
	cout << ". YOUR DONATION : " << donation << endl;

	
}
double DonationAccount::getDonation() const
{
	return amountDonation;
}
