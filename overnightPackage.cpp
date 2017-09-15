/* Jeremy Roberts
 * Papadakis
 * CISC2000 - Spring 2017
 *
 * This contains the implementation of the OvernightPackage class,
 * derived from base Package class
 * 
 * NOTE: Must be compiled with customer.cpp and package.cpp
 */

#include "overnightPackage.h"

//initialize static counter variables
int OvernightPackage::numOvernight = 0;
double OvernightPackage::overnightRevenue = 0;

//default constructor
OvernightPackage::OvernightPackage():Package() {
	calculateCost();
	numOvernight++;
}

//custom constructor
OvernightPackage::OvernightPackage(const Customer &s, const Customer &r, double w, double u):Package(s,r,w,u){
	calculateCost();
	numOvernight++;
}

//destructor, decrements counter and total revenue
OvernightPackage::~OvernightPackage(){
	numOvernight--;
	overnightRevenue - getOvernightCost();
}

//allows input of customer and package details
void OvernightPackage::input(){

 	cout << "Input Sender Information:\n";
        Package::inputSender();

        cout << "Input Recipient Information:\n";
        Package::inputRecipient();

        double weight;
        cout << "Package Weight (oz): ";
        cin >> weight;
        setWeight(weight);

        double cost;
        cout << "Cost per Ounce ($): ";
        cin >> cost;
        setUnitCost(cost);
}

//overwrites base class function, adds overnight flat fee
double OvernightPackage::calculateCost(){
	overnightRevenue -= overnightCost; //subtracts old value from total revenue
	overnightCost = (weight*unitCost)+getOvernightFee(); //recalculates, adding flat fee
	overnightRevenue+=overnightCost; //adds new value to total revenue
}

//accessor methods
double OvernightPackage::getOvernightCost() const{
	return(overnightCost);
}

double OvernightPackage::getOvernightFee() const{
	return(overnightFee);
}

int OvernightPackage::getNumOvernight(){
	return(numOvernight);
}

double OvernightPackage::getOvernightRevenue(){
	return(overnightRevenue);
}

//mutator methods
//validates input, updates variable value,
//runs calculateCost to update overnightCost
bool OvernightPackage::setWeight(double w){
	bool valid = false;
        if(w >= 0.0){
                weight = w;
                calculateCost();
                valid = true;
        }
        return(valid);
}

//same as above
bool OvernightPackage::setUnitCost(double u){
	bool valid = false;
        if(u >= 0.0){
                unitCost = u;
                calculateCost();
                valid = true;
        }
        return(valid);
}

//display method
void OvernightPackage::print() const{
	cout << "\nOvernight Shipping Summary:\n";
        Package::print();
	cout << "Package Weight: " << Package::getWeight() << "oz."
                << "\nShipping Cost per Ounce: $" << Package::getUnitCost()
                << "\nOvernight Shipping Fee: $" << getOvernightFee()
                << "\nTotal Shipping Cost: $" << getOvernightCost() << endl;
}

/*
main(){
        Customer c1("Jeremy", "Roberts", "7664 S. Joplin", "Tulsa", "OK", "74136");
        Customer c2("David", "S. Pumpkins", "69 Halloweentown Road", "New York", "NY", "10458");

        OvernightPackage p(c1, c2, 5, 5);
	p.print();
	cout << p.getNumOvernight() << endl;
	cout << p.getOvernightRevenue() << endl;

	OvernightPackage p2(c1, c2, 10, 10);
	p2.print();
	cout << p2.getNumOvernight() << endl;
	cout << p2.getOvernightRevenue() << endl;

	p.setUnitCost(10);
	p.print();
	cout << p.getOvernightRevenue() << endl;
}*/
