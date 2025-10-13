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