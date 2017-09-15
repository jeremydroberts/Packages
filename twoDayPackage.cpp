/* Jeremy Roberts
 * Papadakis
 * CISC2000 - Spring 2017
 * This contains the implementation of the TwoDayPackage class
 * derived from base Package class
 * NOTE: Must be compiled with package.cpp and customer.cpp
 */

#include "twoDayPackage.h"

//initialize static counter variables
int TwoDayPackage::numTwoDay = 0;
double TwoDayPackage::twoDayRevenue = 0;

//default constructor
TwoDayPackage::TwoDayPackage() : Package() {
	calculateCost();
	numTwoDay++;
}

//custom constructor
TwoDayPackage::TwoDayPackage(const Customer &s, const Customer &r, double w, double u) : Package(s, r, w, u) {
	calculateCost();
	numTwoDay++;
}

//copy constructor
TwoDayPackage& TwoDayPackage::operator=(const TwoDayPackage &t){
	setUnitCost(t.getUnitCost());
	setWeight(t.getWeight());
	Package::sender = t.Package::getSender();
	Package::recipient = t.Package::getRecipient();
}

//destructor, decrements numTwoDay counter and total revenue counter
TwoDayPackage::~TwoDayPackage(){
	numTwoDay--;
	twoDayRevenue - getTwoDayCost();
}


//overwrites base class function, adding two day shipping flat fee
double TwoDayPackage::calculateCost(){
	twoDayRevenue-=twoDayCost; //subtracts previous value from total
	twoDayCost = (weight*unitCost)+getTwoDayFee(); //recalculates, adding flat fee
	twoDayRevenue+=twoDayCost; //adds new value to total
	return(twoDayCost); //returns twoDayCost
}

//accessor methods
double TwoDayPackage::getTwoDayCost() const{
	return(twoDayCost);
}

double TwoDayPackage::getTwoDayFee() const{
	return(twoDayFee);
}

int TwoDayPackage::getNumTwoDay(){
	return(numTwoDay);
}

double TwoDayPackage::getTwoDayRevenue(){
	return(twoDayRevenue);
}

//allows for input of customer and package
void TwoDayPackage::input(){
	
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

//mutator methods
//validates input, updates variable value,
//then runs calculateCost() to update twoDayCost value
bool TwoDayPackage::setWeight(double w){
	bool valid = false;
        if(w >= 0.0){
                weight = w;
                calculateCost();
                valid = true;
        }
        return(valid);	
}

//same as above
bool TwoDayPackage::setUnitCost(double u){
	bool valid = false;
	if(u >= 0.0){
                unitCost = u;
                calculateCost();
                valid = true;
        }
        return(valid);
}

//display method
void TwoDayPackage::print() const {

	cout << "\nTwo-Day Shipping Summary:\n";
	Package::print();
	cout << "Package Weight: " << Package::getWeight() << "oz."
		<< "\nShipping Cost per Ounce: $" << Package::getUnitCost()
		<< "\nTwo Day Shipping Fee: $" << getTwoDayFee()
		<< "\nTotal Shipping Cost: $" << getTwoDayCost() << endl;

}

/*
main(){

 	Customer c1("Jeremy", "Roberts", "7664 S. Joplin", "Tulsa", "OK", "74136");
        Customer c2("David", "S. Pumpkins", "69 Halloweentown Road", "New York", "NY", "10458");

        TwoDayPackage p(c1, c2, 5, 5);
        p.print();
        cout << p.getNumTwoDay() << endl;
        cout << p.getTwoDayRevenue() << endl;

        TwoDayPackage p2(c2, c1, 10, 10);
        p2.print();
        cout << p2.getNumTwoDay() << endl;
        cout << p2.getTwoDayRevenue() << endl;

        p.setUnitCost(1);
        p.print();
        cout << p.getTwoDayRevenue() << endl;

	p = p2;
	p.print();	
}*/
