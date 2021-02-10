#include <iostream>
#include <iomanip>


using namespace std;

int main()
{
	// Declare variables for input storage
	float initialInv, monthDeposit, AnnualInt, months, years;

	// Declare variables for year end total amount, interest, and year end interest
	float totalAm, intAmt, yearTotInt;

	// User Display
	cout << "******************************\n";
	cout << "**********Data Input**********\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Interest: \n";
	cout << "Number of Years: \n";

	// Wait for user input
	system("PAUSE");

	// Get user input
	cout << "******************************\n";
	cout << "**********Data Input**********\n";
	cout << "Initial Investment Amount: \n";
	cin >> initialInv;
	cout << "Monthly Deposit: \n";
	cin >> monthDeposit;
	cout << "Annual Interest: \n";
	cin >> AnnualInt;
	cout << "Number of Years: \n";
	cin >> years;
	months = years * 12;

	// wait for user input
	system("PAUSE");

	// set total amount to initial investment to be updated
	totalAm = initialInv;

	// Display year data without monthly deposits
	cout << "\n Balance and Interest Without Additional Monthly Deposits\n";
	cout << "===============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "---------------------------------------------------------------\n";

	for (int i = 0; i < years; i++){

		// calculate yearly interest
		intAmt = (totalAm) * ((AnnualInt / 100));


		// calculate year end total
		totalAm = totalAm + intAmt;

		// print results to table with two decimal places
		cout << (i+1) << "\t\t" << fixed << setprecision(2) << totalAm << "\t\t\t" << intAmt << "\n";

	}

	// set total amount to initial investment to be updated
	totalAm = initialInv;

	// Display year data with monthly deposits
	cout << "\n\nBalance and Interests With Additional Monthly Deposits\n";
	cout << "===============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interests\n";
	cout << "---------------------------------------------------------------\n";

	for (int i = 0; i < years; i++){

		// set yearly interest to zero at the start of the year
		yearTotInt = 0;

		for (int j = 0; j < 12; j++){
			// calculate monthly interest
			intAmt = (totalAm + monthDeposit) * ((AnnualInt / 100) / 12);

			// calculate month end interest
			yearTotInt = yearTotInt + intAmt;

			// calculate month end total
			totalAm = totalAm + monthDeposit + intAmt;
		}

		// print results to table with two decimal places
		cout << (i+1) << "\t\t" << fixed << setprecision(2) << totalAm << "\t\t\t" << yearTotInt << "\n";
	}

	return 0;
}

