#include "Customer.h"
#include <algorithm>
#include <sstream>

/**
 * Default constructor - initializes customer with default values
 */
Customer::Customer() : customerId(0), title(""), name(""), type(""), purchasesCount(0) 
{
}

/**
 * Full constructor with validation
 * @param id customer ID number
 * @param t customer title
 * @param n customer name
 * @param typ customer type (New or Regular)
 * @param count number of purchases
 * @param numbers vector of purchase numbers
 */
Customer::Customer(int id, const string& t, const string& n, 
				   const string& typ, int count, const vector<int>& numbers)
	: customerId(id), title(t), name(n), type(typ), purchasesCount(count), purchaseNumbers(numbers) 
{
	// Validation
	if (id <= 0) customerId = 1;
	if (count < 0) purchasesCount = 0;
	if (typ != "New" && typ != "Regular") type = "New";
}

/**
 * Copy constructor
 * @param other customer object to copy from
 */
Customer::Customer(const Customer& other) 
	: customerId(other.customerId), title(other.title), name(other.name), 
	  type(other.type), purchasesCount(other.purchasesCount), purchaseNumbers(other.purchaseNumbers) 
{
}

/**
 * Destructor - vector will automatically clean up
 */
Customer::~Customer() 
{
}

/**
 * Assignment operator
 * @param other customer object to assign from
 * @return reference to this customer object
 */
Customer& Customer::operator=(const Customer& other) 
{
	if (this != &other) 
	{
		customerId = other.customerId;
		title = other.title;
		name = other.name;
		type = other.type;
		purchasesCount = other.purchasesCount;
		purchaseNumbers = other.purchaseNumbers;
	}
	return *this;
}

/**
 * Set customer ID with validation
 * @param id customer ID (must be positive)
 */
void Customer::setCustomerId(int id) 
{
	if (id > 0) 
	{
		customerId = id;
	}
}

/**
 * Set customer title
 * @param t customer title
 */
void Customer::setTitle(const string& t) 
{
	if (!t.empty()) 
	{
		title = t;
	}
}

/**
 * Set customer name
 * @param n customer name
 */
void Customer::setName(const string& n) 
{
	if (!n.empty()) 
	{
		name = n;
	}
}

/**
 * Set customer type with validation
 * @param typ customer type (must be "New" or "Regular")
 */
void Customer::setType(const string& typ) 
{
	if (typ == "New" || typ == "Regular") 
	{
		type = typ;
	}
}

/**
 * Set purchases count with validation
 * @param count number of purchases (must be non-negative)
 */
void Customer::setPurchasesCount(int count) 
{
	if (count >= 0) 
	{
		purchasesCount = count;
	}
}

/**
 * Set purchase numbers vector
 * @param numbers vector of purchase numbers
 */
void Customer::setPurchaseNumbers(const vector<int>& numbers) 
{
	purchaseNumbers = numbers;
	purchasesCount = numbers.size();
}

/**
 * Equality operator - compares customer IDs
 * @param other customer to compare with
 * @return true if customer IDs are equal
 */
bool Customer::operator==(const Customer& other) const 
{
	return customerId == other.customerId;
}

/**
 * Inequality operator
 * @param other customer to compare with
 * @return true if customer IDs are not equal
 */
bool Customer::operator!=(const Customer& other) const 
{
	return !(*this == other);
}

/**
 * Output stream operator for writing customer to file
 * @param os output stream
 * @param customer customer object to write
 * @return output stream
 */
ostream& operator<<(ostream& os, const Customer& customer) 
{
	os << customer.customerId << ";" << customer.title << ";" << customer.name << ";"
	   << customer.type << ";" << customer.purchasesCount << ";";
	
	for (int i = 0; i < customer.purchaseNumbers.size(); ++i) 
	{
		os << customer.purchaseNumbers[i];
		if (i < customer.purchaseNumbers.size() - 1) 
		{
			os << ";";
		}
	}
	return os;
}

/**
 * Input stream operator for reading customer from file
 * @param is input stream
 * @param customer customer object to read into
 * @return input stream
 */
istream& operator>>(istream& is, Customer& customer) 
{
	string line;
	if (getline(is, line)) 
	{
		stringstream ss(line);
		string token;
		vector<string> tokens;
		
		while (getline(ss, token, ';')) 
		{
			tokens.push_back(token);
		}
		
		if (tokens.size() >= 5) 
		{
			customer.customerId = stoi(tokens[0]);
			customer.title = tokens[1];
			customer.name = tokens[2];
			customer.type = tokens[3];
			customer.purchasesCount = stoi(tokens[4]);
			
			customer.purchaseNumbers.clear();
			for (int i = 5; i < tokens.size(); ++i) 
			{
				customer.purchaseNumbers.push_back(stoi(tokens[i]));
			}
		}
	}
	return is;
}

/**
 * Add a purchase number to the customer's purchase history
 * @param number purchase number to add
 */
void Customer::addPurchaseNumber(int number) 
{
	if (number > 0) 
	{
		purchaseNumbers.push_back(number);
		purchasesCount = purchaseNumbers.size();
	}
}

/**
 * Check if customer has a specific purchase number
 * @param number purchase number to search for
 * @return true if purchase number exists
 */
bool Customer::hasPurchaseNumber(int number) const 
{
	return find(purchaseNumbers.begin(), purchaseNumbers.end(), number) != purchaseNumbers.end();
}

/**
 * Convert customer to string representation
 * @return string representation of customer
 */
string Customer::toString() const 
{
	stringstream ss;
	ss << "ID: " << customerId << ", Name: " << title << " " << name 
	   << ", Type: " << type << ", Purchases: " << purchasesCount;
	return ss.str();
}
