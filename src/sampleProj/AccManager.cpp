#include "AccManager.h"
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