#include<iostream>
#include<string>
#include<cstring>
#include<list>

using namespace std; 

class node {
public:
	Product data;
	node* next;
	node() {
		data = Product(0, 0, "", "", 0.0);
		next = NULL;
	}
};

class LinkedList {
	node* head;
public:
	LinkedList() {
		head = NULL;
	}
	node* create_New_Node(Product data) {
		node* newNode = new node;
		newNode->data = data;
		return newNode;
	}
	int insertItem(Product data) {
		node* newNode = create_New_Node(data);
		if (head == NULL) {
			head = newNode;
		}
		else {
			node* temp_node = head;
			while (temp_node->next != NULL) {
				temp_node = temp_node->next;
			}
			temp_node->next = newNode;
		}
		return 1;
	}
	int delete_Item(int id, string name) {
		if (head == NULL) {
			cout << "Link list is empty there is nothing to delete in it.";

		}
		else {
			node* temp_node = head;
			// Tranversing pointer node->next-next to easily delete the desired item and to connect the prev and next node easily.
			while (temp_node->next->next != NULL) {
				if (temp_node->next->data.id == id && temp_node->next->data.name == name) {
					break;
				}
				temp_node = temp_node->next;
			}
			node* node_to_del = temp_node;
			temp_node = temp_node->next->next;
			delete node_to_del;

		}
		return 1;
	}

	int update_item(int id, string name) {
		if (head == NULL) {
			cout << "Link list is empty there is nothing to delete in it.";

		}
		else {
			node* temp_node = head;
			// Tranversing pointer node->next-next to easily delete the desired item and to connect the prev and next node easily.
			while (temp_node->next->next != NULL) {
				if (temp_node->next->data.id == id && temp_node->next->data.name == name) {
					break;
				}
				temp_node = temp_node->next;
			}
			cout << "Enter 1 if you want to update the id of the product." << endl;
			cout << "Enter 2 if you want to update the name of the product. " << endl;
			cout << "Enter 3 if you want to update Company name of the product. " << endl;
			cout << "Enter 4 if you want to update the quantity of the product. " << endl;
			cout << "Enter 5 if you want to update the price of the product. " << endl;
			int choice = 0;
			cout << "Enter your choice here : ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter updated id of the product : ";
				int id;
				cin >> id;
				temp_node->data.name = name;
				break;
			case 2:
				temp_node->data.name = "";
				cout << "Enter updated name of the product : ";
				cin >> temp_node->data.name;
				break;
			case 3:
				temp_node->data.company_name = "";
				cout << "Enter the updated Company Name of product : ";
				cin >> temp_node->data.company_name;
				break;
			case 4:
				cout << "Enter the updated quantity of Product : ";
				temp_node->data.quantity = 0;
				cin >> temp_node->data.quantity;
				break;
			case 5:
				cout << "Enter the updated price of Product : ";
				cin >> temp_node->data.price;
			default:
				break;
			}

		}
	}



};

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

class Customer : public Identity {
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
	void display() {

	}

};

class Product : public Identity {
public:
	string company_name; 
	int quantity;
	long float price;
	Product() {
		company_name = "";
		quantity = 0;
		price = 0.0;
	}
	Product(int id, string name, string company_name):Identity(id, name) {
		this->company_name;
	}
	Product(int id, int quantity,  string name, string company_name, long float price):Identity(id, name) {
		this->company_name = company_name;
		this->quantity = quantity;
		this->price = price;
	}
};
class Inventory {
public:
	list<Product> l1;
	int add_item(int id, string name, int quantity, string company_name, long float price) {

		Product p;
		p = Product(id, quantity, name, company_name, price);
		l1.push_back(p);
	}
	int del_item(string name) {
		for (int i = 0; i < l1.size(); i++) {
			Product temp;
			l1.front();
		}
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



class Functionality {
public:
	void Func() {
		cout << "Enter 1 for Customer : ";
	}
};

int main() {
	Identity* id;
	Customer c;
	id = &c;
	return 1;
}