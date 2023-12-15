#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>		// for std::setw(n), std::setfill(ch), std::left
#include <string>		
#include <fstream>		// open, write to file
#include <limits>
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
		// Ham cap nhat diem va rank dua vao tong tien da chi tieu
		void update_rank_and_pts() {
			pts = static_cast<int>(totalbuy) / 1000;
			if (pts < 1000) {
				rank = "None";
			} 
			else if (pts < 2000) {
				rank = "Bronze";
			} 
			else if (pts < 3000) {
				rank = "Silver";
			} 
			else if (pts < 4000) {
				rank = "Gold";
			} 
			else if (pts < 5000) {
				rank = "Platinum";
			} 
			else if (pts < 10000) {
				rank = "Diamond";
			} 
			else if (pts >= 10000) {
				rank = "VIP";
			}
			else {
				cout << "Invalid purchase";	
			}
			return;
		}
		// Ham ghi thong tin tai khoan vao file
    	void saveToCustomerFile(ofstream& output) const {
        output << ID << endl;
        output << name << endl;
        output << tel << endl;
        output << dob << endl;
		output << pts << endl;
        output << rank << endl;
        output << totalbuy << endl;
    	}
};
// Tao class Account chua ten dang nhap va mat khau
class Account {
public:
    string username;
    string password;
    Account() : username(""), password("") {}
    Account(const string& username, const string& password) : username(username), password(password) {
    }
	// Ham kiem tra dang nhap
    bool login(const string& inputUsername, const string& inputPassword) const {
        return (inputUsername == username && inputPassword == password);
    }
    // Ham ghi thong tin tai khoan vao file
    void saveToAccountFile(ofstream& file) const {
        file << username << endl;
        file << password << endl;
    }
};
// Ham dang ky tai khoan
void registerAccount(vector<Account>& accounts) {
    string newUsername;
	string newPassword;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter new username: ";
    getline(cin, newUsername);
    cout << "Enter new password: ";
    getline(cin, newPassword);
    // Kiem tra xem tai khoan da duoc tao chua
    for (const auto& account : accounts) {
        if (account.username == newUsername) {
            cout << "Username already exists. Try again." << endl;
            return;
        }
    }
    // Them tai khoan moi vao danh sach
    accounts.emplace_back(newUsername, newPassword);
    cout << "Sign up successful." << endl;
}
// Ham dang nhap
bool loginAccount(const vector<Account>& accounts) {
    string inputUsername;
	string inputPassword;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter username: ";
    getline(cin, inputUsername);
    cout << "Enter password: ";
    getline(cin, inputPassword);
    // Kiem tra tung tai khoan
    for (const auto& account : accounts) {
        if (account.login(inputUsername, inputPassword)) {
            cout << "Login successful." << endl;
            return true;
        }
    }
    // Neu tai khoan do chua duoc dang ki
    cout << "Login failed. Invalid username or password." << endl;
    return false;
}
// Ham khoi tao khach hang moi
void create_customer(Customer& customer) {
	cout << "----------Customer Information----------" << endl;
	cout << "ID: ";
	cin >> customer.ID;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Name: ";
	getline(cin,customer.name);
	cout << "Telephone number: ";
	getline(cin,customer.tel);
	cout << "Date of birth (dd/mm/yyyy): ";
	getline(cin,customer.dob);
	customer.totalbuy = 0.0;
	customer.update_rank_and_pts();
}
// Ham hien thi thong tin cua tung khach hang
void show_customer(const Customer& customer) {
	cout << setfill(' ');
	cout << setw(5) << left << customer.ID;
	cout << setw(30) << left << customer.name;
	cout << setw(20) << left << customer.tel;
	cout << setw(20) << left << customer.dob;
	cout << setw(10) << left << customer.pts;
	cout << setw(20) << left << customer.rank;
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
	cin >> choice;
	if (choice == 1) {
		cin.ignore();
		int customerID;
		cout << "Delete customer by ID: ";
		cin >> customerID;
		customers.erase(remove_if(customers.begin(), customers.end(),
							[customerID](const Customer& customer) {return customer.ID == customerID; }),
				customers.end());
		cout << "DONE !!!" <<endl;
	} 
	else if (choice == 2) {
		cin.ignore();
		string customername;
		cout << "Delete customer by name: ";
		getline(cin, customername);
		customers.erase(remove_if(customers.begin(), customers.end(),
							[customername](const Customer& customer) {return customer.name == customername; }),
				customers.end());
		cout << "DONE !!!" <<endl;
	} 
	else if (choice == 3) {
		cin.ignore();
		string customertel;
		cout << "Delete customer by telephone number: ";
		getline(cin, customertel);
		customers.erase(remove_if(customers.begin(), customers.end(),
							[customertel](const Customer& customer) {return customer.tel == customertel; }),
				customers.end());
		cout << "DONE !!!" <<endl;
	} 
	else if (choice == 4) {
		cin.ignore();
		string customerdob;
		cout << "Delete customer by date of birth: ";
		getline(cin, customerdob);
		customers.erase(remove_if(customers.begin(), customers.end(),
							[customerdob](const Customer& customer) {return customer.dob == customerdob; }),
				customers.end());
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
	cin >> customertotalbuy;
	for(const auto& customer : customers) {
		if (customer.totalbuy > customertotalbuy) {
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
	cout << "Search by [1]: ID, [2]: Name, [3]: Telephone number, [4]: Date of birth, [5]: Points, [6]: Rank, [7]: Total buy" << endl;
	int choice;
	cin >> choice;
	cin.ignore();
	if (choice == 1) {
		search_ID(customers);
	}
	else if (choice == 2) {
		search_name(customers);
	}
	else if (choice == 3) {
		search_tel(customers);
	}
	else if (choice == 4) {
		search_dob(customers);
	}
	else if (choice == 5) {
		search_pts(customers);
	}
	else if (choice == 6) {
		search_rank(customers);
	}
	else if (choice == 7) {
		search_totalbuy(customers);
	}
}
// Ham thay doi thong tin khach hang
void change_info_customer(vector<Customer>& customers) {
	int customerID;
	cout << "----------Change Customer Information---------- "<< endl;
	cout << "Changing informaton for customer with ID: ";
	cin >> customerID;
	for (auto& customer : customers) {
		if (customer.ID == customerID) {
			int choice;
			cout << "What do you want to change? [1]: Name, [2]:Telephone number, [3]: Date of birth, [4]: Total buy)" << endl;
			cin >> choice;
			if(choice == 1) {
				cout << "New name: ";
				getline(cin, customer.name);
			} else if(choice == 2) {
				cout << "New telephone number: ";
				getline(cin, customer.tel);
			} else if(choice == 3) {
				cout << "New date of birth: ";
				getline(cin, customer.dob);
			} else if(choice == 4) {
				double newpurchase;
				cout << "New purchase: ";
				cin >> newpurchase;
				customer.totalbuy += newpurchase;
				customer.update_rank_and_pts();
			}
			cout << "Information for customer with ID " << customerID << " has been changed." << endl;
			return;
		}
	}
	cout << "Customer with ID " << customerID << " does not exist." << endl;
}
// Ham ghi danh sach tai khoan vao file
void saveAccountToFile(const vector<Account>& accounts) {
    ofstream file("Account.txt");
    if (file.is_open()) {
        for (const auto& account : accounts) {
            account.saveToAccountFile(file);
        }
        cout << "Accounts have been saved to file." << endl;
    } else {
        cout << "Failed to open file for writing." << endl;
    }
    file.close();
}

void readAccountFile(vector<Account>& accounts) {
    ifstream file("Accounts.txt");
    if (file.is_open()) {
        string username, password;
        while (file >> username >> password) {
            accounts.emplace_back(username, password);
        }
        cout << "Accounts have been loaded." << std::endl;
    } else {
        cout << "Failed to open file for reading." << std::endl;
    }
    file.close();
}
// Ham dinh dang thong tin trong file
void customerFile(const vector<Customer>& customers) {
    ofstream output("Customer.txt");
    if (output.is_open()) {
        for (const auto& customer : customers) {
            customer.saveToCustomerFile(output);
        }
        cout << "Customers' information has been saved to the file." << endl;
    } else {
        cout << "File is unable to be used." << endl;
    }
    output.close();
}

void readCustomerFile(vector<Customer>& customers) {
    ifstream input("Customer.txt");
    if (input.is_open()) {
    	Customer customer;
        while (input >> customer.ID >> customer.name >> customer.tel >> customer.dob) {
            customers.push_back(customer);
        }
        cout << "Customers' information has been loaded!" << endl;
    } 
	else {
        cout << "Failed to load customers' information!" << endl;
    }
    input.close();
}
int main() {
	vector<Customer> customers;
	vector<Account> accounts;
 	readCustomerFile(customers);
 	customerFile(customers);
 	readAccountFile(accounts);
 	saveAccountToFile(accounts);
	cout << fixed;
	cout << setprecision(0);
    bool exitProgram = false;
    while (!exitProgram) {
        cout << "Welcome to the customer management system" << endl;
        cout << "Please select your option: " << endl;
        cout << "[1]: Login" << endl;
        cout << "[2]: Sign up" << endl;
        cout << "[3]: Exit" << endl;
        bool login = false;
        while (!login) {
            cout << "-------------------------------------" << endl;
            cout << "Your choice: ";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    login = loginAccount(accounts);
                    if (login) {
                        cout << "--------------- Main menu ---------------" << endl;
                        cout << "[1]: Show the list of customers " << endl;
                        cout << "[2]: Add a new customer " << endl;
                        cout << "[3]: Delete a customer " << endl;
                        cout << "[4]: Search for customers by categories " << endl;
                        cout << "[5]: Change customer's information " << endl;
                        cout << "[6]: Exit " << endl;
                    }
                    break;
                case 2:
                    registerAccount(accounts);
                    break;
                case 3:
                    cout << "Exiting the program." << endl;
                    return 0;
                default:
                    cout << "Invalid choice." << endl;
            }
        }
            while (1) {
                cout << "-------------------------------------" << endl;
                cout << "Your choice: ";
                int choice;
                cin >> choice;
                switch (choice) {
                    case 1:
                        list_customers(customers);
                        break;
                    case 2:
                        add_customer(customers);
                        break;
                    case 3:
                        delete_customer(customers);
                        break;
                    case 4:
                        search_all(customers);
                        break;
                    case 5:
                        change_info_customer(customers);
                        break;
                    case 6:
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                }
                if (choice == 6) {
                    break;
                }
            }
    }
    return 0;
}


