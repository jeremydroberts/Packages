/* Jeremy Roberts
 * Papadakis
 * CISC2000 - Spring 2017
 *
 * This contains the definition of TwoDayPackage,
 * a derived class of Package
 */

#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package {

public:
	TwoDayPackage();
	TwoDayPackage(const Customer &, const Customer &, double = 0.0, double = 0.0);
	~TwoDayPackage();
	
	TwoDayPackage &operator=(const TwoDayPackage &);
	
	double getTwoDayCost() const;
	double getTwoDayFee() const;
	static int getNumTwoDay();
	static double getTwoDayRevenue();

	void input();
	bool setWeight(double);
	bool  setUnitCost(double);
	//void setSender(Customer);
	//void setRecipient(Customer);

	void print() const;
	double calculateCost();
	
private:
	const double twoDayFee = 8.00;
	double twoDayCost;
	static int numTwoDay;
	static double twoDayRevenue;
};
#endif
