#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>		// for std::setw(n), std::setfill(ch), std::left, std::right
#include <string>		// for stoi
#include <fstream>		// open, write to file
#include <sstream>
using namespace std;
// Tao class Customer chua thong tin khach hang
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
// Ham khoi tao khach hang moi
void create_customer(Customer& customer) {
	cout << "----------Customer Information----------" << endl;
	cout << "ID: ";
	cin >> customer.ID;
	cout << "Name: ";
	getline(cin,customer.name);
	cout << "Telephone number: ";
	getline(cin,customer.tel);
	cout << "Date of birth (dd/mm/yyyy): ";
	getline(cin,customer.dob);
	cin.ignore();
}
// Ham hien thi thong tin cua tung khach hang
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
// Ham tao ra 1 list hien thi thong tin khach hang
void list_customers(const vector<Customer>& customers) {
	for (const auto& customer : customers) {
		show_customer(customer);
	}
}
// Ham them khach hang moi
void add_customer(vector<Customer>& customers) {
	Customer newCustomer;
	create_customer(newCustomer);
	customers.push_back(newCustomer);
}
// Ham xoa khach hang
void delete_customer(vector<Customer>& customers) {
	cout << "Delete customers by [1]: ID, [2]: Name, [3]: Telephone number, [4]: Date of birth " << endl;
	int choice;
	if (choice == 1) {
		int customerID;
		cout << "Delete customer by ID: ";
		cin >> customerID;
		customers = customers.erase(remove(customers.begin(), customers.end(), customerID), customers.end());
		cout << "DONE !!!" <<endl;
	}
	else if (choice == 2) {
		string customername;
		cout << "Delete customer by name: ";
		getline(cin, customername);
		customers = customers.erase(remove(customers.begin(), customers.end(), customername), customers.end());
		cout << "DONE !!!" <<endl;
	}
	else if (choice == 3) {
		string custometel;
		cout << "Delete customer by telephone number: ";
		getline(cin, customertel);
		customers = customers.erase(remove(customers.begin(), customers.end(), customertel), customers.end());
		cout << "DONE !!!" <<endl;
	}
	else if (choice == 4) {
		string customerdob;
		cout << "Delete customer by date of birth: ";
		getline(cin, customerdob);
		customers = customers.erase(remove(customers.begin(), customers.end(), customerdob), customers.end());
		cout << "DONE !!!" <<endl;
	}
	else {
		cout << "Invalid choice " << endl;
	}
	return;
}
// Ham tim kiem khach hang theo ID
vector<Customer> search_ID(const vector<Customer>& customers) {
	vector<Customer> list;
	int customerID;
	cout << "Search for ID: ";
	cin >> customerID;
	for(const auto& customer : customers) {
		if (customer.ID == customerID) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is no customer with ID: " << customerID << endl;
		return customers;
	} else {
		cout << "There is 1 customer with ID: " << customerID << endl;
	}
	list_customers(list);
	return list;
}
// Ham tim kiem khach hang theo ten
vector<Customer> search_name(const vector<Customer>& customers) {
	vector<Customer> list;
	string customername;
	cout << "Search for name: ";
	getline (cin, customername);
	for (const auto& customer : customers) {
		if (customer.name == customername) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is no customer with name: " << customername << endl;
		return customers;
	} else if (list.size() == 1) {
		cout << "There is 1 customer with name: " << customername << endl;
	} else {
		cout << "There are " << list.size() << " customers with name: " << customername << endl;
	}
	list_customers(list);
	return list;
}
// Ham tim kiem khach hang theo sdt
vector<Customer> search_tel(const vector<Customer>& customers) {
	vector<Customer> list;
	string customertel;
	cout << "Search for telephone number: ";
	getline (cin, customertel);
	for(const auto& customer : customers) {
		if (customer.tel == customertel) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is no customer with telephone number: " << customertel << endl;
		return customers;
	} else {
		cout << "There is 1 customer with telephone number: " << customertel << endl;
	}
	list_customers(list);
	return list;
}
// Ham tim kiem khach hang theo ngay thang sinh
vector<Customer> search_dob(const vector<Customer>& customers) {
	vector<Customer> list;
	string customerdob;
	cout << "Search for date of birth (dd/mm): ";
	getline (cin, customerdob);
	for(const auto& customer : customers) {
		if (customer.dob.substr(0, 5) == customerdob) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is no customer with date of birth: " << customerdob << endl;
		return customers;
	} else if (list.size() == 1) {
		cout << "There is 1 customer with date of birth: " << customerdob << endl;
	} else {
		cout << "There are " << list.size() << " customers with date of birth: " << customerdob << endl;
	}
	list_customers(list);
	return list;
}
// Ham tim kiem khach hang theo diem tich luy
vector<Customer> search_pts(const vector<Customer>& customers) {
	vector<Customer> list;
	long int customerpts;
	cout << "Search for point: ";
	cin >> customerpts;
	for(const auto& customer : customers) {
		if (customer.pts > customerpts) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is no customer has more points than: " << customerpts << endl;
		return customers;
	} else if (list.size() == 1) {
		cout << "There is 1 customer has more points than: " << customerpts << endl;
	} else {
		cout << "There are " << list.size() << " customers have more points than " << customerpts << endl;
	}
	list_customers(list);
	return list;
}
// Ham tim kiem khach hang theo xep hang
vector<Customer> search_rank(const vector<Customer>& customers) {
	vector<Customer> list;
	string customerrank;
	cout << "Search for rank: ";
	getline (cin, customerrank);
	for(const auto& customer : customers) {
		if (customer.rank == customerrank) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is no customer with rank: " << customerrank << endl;
		return customers;
	} else if (list.size() == 1) {
		cout << "There is 1 customer with rank: " << customerrank << endl;
	} else {
		cout << "There are " << list.size() << " customers with rank: " << customerrank << endl;
	}
	list_customers(list);
	return list;
}
// Ham tim kiem khach hang theo tong tien da chi
vector<Customer> search_totalbuy(const vector<Customer>& customers) {
	vector<Customer> list;
	double customertotalbuy;
	cout << "Search for total buy: ";
	cin >> totalbuy;
	for(const auto& customer : customers) {
		if (customer.totalbuy > customerdob) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is not customer has bought more than: " << customertotalbuy << endl;
		return customers;
	} else if (list.size() == 1) {
		cout << "There is 1 customer has bought more than: " << customertotalbuy << endl;
	} else {
		cout << "There are " << list.size() << " customers have bought more than: " << customertotalbuy << endl;
	}
	list_customers(list);
	return list;
}
// Ham tong hop cac loai tim kiem
void search_all(const vector<Customer>& customers) {
	cout << "Search for customers by [1]: ID, [2]: Name, [3]: Telephone number, [4]: Date of birth, [5]: Points, [6]: Rank, [7]: Total buy" << endl;
	int choice;
	cin >> choice;
	
}
// Ham thay doi thong tin khach hang
void change_info_customer(vector<Customer>& customers) {
	int customerID;
	cin >> customerID;
	cout << "----------Change Customer Information---------- "<< endl;
	cout << "Changing informaton for customer with ID: " << customerID << endl;
	cin.ignore();
	for (auto& customer : customers) {
		if (customer.ID == customerID) {
			int choice;
			cout << "What do you want to change? [1]: Name, [2]:Telephone number, [3]: Date of birth)" << endl;
			cin >> choice;
			cin.ignore();
			if(choice == 1) {
				cout << "New name: ";
				getline(cin, customer.name);
			}
			else if(choice == 2) {
				cout << "New telephone number: ";
				getline(cin, customer.tel);
			}
			else if(choice == 3) {
				cout << "New date of birth: ";
				getline(cin, customer.dob);
			}
			cout << "Information for customer with ID " << customerID << " has been changed." << endl;
			return;
		}
	}
	cout << "Customer with ID " << customerID << " does not exist." << endl;
}



