/* Jeremy Roberts
 * Papadakis
 * CISC2000 - Spring 2017
 *
 * This contains the definition for OvernightPackage class,
 * derived from base Package class
 */

#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "package.h"

class OvernightPackage : public Package {

public:
	OvernightPackage();
	OvernightPackage(const Customer &, const Customer &, double = 0.0, double = 0.0);
	~OvernightPackage();

	double getOvernightCost() const;
	double getOvernightFee() const;
	static int getNumOvernight();
	static double getOvernightRevenue();

	void input();
	bool setWeight(double);
	bool setUnitCost(double);

	void print() const;
	double calculateCost();

private:
	const double overnightFee = 15.00;
	double overnightCost;
	static int numOvernight;
	static double overnightRevenue;
};
#endif
