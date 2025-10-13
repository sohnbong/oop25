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