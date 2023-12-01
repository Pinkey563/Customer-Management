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


class List {
	private:
		CusInfo* head;
		CusInfo* tail;
		int length;
	public:
		// Constructor
		List() {
			head=nullptr;
			tail=nullptr;
			length=0;
		}
		// Destructor
		~List() {
			CusInfo* temp=head;
			while(head != nullptr) {
				head=temp->next;
				delete temp;
				temp=head;
			}
		}
		// In danh sach
		void printList() {
			CusInfo* temp=head;
			if (length == 0) {
				cout << "Khong co khach hang." << endl;
				return;
			}
			int i=1;
			cout << endl;
			cout << setfill(' ');
			cout << setw(5) << left << "ID";
			cout << setw(15) << left << "Ten";
			cout << setw(30) << left << "SDT";
			cout << setw(20) << left << "DOB";
			cout << setw(20) << left << "Total point";
			cout << setw(15) << left << "Rank";
			cout << setw(5) << left << "Total buy" << endl;
			cout << setfill('-');
			cout << setw(115) << "-" << endl;
			while(temp != nullptr) {
				cout << setfill(' ');
				cout << setw(5) << left << i;
				CusInfo.show_customer();
				cout << setfill('-');

				temp=temp->next;
				i++;
			}
			cout << setw(115) << "-" << endl;
		}
		// Them vao duoi
		void append() {
        KH* newKH = new KH;
        nhapthongtin(newKH);
        updateRank(newKH);
        if (length == 0) {
            head = newKH;
            tail = newKH;
            newKH->next = nullptr;
            newKH->prev = nullptr; // Set the previous pointer to nullptr for the first node
        } else {
            newKH->prev = tail; // Set the previous pointer to the current tail
            tail->next = newKH;
            tail = newKH;
            newKH->next = nullptr;
        }
        length++;
    }
		// Them vao dau
		void prepend() {
        KH* newKH = new KH;
        nhapthongtin(newKH);
        updateRank(newKH);
        if (length == 0) {
            head = newKH;
            tail = newKH;
            newKH->next = nullptr;
            newKH->prev = nullptr;
        } else {
            newKH->next = head; // Set the next pointer to the current head
            head->prev = newKH;
            head = newKH;
        }
        length++;
    }
		// Xoa o dau
		void deleteFirst() {
			if(length==0) return;
			KH* temp=head;
			if(length==1) head=tail=nullptr;
			else {
				head=head->next;
				head->prev=nullptr;
			}
			delete temp;
			length--;
		}
		// Xoa o duoi
		void deleteLast() {
			if(length==0) return;
			KH* temp=tail;
			if(length==1) {
				head=nullptr;
				tail=nullptr;
			} else {
				tail=tail->prev;
				tail->next=nullptr;
			}
			delete temp;
			length--;
		}
		// Tim kiem theo STT
		CusInfo* get(int index) {
			if (index < 1 || index > length) return nullptr;
			KH* temp = head;
			for (int i = 1; i < index; i++) {
				temp = temp->next;
			}
			return temp;
		}
		// Tim kiem theo ID
		CusInfo* findID(int id) {
			KH* temp=head;
			while(temp) {
				if (temp->ID ==  id) {
					cout << "Found!" << endl;
					return temp;
				}
				temp=temp->next;
			}
			return temp;
		}
		// Tim kiem theo ten
		CusInfo* findName(string Name) {
			KH* temp=head;
			while(temp) {
				if (temp->name ==  Name) {
					cout << "Found!" << endl;
					return temp;
				}
				temp=temp->next;
			}
			return temp;
		}
		// Tim kiem theo SDT
		CusInfo* findTel(string Tel) {
			KH* temp=head;
			while(temp) {
				if (temp->tel ==  Tel) {
					cout << "Found!" << endl;
					return temp;
				}
				temp=temp->next;
			}
			return temp;
		}
		// Hien thi nhung khach hang co Rank xxx
		void findRank(string Rank) {
			KH* temp=head;
			int check=0;
			cout << setfill('-');
			cout << setw(115) << "-" << endl;
			while(temp) {
				if (temp->rank == Rank) {
					cout << setfill(' ');
					cout << setw(5) << left << " ";
					hienthongtin(temp);
					check = 1;
				}
				temp=temp->next;
			}
			if (check == 0) cout << "Khong ton tai Rank." << endl;
			cout << setfill('-');
			cout << setw(115) << "-" << endl;
		}
		// Sua thong tin theo ID
		void set(int id) {
			KH* temp=findID(id);
			if (temp == nullptr) {
				cout << "Khong tim thay khach hang co ID da nhap." << endl;
				return;
			}
			nhapthongtin(temp);
			updateRank(temp);
			cout << "Sua thanh cong!" << endl;
		}
		// Insert vi tri bat ki
		void insert(int index) {
			if (index < 1 || index > length+1) {
				cout << "Khong hop le." << endl;
				return;
			}
			if (index == 1) {
				prepend();
				cout << "DONE!" << endl;
				return;
			}
			if (index == length+1) {
				append();
				cout << "DONE!" << endl;
				return;
			}
			KH* newKH = new KH;
			nhapthongtin(newKH);
			updateRank(newKH);
			KH* temp = get(index - 1);
			newKH->next = temp->next;
			temp->next->prev = newKH;
			temp->next = newKH;
			newKH->prev=temp;
			length++;
			cout << "DONE!" << endl;
			return;
		}
		// Delete theo STT
		void deleteKH(int index) {
			if (index < 1 || index > length) {
				cout << "Khong hop le." << endl;
				return;
			}
			if (index == 1) {
				cout << "DONE!" << endl;
				return deleteFirst();
			}
			if (index == length) {
				cout << "DONE!" << endl;
				return deleteLast();
			}

			KH* before = get(index - 1);
			KH* temp = before->next;

			before->next = temp->next;
			temp->next->prev = before;
			delete temp;
			length--;
		}
		// Delete theo ten
		void deletename(string Name){
			KH* temp=findName(Name);
			if(temp == nullptr) {
				cout << "Khong tim thay khach hang." << endl;
				return;
			}
			if(temp->next==nullptr){
				deleteLast();
			}else if(temp->prev==nullptr){
				deleteFirst();
			}else{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				delete temp;
			}
			cout << "Xoa thong tin khach hang thanh cong ";
			length--;
		}
		// delete theo ID
		void deleteID(int ID){
			KH* temp = findID(ID);
			if(temp == nullptr) {
				cout << "Khong tim thay khach hang." << endl;
				return;
			}
			if(temp->next==nullptr){
				deleteLast();
			}else if(temp->prev==nullptr){
				deleteFirst();
			}else{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				delete temp;
			}
			cout << "Xoa thong tin khach hang thanh cong ";
			length--;
		}
		// delete theo SDT
		void deleteTel(string Tel){
			KH*temp=findTel(Tel);
			if(temp == nullptr) {
				cout << "Khong tim thay khach hang." << endl;
				return;
			}
			if(temp->next==nullptr){
				deleteLast();
			}else if(temp->prev==nullptr){
				deleteFirst();
			}else{
				temp->prev->next=temp->next;
				temp->next->prev=temp->prev;
				delete temp;
			}
			cout << "Xoa thong tin khach hang thanh cong ";
			length--;
		}
			// Ham add khach hang tu file
		void add(int ID, string name, string tel, string dob,long int pts,string rank) {
			KH* newKH= new KH;
			newKH->ID=ID;
			newKH->name=name;
			newKH->tel=tel;
			newKH->dob=dob;
			newKH->pts=pts;
			newKH->rank=rank;
			newKH->next=nullptr;
			newKH->prev=nullptr;
			if (length == 0) {
				head = newKH;
				tail = newKH;
			} else {
				tail->next = newKH;
				newKH->prev = tail;
				tail = newKH;
			}
			length++;
		}
		// Luu data vao file
		void savetofile() {
			ofstream save;
			save.open ("customer.txt", ios::out | ios::trunc);
			KH* temp=head;
			while(temp) {
				save << temp->ID << ",";
				save << temp->name << ",";
				save << temp->tel << ",";
				save << temp->dob << ",";
				save << temp->pts << ",";
				save << temp->rank << "," << endl;
				temp=temp->next;
			}
			save.close();
		}
		// Doc data tu file
		void readfile() {
			ifstream save("customer.txt");
			if(save.is_open()) {
				string line;
				while(getline(save, line)) {
					stringstream ss(line);
					string ID;
					string name;
					string tel;
					string dob;
					string pts;
					string rank;
					getline(ss, ID, ',');
					getline(ss, name, ',');
					getline(ss, tel, ',');
					getline(ss, dob, ',');
					getline(ss, pts, ',');
					getline(ss, rank, ',');
					add(stoi(ID),name,tel,dob,stoi(pts),rank);
				}
			}
		}
};



