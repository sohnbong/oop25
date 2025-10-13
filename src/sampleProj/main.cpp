/**********************************************************/
/* NAME   : OOP Project                                   */ 
/* DATE   : 03/04/2008                                    */
/* AUTHOR : JAY                                           */ 
/**********************************************************/
/* VERSION : Project 4.1 - 28/04/2008 ~ 28/04/2008        */
/**********************************************************/

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