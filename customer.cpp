/* Jeremy Roberts
 * Papadakis
 * CISC2000 - Spring 2017
 *
 * This implements the Customer class
 */

#include "customer.h"

//default constructer
Customer::Customer(const string &fname, const string &lname, const string &ad, const string &ct, const string &st, const string &z){

	setFirstName(fname);
	setLastName(lname);
	setAddress(ad);
	setCity(ct);
	setState(st);
	setZip(z);
}

//input method
void Customer::input(){
	string fname, lname, ad, ct, st, z;

	cout << "First Name: ";
	cin >> fname;
	setFirstName(fname);

	cout << "Last Name: ";
	cin >> lname;
	setLastName(lname);
	cin.ignore(100, '\n');

	cout << "Address: ";
	getline(cin, ad);
	setAddress(ad);
	
	cout << "City: ";
	getline(cin, ct);
	setCity(ct);

	cout << "State: ";
	cin >> st;
	setState(st);

	cout << "Zip Code: ";
	cin >> z;
	setZip(z);
}

//copy constructor
const Customer& Customer::operator=(const Customer &c){
	setFirstName(c.getFirstName());
	setLastName(c.getLastName());
	setAddress(c.getAddress());
	setCity(c.getCity());
	setState(c.getState());
	setZip(c.getZip());
};

//display method
void Customer::print() const{
	cout << setprecision(2) << fixed;
	cout << "Name: " << getFirstName() << " " << getLastName() << endl;
/*	cout << "Address: " << getAddress() << endl;
	cout << "City: " << getCity() << endl;
	cout << "State: " << getState() << endl;
	cout << "Zip Code: " << getZip() << endl << endl;*/
}

//mutator methods for data members of Customer
void Customer::setFirstName(const string &fname){
	firstName = fname;
}

void Customer::setLastName(const string &lname){
	lastName = lname;
}

void Customer::setAddress(const string &ad){
	address = ad;
}

void Customer::setCity(const string &ct){
	city = ct;
}

void Customer::setState(const string &st){
	state = st;
}

void Customer::setZip(const string &z){
	zip = z;
}

//accessor methods for data members of Customer
string Customer::getFirstName() const{
	return(firstName);
}

string Customer::getLastName() const{
	return(lastName);
}

string Customer::getAddress() const{
	return(address);
}

string Customer::getCity() const{
	return(city);
}

string Customer::getState() const{
	return(state);
}

string Customer::getZip() const{
	return(zip);
}

/*
main(){
	Customer c;
	c.input();
	c.print();
	Customer d;
	d = c;
	d.print();
}*/
