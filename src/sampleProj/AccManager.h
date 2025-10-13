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