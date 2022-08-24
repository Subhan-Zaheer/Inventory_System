#include<iostream>
#include<string>
#include<cstring>
#include<list>

using namespace std; 

class Identity {
public:
	long int id;
	string name;

	Identity() {
		id = 0;
		name = "";
	}

	Identity(int id, string name) {
		this->id = id;
		this->name = name;
	}
};

class Customer : protected Identity {
public:
	long int phone_number;
	string address;
	Customer() {
		phone_number = 0;
		address = "";
	}
	Customer(int id, string name, int phone_number, string address):Identity(id, name) {
		this->phone_number = phone_number;
		this->address = address;
	}

};

class Product : public Identity {
public:
	string company_name; 
	int quantity;
	Product() {
		company_name = "";
		quantity = 0;
	}
	Product(int id, string name, string company_name):Identity(id, name) {
		this->company_name;
	}
	Product(int id, int quantity,  string name, string company_name):Identity(id, name) {
		this->company_name = company_name;
		this->quantity = quantity;
	}
};

class Order: protected Product {
public:
	long double order_price;
	string* order_item;
	int length_of_list_of_item;
	Order() {
		order_price = 0.0;
		order_item = nullptr;
		length_of_list_of_item = 0;
	}
	Order(int id, long double order_price, string* order_item, int length_of_list_of_item):Product(id, "", "") {
		this->order_price = order_price;
		this->length_of_list_of_item = length_of_list_of_item;
		this->order_item = new string[length_of_list_of_item];
		for (int i = 0; i < length_of_list_of_item; i++) {
			cout << "Enter name of " << i + 1 << " item in order list : ";
			string item = "";
			getline(cin, item);
			this->order_item[i] = item;

		}
	}
};


class Inventory {
public:
	list<Product> l1;
	Product p;
	int add_item(int id, string name, int quantity, string company_name) {
		p.id = id;
		p.quantity = quantity;
		p.name = name;
		p.company_name = company_name;
		l1.push_back(p);
	}
	int del_item(string name, int quantity) {
		for (int i = 0; i < l1.size(); i++) {
			;
		}
	}

};

class Functionality {
public:
	void Func() {
		cout << "Enter 1 for Customer : ";
	}
};

int main() {
	return 0;
}