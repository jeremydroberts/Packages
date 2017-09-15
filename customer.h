/*Jeremy Roberts
 * Papadakis
 * CISC2000 - Spring 2017
 *
 * This contains the definition of the Customer class
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Customer {

public: 
	Customer(const string & = " ", const string & = " ", const string & = " ", const string & = " ", const string & = " ", const string & = " ");

	const Customer &operator=(const Customer &);

        void input();
	void print() const;

        string getFirstName() const;
        string getLastName() const;
        string getAddress() const;
        string getCity() const;
        string getState() const;
        string getZip() const;

        void setFirstName(const string &);
        void setLastName(const string &);
        void setAddress(const string &);
        void setCity(const string &);
        void setState(const string &);
        void setZip(const string &);
        
private:
        string firstName;
        string lastName;
        string address;
        string city;
        string state;
        string zip;
        
};     

#endif
