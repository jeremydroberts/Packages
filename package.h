/* Jeremy Roberts
 * Papadakis
 * CISC2000 - Spring 2017
 *
 * This contains the definition of the base Package class
 */

#ifndef PACKAGE_H
#define PACKAGE_H

#include <iostream>
#include "customer.h"
using namespace std;

class Package {

public:
	Package();
	Package(const Customer &, const Customer &, double = 0.0, double = 0.0);
	
	double getWeight() const;
	double getUnitCost() const;
	double getShippingCost() const;
	
	Customer getSender() const;
	Customer getRecipient() const;


	void inputSender();
	void inputRecipient();

	bool setWeight(const double &);
	bool setUnitCost(const double &);
	double calculateCost();	

	void print() const;	

protected:
	Customer sender;
	Customer recipient;
//private:
	double weight;
	double unitCost;
	double shippingCost;
};

#endif
