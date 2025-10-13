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