int main() {
	List* myList = new List();
	myList->readfile();
	cout << "----------Menu----------" << endl;
	cout << "[1] Them khach hang" << endl;
	cout << "[2] Them khach hang vao vi tri tu chon" << endl;
	cout << "[3] In danh sach khach hang" << endl;
	cout << "[4] Tim kiem khach hang" << endl;
	cout << "[5] Cap nhat diem" << endl;
	cout << "[6] Sap xep khach hang theo diem" << endl;
	cout << "[7] Sua thong tin khach hang" << endl;
	cout << "[8] Xoa khach hang" << endl;
	cout << "[0] Exit" << endl;
	int choice;
	while (1) {
		cout << "------------------------" << endl;
		cout << "[Nhap lua chon cua ban] ";
		cin >> choice;
		fflush(stdin);
		if (choice == 1) {
			myList->append();
			cout << "DONE!" << endl;
		}
		if (choice == 2) {
			cout << "Ban muon them vao dau? ";
			int index;
			cin >> index;
			myList->insert(index);
		}
		if (choice == 3) {
			myList->printList();
		}
		if (choice == 4) {
			cout << "\tTim kiem theo? " << endl << "[1] ID" << endl << "[2] Ten" << endl << "[3] SDT" << endl << "[4] Rank" << endl << "Chon: ";
			int choice2;
			cin >> choice2;
			fflush(stdin);
			if (choice2 == 1) {
				int id;
				cout << "Nhap ID can tim: ";
				cin >> id;
				KH* t = myList->findID(id);
				if (t == nullptr) {
					cout << "Khong tim thay ID." << endl;
				} else {
					cout << setfill('-');
					cout << setw(115) << "-" << endl;
					cout << "     ";
					hienthongtin(t);
					cout << setfill('-');
					cout << setw(115) << "-" << endl;
				}
			}
			if (choice2 == 2) {
				string name;
				cout << "Nhap ten can tim: ";
				getline(cin,name);
				KH* t = myList->findName(name);
				if (t == nullptr) {
					cout << "Khong tim thay ten." << endl;
				} else {
					cout << setfill('-');
					cout << setw(115) << "-" << endl;
					cout << "     ";
					hienthongtin(t);
					cout << setfill('-');
					cout << setw(115) << "-" << endl;
				}
			}
			if (choice2 == 3) {
				string tel;
				cout << "Nhap SDT can tim: ";
				getline(cin,tel);
				KH* t = myList->findTel(tel);
				if (t == nullptr) {
					cout << "Khong tim thay SDT." << endl;
				} else {
					cout << setfill('-');
					cout << setw(115) << "-" << endl;
					cout << "     ";
					hienthongtin(t);
					cout << setfill('-');
					cout << setw(115) << "-" << endl;
				}
			}
			if (choice2 == 4) {
				string rank;
				cout << "Nhap Rank can tim: ";
				cin >> rank;
				myList->findRank(rank);
			}
		}
		if (choice == 5) {
			int id;
			cout << "Nhap ID can tim: ";
			cin >> id;
			KH* t = myList->findID(id);
			if (t == nullptr) {
				cout << "Khong tim thay ID." << endl;
			} else {
				cout << "Diem cu: " << t->pts << ". Hay nhap diem moi: ";
				cin >> t->pts;
				myList->updateRank(t);
				cout << "Cap nhat thanh cong." << endl;
			}
		}
		if (choice == 6) {
			myList->Sort();
		}
		if (choice == 7) {
			int id;
			cout << "Nhap ID can sua: ";
			cin >> id;
			myList->set(id);
		}
		if (choice == 8) {
			cout << "\tXoa thong tin theo? " << endl << "[1] ID" << endl << "[2] Ten" << endl << "[3] SDT" << endl << "[4] Vi tri" << endl << "Chon: ";
			int chon;
			cin >> chon;
			fflush(stdin);
			if(chon==1){
				int ID;
				cout << "Nhap ID khach hang muon xoa: ";
				cin >> ID;
				myList->deleteID(ID);
			}
			if(chon==2){
				string Name;
				cout << "Nhap ten khach hang muon xoa: ";
				getline(cin,Name);
				myList->deletename(Name);
			}
			if(chon==3){
				string Tel;
				cout << "Nhap SDT khach hang muon xoa: ";
				getline(cin,Tel);
				myList->deleteTel(Tel);
			}
			if(chon==4){
				int index;
				cout << "Nhap STT khach hang muon xoa: ";
				cin >> index;
				myList->deleteKH(index);
			}
		}
		if (choice == 0) {
			myList->savetofile();
			cout << "Luu thanh cong." << endl;
			return 0;
		}
		if (choice < 0 || choice > 8) cout << "Khong hop le." << endl;
	}
}
