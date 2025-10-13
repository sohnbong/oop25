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