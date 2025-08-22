#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>         // March 2022
#include <string>
#include <vector>
using namespace std;

/**
 * Customer class for managing customer data
 * - stores customer information including ID, name, type, and purchase history
 * - provides validation for customer data
 * - supports file I/O operations
 */

class Customer 
{
private:
	int customerId;
	string title;
	string name;
	string type;
	int purchasesCount;
	vector<int> purchaseNumbers;

public:
	// Constructors
	Customer(); // Default constructor
	Customer(int id, const string& t, const string& n, 
			 const string& typ, int count, const vector<int>& numbers);
	
	// Copy constructor
	Customer(const Customer& other);
	
	// Destructor
	~Customer();
	
	// Assignment operator
	Customer& operator=(const Customer& other);
	
	// Getters
	int getCustomerId() const { return customerId; }
	string getTitle() const { return title; }
	string getName() const { return name; }
	string getType() const { return type; }
	int getPurchasesCount() const { return purchasesCount; }
	vector<int> getPurchaseNumbers() const { return purchaseNumbers; }
	
	// Setters with validation
	void setCustomerId(int id);
	void setTitle(const string& t);
	void setName(const string& n);
	void setType(const string& typ);
	void setPurchasesCount(int count);
	void setPurchaseNumbers(const vector<int>& numbers);
	
	// Overloaded operators
	bool operator==(const Customer& other) const;
	bool operator!=(const Customer& other) const;
	
	// Friend functions for stream operators
	friend ostream& operator<<(ostream& os, const Customer& customer);
	friend istream& operator>>(istream& is, Customer& customer);
	
	// Utility methods
	void addPurchaseNumber(int number);
	bool hasPurchaseNumber(int number) const;
	string toString() const;
};

#endif // CUSTOMER_H
