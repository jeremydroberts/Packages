/* Jeremy Roberts
 * Papadakis
 * CISC2000 - Spring 2017
 * 
 * This implements base Package Class
 * NOTE: must be compiled with customer.cpp
 *
 */

#include "package.h"

//default constructor
Package::Package(){
	
	setWeight(0.0);
	setUnitCost(0.0);
	calculateCost();
}

//constructor with values for weight and unit cost
Package::Package(const Customer &s, const Customer &r, double w, double cost) : Package() {
	
	setWeight(w);
	setUnitCost(cost);
	calculateCost();

	sender.setFirstName(s.getFirstName());
	sender.setLastName(s.getLastName());
	sender.setAddress(s.getAddress());
	sender.setCity(s.getCity());
	sender.setState(s.getState());
	sender.setZip(s.getZip());

	recipient.setFirstName(r.getFirstName());
	recipient.setLastName(r.getLastName());
	recipient.setAddress(r.getAddress());
	recipient.setCity(r.getCity());
	recipient.setState(r.getState());
	recipient.setZip(r.getZip());
}

//accessor methods
double Package::getWeight() const {
	return(weight);
}

double Package::getUnitCost() const {
	return(unitCost);
}

double Package::getShippingCost() const {
	return(shippingCost);
}

Customer Package::getSender() const{
	return(sender);
}

Customer Package::getRecipient() const{
	return(recipient);
}

//runs input methods for each Customer object
void Package::inputSender(){
	sender.input();
}

void Package::inputRecipient(){
	recipient.input();
}

//mutator methods
//valids input, updates variable value
//then runs calculateCost to update shippingCost
bool Package::setWeight(const double &w) {
	
	bool valid = false;

	if(w >= 0.0){
		weight = w;
		calculateCost();
		valid = true;
	}
	
	return(valid);
}

//validates information, updates variable value
//then runs calculateCost to update shipppingCost
bool Package::setUnitCost(const double &u) {

	bool valid = false;

	if(u >= 0.0){
		unitCost = u;
		calculateCost();
		valid = true;
	}

	return(valid);
}

//method to calculate shipping cost using weight and unit cost
double Package::calculateCost() {
	
	shippingCost = getWeight()*getUnitCost();
	return(shippingCost);
}

//uses Customer print method for each object
//other variables are printed in derived class method
void Package::print() const{
	cout << "\nSender Information:\n";
	sender.print();
	cout << "Recipient Information:\n";
	recipient.print();
}

/*
main(){

	Customer c1("Jeremy", "Roberts", "7664 S. Joplin", "Tulsa", "OK", "74136");
	Customer c2("David", "S. Pumpkins", "69 Halloweentown Road", "New York", "NY", "10458");

	Package p(c1, c2, 5.3, 4.234);

	p.print();
	cout << "Weight: " << p.getWeight() << "\nUnit Cost: " << p.getUnitCost()
		<< "\nShipping Cost: " << p.getShippingCost() << endl;

}*/
