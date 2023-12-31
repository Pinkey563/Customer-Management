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
		string ID;
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
			} else if (pts < 2000) {
				rank = "Bronze";
			} else if (pts < 3000) {
				rank = "Silver";
			} else if (pts < 4000) {
				rank = "Gold";
			} else if (pts < 5000) {
				rank = "Platinum";
			} else if (pts < 10000) {
				rank = "Diamond";
			} else if (pts >= 10000) {
				rank = "VIP";
			} else {
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
			output << fixed << setprecision(0) << totalbuy << endl;
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
		void saveToAccountFile(ofstream& output) const {
			output << username << endl;
			output << password << endl;
		}
};
// Ham dang ky tai khoan khach hang
void registerCusAccount(vector<Account>& customerAccounts) {
	string newUsername;
	string newPassword;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\nEnter new username (ID): ";
	getline(cin, newUsername);
	cout << "Enter new password (Tel): ";
	getline(cin, newPassword);
	// Kiem tra xem tai khoan da duoc tao chua
	for (const auto& account : customerAccounts) {
		if (account.username == newUsername) {
			cout << "Username already exists. Try again." << endl;
			return;
		}
	}
	// Them tai khoan moi vao danh sach
	customerAccounts.emplace_back(newUsername, newPassword);
	cout << "Sign up successful." << endl;
}
// Ham dang ky tai khoan nhan vien
void registerStaffAccount(vector<Account>& staffAccounts) {
	string newUsername;
	string newPassword;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\nEnter new username (ID): ";
	getline(cin, newUsername);
	cout << "Enter new password (Tel): ";
	getline(cin, newPassword);
	// Kiem tra xem tai khoan da duoc tao chua
	for (const auto& account : staffAccounts) {
		if (account.username == newUsername) {
			cout << "Username already exists. Try again." << endl;
			return;
		}
	}
	// Them tai khoan moi vao danh sach
	staffAccounts.emplace_back(newUsername, newPassword);
	cout << "Sign up successful." << endl;
}
// Ham hien thi tai khoan khach hang
void showCustomerAccounts(const vector<Account>& customerAccounts) {
	cout << "===================================" << endl;
	cout << "List of Accounts:" << endl;
	for (const auto& account : customerAccounts) {
		cout << "Username: " << account.username << "\tPassword: " << account.password << endl;
	}
	cout << "===================================" << endl;
}
// Ham hien thi tai khoan nhan vien
void showStaffAccounts(const vector<Account>& staffAccounts) {
	cout << "===================================" << endl;
	cout << "List of Accounts:" << endl;
	for (const auto& account : staffAccounts) {
		cout << "Username: " << account.username << "\tPassword: " << account.password << endl;
	}
	cout << "===================================" << endl;
}
// Ham dang nhap khach hang
bool loginCusAccount(const vector<Account>& customerAccounts, int& currentCustomerIndex) {
	string inputUsername;
	string inputPassword;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter username (ID): ";
	getline(cin, inputUsername);
	cout << "Enter password (Tel): ";
	getline(cin, inputPassword);
	// Kiem tra tung tai khoan
	for (size_t i = 0; i < customerAccounts.size(); i++) {
		if (customerAccounts[i].login(inputUsername, inputPassword)) {
			cout << "Login successfully." << endl;
			currentCustomerIndex = i;
			return true;
		}
	}
// Neu tai khoan do chua duoc dang ki
	cout << "Login failed. Invalid username or password." << endl;
	return false;
}
// Ham dang nhap nhan vien
bool loginStaffAccount(const vector<Account>& staffAccounts) {
	string inputUsername;
	string inputPassword;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter username (ID): ";
	getline(cin, inputUsername);
	cout << "Enter password (Tel): ";
	getline(cin, inputPassword);
	// Kiem tra tung tai khoan
	for (const auto& account : staffAccounts) {
		if (account.login(inputUsername, inputPassword)) {
			cout << "Login successfully." << endl;
			return true;
		}
	}
	// Neu tai khoan do chua duoc dang ki
	cout << "Login failed. Invalid username or password." << endl;
	return false;
}
// Ham dang nhap quan li
bool loginManagerAccount(const vector<Account>& managerAccounts) {
	string inputUsername;
	string inputPassword;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter username (ID): ";
	getline(cin, inputUsername);
	cout << "Enter password (Tel): ";
	getline(cin, inputPassword);
	// Kiem tra tung tai khoan
	for (const auto& account : managerAccounts) {
		if (account.login(inputUsername, inputPassword)) {
			cout << "Login successfully." << endl;
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
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "ID: ";
	getline(cin, customer.ID);
	cout << "Name: ";
	getline(cin, customer.name);
	cout << "Telephone number: ";
	getline(cin, customer.tel);
	cout << "Date of birth (dd/mm/yyyy): ";
	getline(cin, customer.dob);
	customer.totalbuy = 0.0;
	customer.update_rank_and_pts();
}
// Ham hien thi thong tin cua tung khach hang
void show_customer(const Customer& customer) {
	cout << setfill(' ');
	cout << setw(5) << left << customer.ID;
	cout << setw(20) << left << customer.name;
	cout << setw(20) << left << customer.tel;
	cout << setw(20) << left << customer.dob;
	cout << setw(15) << left << customer.pts;
	cout << setw(20) << left << customer.rank;
	cout << setw(20) << left << customer.totalbuy;
}
// Ham tao ra 1 list hien thi thong tin khach hang
void list_customers(const vector<Customer>& customers) {
	cout << setfill(' ');
	cout << setw(5) << left << "ID";
	cout << setw(20) << left << "Name";
	cout << setw(20) << left << "Telephone";
	cout << setw(20) << left << "Date of Birth";
	cout << setw(15) << left << "Points";
	cout << setw(20) << left << "Rank";
	cout << setw(20) << left << "Total Buy" << endl;
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
	cout << "Delete customer by [1]: ID, [2]: Name, [3]: Telephone number, [4]: Date of birth " << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		cin.ignore();
		string customerID;
		cout << "Delete customer by ID: ";
		getline(cin, customerID);
		customers.erase(remove_if(customers.begin(), customers.end(),
		[customerID](const Customer& customer) {
			return customer.ID == customerID;
		}),
		customers.end());
		cout << "DONE !!!" <<endl;
	} else if (choice == 2) {
		cin.ignore();
		string customername;
		cout << "Delete customer by name: ";
		getline(cin, customername);
		customers.erase(remove_if(customers.begin(), customers.end(),
		[customername](const Customer& customer) {
			return customer.name == customername;
		}),
		customers.end());
		cout << "DONE !!!" <<endl;
	} else if (choice == 3) {
		cin.ignore();
		string customertel;
		cout << "Delete customer by telephone number: ";
		getline(cin, customertel);
		customers.erase(remove_if(customers.begin(), customers.end(),
		[customertel](const Customer& customer) {
			return customer.tel == customertel;
		}),
		customers.end());
		cout << "DONE !!!" <<endl;
	} else if (choice == 4) {
		cin.ignore();
		string customerdob;
		cout << "Delete customer by date of birth: ";
		getline(cin, customerdob);
		customers.erase(remove_if(customers.begin(), customers.end(),
		[customerdob](const Customer& customer) {
			return customer.dob == customerdob;
		}),
		customers.end());
		cout << "DONE !!!" <<endl;
	} else {
		cout << "Invalid choice " << endl;
	}
	return;
}
// Ham thay doi thong tin tai khoan khach hang
void changeAccount(vector<Account>& customerAccounts) {
	bool found = false;
	string targetUsername;
	string changeUsername;
	string changePassword;
	cout << "Enter username of the account you want to modify: ";
	cin >> targetUsername;
	for (int i = 0; i < customerAccounts.size(); i++) {
		if(customerAccounts[i].username == targetUsername) {
			found = true;
			cout << "Old username: " << customerAccounts[i].username << endl;
			cout << "Old password: " << customerAccounts[i].password << endl;
			cout << "=========================" << endl;
			cout << "New username: ";
			cin >> changeUsername;
			cout << "New password: ";
			cin >> changePassword;
			customerAccounts[i].username = changeUsername;
			customerAccounts[i].password = changePassword;
			cout << "You have change successfully!!" << endl;
			ofstream output("CustomerAccount.txt");
			if (output.is_open()) {
				for (const auto& account : customerAccounts) {
					account.saveToAccountFile(output);
				}
			}
			output.close();
			break;
		}
	}
	if (!found) {
		cout << "No account has that username" << endl;
	}
}
// Ham sap xep thong tin khach hang theo ID
vector<Customer> sort_ID (const vector<Customer>& customers) {
	vector<string> listID;
	vector<Customer> listSorted;
	cin.ignore();
	for (const auto& customer : customers) {
		listID.push_back(customer.ID);
	}
	cout << "How do you want to sort?" << endl;
	cout << "[1]: Ascending" << endl;
	cout << "[2]: Descending" << endl;
	int choice;
	cout << "Your choice (sort): " ;
	cin >> choice;
	switch (choice) {
		case 1:
			sort (listID.begin(), listID.end());
			break;
		case 2:
			sort (listID.begin(), listID.end(), greater<string>());
			break;
	}
	for (int i = 0; i < listID.size(); i++) {
		for (const auto& customer : customers) {
			if (listID[i] == customer.ID) {
				listSorted.push_back(customer);
			}
		}
	}
	list_customers(listSorted);
	return listSorted;
}
// Ham sap xep thong tin khach hang theo ngay sinh
vector<Customer> sort_Day (const vector<Customer>& customers) {
	vector<string> listDay;
	vector<Customer> listSorted;
	cin.ignore();
	for (const auto& customer : customers) {
		listDay.push_back(customer.dob.substr(0, 2));
	}
	cout << "How do you want to sort?" << endl;
	cout << "[1]: Ascending" << endl;
	cout << "[2]: Descending" << endl;
	int choice;
	cout << "Your choice (sort): " ;
	cin >> choice;
	switch (choice) {
		case 1:
			sort (listDay.begin(), listDay.end());
			break;
		case 2:
			sort (listDay.begin(), listDay.end(), greater<string>());
			break;
	}
	for (int i = 0; i < listDay.size(); i++) {
		for (const auto& customer : customers) {
			if (listDay[i] == customer.dob.substr(0, 2)) {
				listSorted.push_back(customer);
			}
		}
	}
	list_customers(listSorted);
	return listSorted;
}
// Ham sap xep thong tin khach hang theo thang sinh
vector<Customer> sort_Month (const vector<Customer>& customers) {
	vector<string> listMonth;
	vector<Customer> listSorted;
	cin.ignore();
	for (const auto& customer : customers) {
		listMonth.push_back(customer.dob.substr(3, 5));
	}
	cout << "How do you want to sort?" << endl;
	cout << "[1]: Ascending" << endl;
	cout << "[2]: Descending" << endl;
	int choice;
	cout << "Your choice (sort): " ;
	cin >> choice;
	switch (choice) {
		case 1:
			sort (listMonth.begin(), listMonth.end());
			break;
		case 2:
			sort (listMonth.begin(), listMonth.end(), greater<string>());
			break;
	}
	for (int i = 0; i < listMonth.size(); i++) {
		for (const auto& customer : customers) {
			if (listMonth[i] == customer.dob.substr(3, 5)) {
				listSorted.push_back(customer);
			}
		}
	}
	list_customers(listSorted);
	return listSorted;
}
// Ham sap xep thong tin khach hang theo nam sinh
vector<Customer> sort_Year (const vector<Customer>& customers) {
	vector<string> listYear;
	vector<Customer> listSorted;
	cin.ignore();
	for (const auto& customer : customers) {
		listYear.push_back(customer.dob.substr(6, 10));
	}
	cout << "How do you want to sort?" << endl;
	cout << "[1]: Ascending" << endl;
	cout << "[2]: Descending" << endl;
	int choice;
	cout << "Your choice (sort): " ;
	cin >> choice;
	switch (choice) {
		case 1:
			sort (listYear.begin(), listYear.end());
			break;
		case 2:
			sort (listYear.begin(), listYear.end(), greater<string>());
			break;
	}
	for (int i = 0; i < listYear.size(); i++) {
		for (const auto& customer : customers) {
			if (listYear[i] == customer.dob.substr(6, 10)) {
				listSorted.push_back(customer);
			}
		}
	}
	list_customers(listSorted);
	return listSorted;
}
// Ham sap xep thong tin khach hang theo diem tich luy
vector<Customer> sort_Pts (const vector<Customer>& customers) {
	vector<long int> listPts;
	vector<Customer> listSorted;
	cin.ignore();
	for (const auto& customer : customers) {
		listPts.push_back(customer.pts);
	}
	cout << "How do you want to sort?" << endl;
	cout << "[1]: Ascending" << endl;
	cout << "[2]: Descending" << endl;
	int choice;
	cout << "Your choice (sort): " ;
	cin >> choice;
	switch (choice) {
		case 1:
			sort (listPts.begin(), listPts.end());
			break;
		case 2:
			sort (listPts.begin(), listPts.end(), greater<long int>());
			break;
	}
	for (int i = 0; i < listPts.size(); i++) {
		for (const auto& customer : customers) {
			if (listPts[i] == customer.pts) {
				listSorted.push_back(customer);
			}
		}
	}
	list_customers(listSorted);
	return listSorted;
}
// Ham sap xep thong tin khach hang theo tong tien da chi tieu
vector<Customer> sort_TotalBuy (const vector<Customer>& customers) {
	vector<double> listTotalBuy;
	vector<Customer> listSorted;
	cin.ignore();
	for (const auto& customer : customers) {
		listTotalBuy.push_back(customer.totalbuy);
	}
	cout << "How do you want to sort?" << endl;
	cout << "[1]: Ascending" << endl;
	cout << "[2]: Descending" << endl;
	int choice;
	cout << "Your choice (sort): " ;
	cin >> choice;
	switch (choice) {
		case 1:
			sort (listTotalBuy.begin(), listTotalBuy.end());
			break;
		case 2:
			sort (listTotalBuy.begin(), listTotalBuy.end(), greater<double>());
			break;
	}
	for (int i = 0; i < listTotalBuy.size(); i++) {
		for (const auto& customer : customers) {
			if (listTotalBuy[i] == customer.totalbuy) {
				listSorted.push_back(customer);
			}
		}
	}
	list_customers(listSorted);
	return listSorted;
}
// Ham tong hop sap xep
vector<Customer> sort_All (const vector<Customer>& customers) {
	cout << "Sort by [1]: ID, [2]: Date of birth, [3]: Points, [4]: Total buy" << endl;
	int choice;
	cout << "Your choice (sort type): ";
	cin >> choice;
	cin.ignore();
	switch (choice) {
		case 1:
			return sort_ID (customers);
			break;
		case 2:
			cout << "Sort by [1]: Day, [2]: Month, [3]: Year" << endl;
			int sortChoice;
			cout << "Your choice (DOB sort type): ";
			cin >> sortChoice;
			if (sortChoice == 1) {
				return sort_Day (customers);
			} else if (sortChoice == 2) {
				return sort_Month (customers);
			} else if (sortChoice == 3) {
				return sort_Year (customers);
			}
			break;
		case 3:
			return sort_Pts (customers);
			break;
		case 4:
			return sort_TotalBuy (customers);
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
	}
}
// Ham tim kiem khach hang theo ID
vector<Customer> search_ID(const vector<Customer>& customers) {
	vector<Customer> list;
	cin.ignore();
	string customerID;
	cout << "Search for ID: ";
	getline(cin, customerID);
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
	cin.ignore();
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
	cin.ignore();
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
	cin.ignore();
	string customerdob;
	cout << "Search for month of birth (mm): ";
	getline (cin, customerdob);
	for(const auto& customer : customers) {
		if (customer.dob.substr(3, 5) == customerdob) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is no customer with month of birth: " << customerdob << endl;
		return customers;
	} else if (list.size() == 1) {
		cout << "There is 1 customer with month of birth: " << customerdob << endl;
	} else {
		cout << "There are " << list.size() << " customers with month of birth: " << customerdob << endl;
	}
	list_customers(list);
	return list;
}
// Ham tim kiem khach hang theo diem tich luy
vector<Customer> search_pts(const vector<Customer>& customers) {
	vector<Customer> list;
	cin.ignore();
	long int customerpts;
	cout << "Search for point: ";
	cin >> customerpts;
	for(const auto& customer : customers) {
		if (customer.pts >= customerpts) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is no customer has points more than or equal to: " << customerpts << endl;
		return customers;
	} else if (list.size() == 1) {
		cout << "There is 1 customer has points more than or equal to: " << customerpts << endl;
	} else {
		cout << "There are " << list.size() << " customers have points more than or equal to" << customerpts << endl;
	}
	list_customers(list);
	return list;
}
// Ham tim kiem khach hang theo xep hang
vector<Customer> search_rank(const vector<Customer>& customers) {
	vector<Customer> list;
	cin.ignore();
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
	cin.ignore();
	double customertotalbuy;
	cout << "Search for total buy: ";
	cin >> customertotalbuy;
	for(const auto& customer : customers) {
		if (customer.totalbuy >= customertotalbuy) {
			list.push_back(customer);
		}
	}
	if (list.size() == 0) {
		cout << "There is not customer has bought more than or equal to: " << customertotalbuy << endl;
		return customers;
	} else if (list.size() == 1) {
		cout << "There is 1 customer has bought more than or equal to: " << customertotalbuy << endl;
	} else {
		cout << "There are " << list.size() << " customers have bought more than or equal to: " << customertotalbuy << endl;
	}
	list_customers(list);
	return list;
}
// Ham tong hop cac loai tim kiem
void search_all(const vector<Customer>& customers) {
	cout << "Search by [1]: ID, [2]: Name, [3]: Telephone number, [4]: Date of birth, [5]: Points, [6]: Rank, [7]: Total buy" << endl;
	int choice;
	cout << "Your choice (search type): ";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (choice == 1) {
		search_ID(customers);
	} else if (choice == 2) {
		search_name(customers);
	} else if (choice == 3) {
		search_tel(customers);
	} else if (choice == 4) {
		search_dob(customers);
	} else if (choice == 5) {
		search_pts(customers);
	} else if (choice == 6) {
		search_rank(customers);
	} else if (choice == 7) {
		search_totalbuy(customers);
	}
}
// Ham thay doi thong tin khach hang
void change_info_customer(vector<Customer>& customers) {
	string customerID;
	cout << "----------Change Customer Information---------- "<< endl;
	cout << "Changing informaton for customer with ID: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, customerID);
	for (auto& customer : customers) {
		if (customer.ID == customerID) {
			int choice;
			cout << "What do you want to change? [1]: Name, [2]:Telephone number, [3]: Date of birth, [4]: Total buy)" << endl;
			cin >> choice;
			cin.ignore();
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
// Ham kiem tra khach hang va in thong tin khach hang do
void check(const vector<Customer>& customers, const vector<Account>& customerAccounts, int& currentCustomerIndex) {
	bool found = false;
	string loginUsername;
	string loginPassword;
	for (int i =0; i < customerAccounts.size(); i++) {
		if (i == currentCustomerIndex) {
			loginUsername = customerAccounts[i].username;
			loginPassword = customerAccounts[i].password;
		}
	}
	for(const auto&customer : customers) {
		if (loginUsername == customer.ID && loginPassword == customer.tel) {
			cout << "Here is your information, " << customer.name << " !!!" << endl;
			cout << setfill(' ');
			cout << setw(5) << left << "ID";
			cout << setw(20) << left << "Name";
			cout << setw(20) << left << "Telephone";
			cout << setw(20) << left << "Date of Birth";
			cout << setw(15) << left << "Points";
			cout << setw(20) << left << "Rank";
			cout << setw(20) << left << "Total Buy" << endl;
			show_customer(customer);
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "No matching account found for customer" << endl;
	}
}
// Ham in the thanh vien tam thoi
void tempCard (const vector<Customer>& customers, const vector<Account>& customerAccounts, int& currentCustomerIndex) {
	bool found = false;
	string loginUsername;
	string loginPassword;
	for (int i =0; i < customerAccounts.size(); i++) {
		if (i == currentCustomerIndex) {
			loginUsername = customerAccounts[i].username;
			loginPassword = customerAccounts[i].password;
		}
	}
	for(const auto&customer : customers) {
		for (int i =0; i < customerAccounts.size(); i++) {
			if (loginUsername == customer.ID && loginPassword == customer.tel) {
				cout << "=================================================" << endl;
				cout << "||           Customer's Information            ||" << endl;
				cout << "|| ID: " << setw(40) << left << customer.ID << "||" << endl;
				cout << "|| Name: " << setw(38) << left << customer.name << "||" << endl;
				cout << "|| Telephone Number: " << setw(26) << left << customer.tel << "||" << endl;
				cout << "|| Date of birth: " << setw(29) << left << customer.dob << "||" << endl;
				cout << "|| Total point: " << setw(31) << left << customer.pts << "||" << endl;
				cout << "|| Rank: " << setw(38) << left << customer.rank << "||" << endl;
				cout << "|| Total buy: " << setw(33) << left << customer.totalbuy << "||" << endl;
				cout << "=================================================" << endl;
				found = true;
				break;
			}
		}
	}
	if (!found) {
		cout << "No matching account found for customer" << endl;
	}
}
// Ham ghi danh sach tai khoan Customer vao file
void saveCustomerAccountToFile(vector<Account>& customerAccounts) {
	ofstream output("CustomerAccount.txt");
	if (output.is_open()) {
		for (const auto& account : customerAccounts) {
			account.saveToAccountFile(output);
		}
	}
	output.close();
}
// Ham ghi danh sach tai khoan Staff vao file
void saveStaffAccountToFile(vector<Account>& staffAccounts) {
	ofstream output("StaffAccount.txt");
	if (output.is_open()) {
		for (const auto& account : staffAccounts) {
			account.saveToAccountFile(output);
		}
	}
	output.close();
}
// Ham doc tai khoan Customer trong file
void readCustomerAccountFile(vector<Account>& customerAccounts) {
	ifstream input("CustomerAccount.txt");
	if (input.is_open()) {
		string username;
		string password;
		while (input >> username >> password) {
			customerAccounts.emplace_back(username, password);
		}
	}
	input.close();
}
// Ham doc tai khoan Staff trong file
void readStaffAccountFile(vector<Account>& staffAccounts) {
	ifstream input("StaffAccount.txt");
	if (input.is_open()) {
		string username;
		string password;
		while (input >> username >> password) {
			staffAccounts.emplace_back(username, password);
		}
	}
	input.close();
}
// Ham doc tai khoan Manager trong file
void readManagerAccountFile(vector<Account>& managerAccounts) {
	ifstream input("ManagerAccount.txt");
	if (input.is_open()) {
		string username;
		string password;
		while (input >> username >> password) {
			managerAccounts.emplace_back(username, password);
		}
	}
	input.close();
}
// Ham dinh dang thong tin Customer trong file
void saveCustomerToFile(vector<Customer>& customers) {
	ofstream output("Customer.txt");
	if (output.is_open()) {
		for (const auto& customer : customers) {
			customer.saveToCustomerFile(output);
		}
	}
	output.close();
}
// Ham doc thong tin Customer trong file
void readCustomerFile(vector<Customer>& customers) {
	ifstream input("Customer.txt");
	if (input.is_open()) {
		Customer customer;
		while (input >> ws && getline(input, customer.ID) >> ws && getline(input, customer.name) >> ws && getline(input, customer.tel) >> ws &&
		        getline(input, customer.dob) >> customer.pts >> ws && getline(input, customer.rank) >> customer.totalbuy) {
			customers.push_back(customer);
		}
	}
	input.close();
}
// Ham in hinh anh
void printSeal() {
	ifstream input("Seal.txt");
	if (input.is_open()) {
		cout << input.rdbuf();
		input.close();
	}
}
// Ham main
int main() {
	int currentCustomerIndex = -1;
	vector<Customer> customers;
	vector<Account> customerAccounts;
	vector<Account> staffAccounts;
	vector<Account> managerAccounts;
	readCustomerFile(customers);
	readCustomerAccountFile(customerAccounts);
	readStaffAccountFile(staffAccounts);
	readManagerAccountFile(managerAccounts);
	printSeal();
	cout << fixed;
	cout << setprecision(0);
	bool exitProgram = false;
	while (!exitProgram) {
		cout << "\nWelcome to the customer management system" << endl;
		cout << "User type? " << endl;
		cout << "[1]: Customer" << endl;
		cout << "[2]: Staff" << endl;
		cout << "[3]: Manager" << endl;
		cout << "[0]: Exit" << endl;
		int userChoice;
		cout << "Your choice (user type): ";
		cin >> userChoice;
		switch (userChoice) {
			case 1:
				cout << "\nWelcome Customer!!" << endl;
				break;
			case 2:
				cout << "\nWelcome Staff!!" << endl;
				break;
			case 3:
				cout << "\nWelcome Manager!!" << endl;
				break;
			case 0:
				return 0;
			default:
				cout << "\nInvalid choice." << endl;
				continue;
		}
		bool exitUserType = false;
		while (!exitUserType) {
			bool login = false;
			if (!login) {
				cout << "\nPlease select your option: " << endl;
				cout << "[1]: Login" << endl;
				cout << "[0]: Exit" << endl;
				cout << "-------------------------------------" << endl;
				cout << "Your choice (login option): ";
			}
			int choice;
			cin >> choice;
			switch (choice) {
				case 1:
					if (userChoice == 1) {
						if (loginCusAccount(customerAccounts, currentCustomerIndex)) {
							login = true;
							cout << "\n--------------- Main menu for customer ---------------" << endl;
							cout << "[1]: Show customer's information " << endl;
							cout << "[2]: Print temporary card " << endl;
							cout << "[0]: Exit " << endl;
						}
					}
					if (userChoice == 2) {
						if (loginStaffAccount(staffAccounts)) {
							login = true;
							cout << "\n--------------- Main menu for staff ---------------" << endl;
							cout << "[1]: Show the list of customers " << endl;
							cout << "[2]: Add a new customer " << endl;
							cout << "[3]: Delete a customer " << endl;
							cout << "[4]: Change customer's information " << endl;
							cout << "[5]: Search for customers by categories " << endl;
							cout << "[6]: Sort customers by categories " << endl;
							cout << "[7]: Register customer account" << endl;
							cout << "[8]: Show customer accounts" << endl;
							cout << "[9]: Change account information " << endl;
							cout << "[0]: Exit " << endl;
						}
					}
					if (userChoice == 3) {
						if (loginManagerAccount(managerAccounts)) {
							login = true;
							cout << "\n--------------- Main menu for manager ---------------" << endl;
							cout << "[1]: Register staff account" << endl;
							cout << "[2]: Show staff accounts" << endl;
							cout << "[0]: Exit" << endl;
						}
					}
					break;
				case 0:
					exitUserType = true;
					break;
				default:
					cout << "Invalid choice." << endl;
					break;
			}
			if (login) {
				while (1) {
					cout << "\n-------------------------------------" << endl;
					cout << "Your choice (main menu): ";
					int choice;
					cin >> choice;
					if (userChoice == 1) {
						switch (choice) {
							case 1:
								check (customers, customerAccounts, currentCustomerIndex);
								break;
							case 2:
								tempCard (customers, customerAccounts, currentCustomerIndex);
								break;
							case 0:
								break;
							default:
								cout << "Invalid choice" << endl;
								break;
						}
					}
					if  (userChoice == 2) {
						switch (choice) {
							case 1:
								list_customers(customers);
								break;
							case 2:
								add_customer(customers);
								saveCustomerToFile(customers);
								break;
							case 3:
								delete_customer(customers);
								saveCustomerToFile(customers);
								break;
							case 4:
								change_info_customer(customers);
								saveCustomerToFile(customers);
								break;
							case 5:
								search_all(customers);
								break;
							case 6:
								sort_All(customers);
								break;
							case 7:
								registerCusAccount(customerAccounts);
								saveCustomerAccountToFile(customerAccounts);
								break;
							case 8:
								showCustomerAccounts(customerAccounts);
								break;
							case 9:
								changeAccount(customerAccounts);
								break;
							case 0:
								saveCustomerToFile(customers);
								break;
							default:
								cout << "Invalid choice" << endl;
								break;
						}
					}
					if (userChoice == 3) {
						switch (choice) {
							case 1:
								registerStaffAccount(staffAccounts);
								saveStaffAccountToFile(staffAccounts);
								break;
							case 2:
								showStaffAccounts(staffAccounts);
								break;
							case 0:
								break;
							default:
								cout << "Invalid choice" << endl;
								break;
						}
					}
					if (choice == 0) {
						break;
					}
				}
			}
			if (exitUserType) {
				break;
			}
		}
	}
	return 0;
}


