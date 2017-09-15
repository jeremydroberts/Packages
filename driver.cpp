/* Jeremy Roberts
 * Papadakis
 * CISC2000 - Spring 2017
 *
 * This driver program tests the TwoDayPackage and OvernightPackage classes
 * that are derived from the Package base class
 * and tests the calculateCost() function for each of them
 *
 * NOTE: This file must be compiled with twoDayPackage.cpp, overnightPackage.cpp,
 * package.cpp, and customer.cpp
 */

#include "twoDayPackage.h"
#include "overnightPackage.h"

main(){
	//sets output precision for double type variables at 2 decimal points
	cout << setprecision(2) << fixed;
	
	//variables used in main()
	bool moreCustomers = true;
	char cont;
	char shipType;
	bool validType = false;
	
	//limits total amount of each package
	const int MAX_CUST = 100;

	//create array of pointers to TwoDayPackage objects
	TwoDayPackage *TwoDayPackages[MAX_CUST];

	//create array of pointers to OvernightPackage objects
	OvernightPackage *OvernightPackages[MAX_CUST];
	
	//counters for loop
	int m = 0;
	int n = 0;
	
	do{
		do{
			cout << "What type of shipping do you want to use: [T]wo Day, or [O]vernight? ";
			cin >> shipType;

			//checks that user inputs a correct category of package
			//allows input of an object, then moves to next space in array
			if(shipType == 'T' || shipType == 't'){
				if(m > 99){
					cout << "You have reached maximum amount of Two-Day Packages.\n";
					validType = true;
				}
				else{
					TwoDayPackages[m] = new TwoDayPackage;
					TwoDayPackages[m]->input();
					m++;
					validType = true;
				}
			}
			
			//same as above
			else if(shipType == 'O' || shipType == 'o'){
				if(n>99){
					cout << "You have reached the maximum amount of Overnight Packages.\n";
					validType = true;
				}

				else{
					OvernightPackages[n] = new OvernightPackage;
					OvernightPackages[n]->input();
					n++;
					validType = true;
				}
			}
				
			//runs loop again until valid input is entered
			else{
				cout << "Invalid Input...\n";
				validType = false;
			}
		
		} while(!validType); //loop terminates when a valid input is entered
		
		cout << "Would You Like To Input Another Package: [Y]es or [N]o? ";
                cin >> cont;
                if(cont == 'N' || cont == 'n')
                        moreCustomers = false;

	}while(moreCustomers); //loop terminates when user does not want to input more packages

	//outputs summary of packages
	cout << "\nToday's Summary:\n";

	//outputs Two Day Packages
        if (TwoDayPackage::getNumTwoDay() > 0){
                cout << "\nTwo Day Packages:\n";
                //for loop to display twoDayPackages
                for(int i = 0; i < TwoDayPackage::getNumTwoDay(); i++){
                        cout << "\nPackage " << i+1 << ":\n";
                        TwoDayPackages[i]->print();
                }
        }
 
	//outputs Overnight Packages
        if(OvernightPackage::getNumOvernight > 0){
                cout << "\nOvernight Packages:\n";
                //for loop to display overnightPackages
                for(int i=0; i<OvernightPackage::getNumOvernight(); i++){
                        cout << "\nPackage " << i+1 << ":\n";
                        OvernightPackages[i]->print();
                }
        }

	//displays static counter variables for classes
        cout << "\nTotal Number of Two-Day Packages: " << TwoDayPackage::getNumTwoDay()
                << "\nTotal Revenue of Two-Day Packages: $" << TwoDayPackage::getTwoDayRevenue() << endl;
        cout << "\nTotal Number of Overnight Packages: " << OvernightPackage::getNumOvernight()
                << "\nTotal Revenue of Overnight Packages: $" << OvernightPackage::getOvernightRevenue() << endl << endl;
}
