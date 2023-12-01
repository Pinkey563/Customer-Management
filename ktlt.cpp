#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>		// for std::setw(n), std::setfill(ch), std::left, std::right
#include <string>		// for stoi
#include <fstream>		// open, write to file
#include <sstream>
using namespace std;

class Customer {
	public:
		int ID;
		string name;
		string tel;
		string dob;
		long int pts;
		string rank;
		double totalbuy;
};

void create_customer(Customer& customer) {
	cout << "----------Customer Information----------" << endl;
	cout << "ID: ";
	cin >> customer.ID;
	fflush(stdin);
	cout << "Name: ";
	getline(cin,customer.name);
	cout << "Telephone number: ";
	getline(cin,customer.tel);
	cout << "Date of birth: ";
	getline(cin,customer.dob);
	fflush(stdin);
}

void show_customer(const Customer& customer) {
	cout << setfill(' ');
	cout << setw(15) << left << customer.ID;
	cout << setw(30) << left << customer.name;
	cout << setw(20) << left << customer.tel;
	cout << setw(20) << left << customer.dob;
	cout << setw(15) << left << customer.pts;
	cout << setw(5) << left << customer.rank;
	cout << setw(15) << left << customer.totalbuy;
}

void list_customers(const vector<Customer>& customers) {
    for (const auto& customer : customers) {
        show_customer(customer);
    }
}

void add_customer(vector<Customer>& customers) {
	Customer newCustomer;
	create_customer(newCustomer);
	customers.push_back(newCustomer);	
}

void delete_customer(vector<Customer>& customers, int customerID) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].ID == customerID) {
            customers.erase(customers.begin() + i);
            cout << "Customer with ID: " << customerID << " has been deleted." << endl;
            return;
        }
    }
    cout << "Customer with ID " << customerID << " not found." << endl;
}

void change_info_customer(vector<Customer>& customers, int customerID) {
	for (auto& customer : customers) {
        if (customer.ID == customerID) {
            cout << "----------Change Customer Information---------- "<< endl;
            cout << "Changing informaton for customer with ID: " << customerID;
            int choice;
            cout<<"What do you want to change? (1: Name, 2:Telephone number, 3: Date of birth)" << endl;
            cin << choice;
            if(choice == 1){
            	cout << "New Name: ";
            getline(cin, cus.name);
			}
            if(choice == 2){
            	cout << "New Telephone number: ";
            getline(cin, cus.tel);
			}
            if(choice == 3){
                        cout << "New Date of birth: ";
            getline(cin, cus.dob);	
			}
            cout << "Information for customer with ID " << customerID << " has been changed." << endl;
            return;
        }
    }

    cout << "Customer with ID " << customerID << " does not exist." << endl;
}


