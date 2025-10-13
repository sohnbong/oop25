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