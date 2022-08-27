#include<iostream>
#include<string>
#include<cstring>

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
			return 0;

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
			return 0;

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
			return 1;

		}
	}

	int list_size() {
		int size = 0;
		if (head == NULL) {
			return 0;
		}
		else {
			node* temp = head;
			while (temp->next != NULL) {
				size++;
				temp = temp->next;
			}
			size++;
			return size;
		}
	}

	void display_total_items() {
		if (head == NULL) {
			cout << "Link List is empty. There is nothing to show you here." << endl;
		}
		else {
			node* temp = head;
			while (temp->next != NULL) {
				cout << "ID : " << temp->data.id << endl;
				cout << "Product Name : " << temp->data.name << endl;
				cout << "Price of Product" << temp->data.price << endl;
				cout << "Company Name : " << temp->data.company_name << endl;
				cout << "Quantity of Product : " << temp->data.quantity << endl;
				cout << "-----------------------------------------------" << endl;
			}
			cout << "ID : " << temp->data.id << endl;
			cout << "Product Name : " << temp->data.name << endl;
			cout << "Price of Product" << temp->data.price << endl;
			cout << "Company Name : " << temp->data.company_name << endl;
			cout << "Quantity of Product : " << temp->data.quantity << endl;
			cout << "-----------------------------------------------" << endl;
		}
	}

	Product select_Product(string name, string company_name) {
		if (head == NULL) {
			cout << "Stock List is empty. Nothing to select from it." << endl;
			return;
		}
		else {
			node* temp = head;
			bool found_item = false;
			while (temp->next != NULL) {
				if (temp->data.name == name && temp->data.company_name == company_name) {
					Product p;
					p.company_name = temp->data.company_name;
					p.id = temp->data.id;
					p.name = temp->data.name;
					p.price = temp->data.price;
					p.quantity = temp->data.quantity;
					found_item = true;
					return p;
				}
			}
			if (found_item == false) {
				cout << "Your product is not in Inventory List." << endl;
				return;
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
	void display() {
		cout << "ID is : " << this->id << endl;
		cout << "Name is : " << this->name << endl;
	}
};

class Customer : public Identity {
public:
	string phone_number;
	string address;
	Customer() {
		phone_number = "";
		address = "";
	}
	Customer(int id, string name, string phone_number, string address):Identity(id, name) {
		this->phone_number = phone_number;
		this->address = address;
	}
	void display() {
		cout << "ID of this Customer is : " << this->id << endl;
		cout << "Name of this Customer is : " << this->name << endl;
		cout << "Address of this Customer is : " << this->address << endl;
		cout << "Contact of this Customer is : " << this->phone_number << endl;
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
	LinkedList l1;
	int add_item(int id, string name, int quantity, string company_name, long float price) {

		Product p;
		p = Product(id, quantity, name, company_name, price);
		l1.insertItem(p);
	}
	int del_item(int id, string name) {
		return l1.delete_Item(id, name);
		
	}

	int update(int id, string name) {
		return l1.update_item(id, name);
		
	}

	void display_inventory() {
		l1.display_total_items();
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
	void place_order() {
		int id_of_Order;
		cout << "Enter id of Order : " << endl;
		cin >> id_of_Order;
		cout << "Enter items of your order : " << endl;
		while (true) {
			cout << "Enter 1 if you have done with your items otherwise Enter 0 : ";
			int choice;
			cin >> choice;
			if (choice == 0) {
				return;
			}
			else {
				string product_Name = "", company_name="";
				Inventory stock_list;
				cout << "Enter Product Name : ";
				getline(cin, product_Name);
				cout << "Enter Company Name : ";
				getline(cin, company_name);
				stock_list.

			}
		}



	}
};



class Functionality {
public:
	void Func() {
		cout << "Enter 1 for add Customer : ";
	}
};

int main() {
	Identity* id;
	Customer c;
	id = &c;
	return 1;
}