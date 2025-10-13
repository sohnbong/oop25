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