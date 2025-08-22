#include <iostream>         // March 2022
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include "Customer.h"
using namespace std;

/**
 * Customer Management System
 * - manages customer data with file I/O
 * - provides console-based user interface
 * - supports all required operations from Part A
 */

// function prototypes
void displayMenu();
void addCustomer(vector<Customer>& customers);
void displayAllCustomers(const vector<Customer>& customers);
void displayCustomersByType(const vector<Customer>& customers);
void findCustomer(const vector<Customer>& customers);
void findCustomerByPurchase(const vector<Customer>& customers);
void loadCustomers(vector<Customer>& customers);
void saveCustomers(const vector<Customer>& customers);
void sortCustomersByName(vector<Customer>& customers);
const Customer* findCustomerById(const vector<Customer>& customers, int id);

int main()
{
	vector<Customer> customers;
	
	cout << "=== Customer Management System ===" << endl;
	cout << "Loading existing customer data..." << endl;
	
	loadCustomers(customers);
	
	int choice;
	do 
	{
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch (choice) 
		{
			case 1:
				addCustomer(customers);
				break;
			case 2:
				displayAllCustomers(customers);
				break;
			case 3:
				findCustomer(customers);
				break;
			case 4:
				findCustomerByPurchase(customers);
				break;
			case 5:
				cout << "Saving customer data..." << endl;
				saveCustomers(customers);
				cout << "Data saved successfully!" << endl;
				break;
			case 6:
				cout << "Exiting program..." << endl;
				saveCustomers(customers);
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 6);
	
	return 0;
}

/**
 * Display the main menu options
 */
void displayMenu()
{
	cout << "\n=== Customer Management Menu ===" << endl;
	cout << "1. Add Customer" << endl;
	cout << "2. Display All Customers" << endl;
	cout << "3. Find Customer by ID" << endl;
	cout << "4. Find Customer by Purchase Number" << endl;
	cout << "5. Save Data" << endl;
	cout << "6. Exit" << endl;
	cout << "================================" << endl;
}

/**
 * Add a new customer to the system
 * @param customers vector of customers to add to
 */
void addCustomer(vector<Customer>& customers)
{
	cout << "\n=== Add New Customer ===" << endl;
	
	int id;
	string title, name, type;
	int purchasesCount;
	vector<int> purchaseNumbers;
	
	cout << "Enter Customer ID: ";
	cin >> id;
	
	cout << "Enter Title (Mr/Mrs/Ms/Dr): ";
	cin.ignore();
	getline(cin, title);
	
	cout << "Enter Name: ";
	getline(cin, name);
	
	cout << "Enter Type (New/Regular): ";
	cin >> type;
	
	cout << "Enter number of purchases: ";
	cin >> purchasesCount;
	
	if (purchasesCount > 0) 
	{
		cout << "Enter purchase numbers (one per line):" << endl;
		for (int i = 0; i < purchasesCount; i++) 
		{
			int purchaseNum;
			cout << "Purchase " << (i + 1) << ": ";
			cin >> purchaseNum;
			purchaseNumbers.push_back(purchaseNum);
		}
	}
	
	Customer newCustomer(id, title, name, type, purchasesCount, purchaseNumbers);
	customers.push_back(newCustomer);
	
	cout << "Customer added successfully!" << endl;
}

/**
 * Display all customers in the system
 * @param customers vector of customers to display
 */
void displayAllCustomers(const vector<Customer>& customers)
{
	if (customers.empty()) 
	{
		cout << "No customers found." << endl;
		return;
	}
	
	cout << "\n=== All Customers ===" << endl;
	cout << "Display by: 1) Name order, 2) Type filter" << endl;
	int choice;
	cin >> choice;
	
	vector<Customer> sortedCustomers = customers;
	
	if (choice == 1) 
	{
		sortCustomersByName(sortedCustomers);
		for (int i = 0; i < sortedCustomers.size(); i++) 
		{
			cout << (i + 1) << ". " << sortedCustomers[i].toString() << endl;
		}
	} 
	else if (choice == 2) 
	{
		displayCustomersByType(customers);
	} 
	else 
	{
		cout << "Invalid choice." << endl;
	}
}

/**
 * Display customers filtered by type
 * @param customers vector of customers to filter
 */
void displayCustomersByType(const vector<Customer>& customers)
{
	string type;
	cout << "Enter type to filter (New/Regular): ";
	cin >> type;
	
	cout << "\n=== Customers of type: " << type << " ===" << endl;
	int count = 0;
	
	for (int i = 0; i < customers.size(); i++) 
	{
		if (customers[i].getType() == type) 
		{
			cout << (count + 1) << ". " << customers[i].toString() << endl;
			count++;
		}
	}
	
	if (count == 0) 
	{
		cout << "No customers found with type: " << type << endl;
	}
}

/**
 * Find a customer by ID
 * @param customers vector of customers to search
 */
void findCustomer(const vector<Customer>& customers)
{
	int id;
	cout << "Enter Customer ID to find: ";
	cin >> id;
	
	const Customer* foundCustomer = findCustomerById(customers, id);
	
	if (foundCustomer != nullptr) 
	{
		cout << "Customer found: " << foundCustomer->toString() << endl;
		cout << "Purchase numbers: ";
		vector<int> purchases = foundCustomer->getPurchaseNumbers();
		for (int i = 0; i < purchases.size(); i++) 
		{
			cout << purchases[i];
			if (i < purchases.size() - 1) cout << ", ";
		}
		cout << endl;
	} 
	else 
	{
		cout << "Customer with ID " << id << " not found." << endl;
	}
}

/**
 * Find a customer by purchase number
 * @param customers vector of customers to search
 */
void findCustomerByPurchase(const vector<Customer>& customers)
{
	int purchaseNum;
	cout << "Enter Purchase Number to find: ";
	cin >> purchaseNum;
	
	bool found = false;
	for (int i = 0; i < customers.size(); i++) 
	{
		if (customers[i].hasPurchaseNumber(purchaseNum)) 
		{
			cout << "Customer found: " << customers[i].toString() << endl;
			found = true;
			break;
		}
	}
	
	if (!found) 
	{
		cout << "No customer found with purchase number " << purchaseNum << endl;
	}
}

/**
 * Load customers from file
 * @param customers vector to load customers into
 */
void loadCustomers(vector<Customer>& customers)
{
	ifstream file("data/customers.txt");
	if (file.is_open()) 
	{
		Customer customer;
		while (file >> customer) 
		{
			customers.push_back(customer);
		}
		file.close();
		cout << "Loaded " << customers.size() << " customers from file." << endl;
	} 
	else 
	{
		cout << "No existing customer file found. Starting with empty system." << endl;
	}
}

/**
 * Save customers to file
 * @param customers vector of customers to save
 */
void saveCustomers(const vector<Customer>& customers)
{
	ofstream file("data/customers.txt");
	if (file.is_open()) 
	{
		for (int i = 0; i < customers.size(); i++) 
		{
			file << customers[i] << endl;
		}
		file.close();
	} 
	else 
	{
		cout << "Error: Could not open file for writing." << endl;
	}
}

/**
 * Sort customers by name
 * @param customers vector of customers to sort
 */
void sortCustomersByName(vector<Customer>& customers)
{
	sort(customers.begin(), customers.end(), 
		 [](const Customer& a, const Customer& b) 
		 {
			 return a.getName() < b.getName();
		 });
}

/**
 * Find customer by ID and return pointer
 * @param customers vector of customers to search
 * @param id customer ID to find
 * @return pointer to customer if found, nullptr otherwise
 */
const Customer* findCustomerById(const vector<Customer>& customers, int id)
{
	for (int i = 0; i < customers.size(); i++) 
	{
		if (customers[i].getCustomerId() == id) 
		{
			return &customers[i];
		}
	}
	return nullptr;
}
