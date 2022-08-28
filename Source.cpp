#include<iostream>
#include<string>
#include<cstring>
#include<list>
#include<time.h>
#include<cstdlib>

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
	int insertItem(Product new_data) {
		node* newNode = create_New_Node(new_data);
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
				cout << "Price of Product : " << temp->data.price << endl;
				cout << "Company Name : " << temp->data.company_name << endl;
				cout << "Quantity of Product : " << temp->data.quantity << endl;
				cout << "-----------------------------------------------" << endl;
				temp = temp->next;
			}
			cout << "ID : " << temp->data.id << endl;
			cout << "Product Name : " << temp->data.name << endl;
			cout << "Price of Product" << temp->data.price << endl;
			cout << "Company Name : " << temp->data.company_name << endl;
			cout << "Quantity of Product : " << temp->data.quantity << endl;
			cout << "-----------------------------------------------" << endl;
		}
	}

	Product select_Product(string name, string company_name, int quantity) {
		if (head == NULL) {
			cout << "Stock List is empty. Nothing to select from it." << endl;
			return Product(0, 0,"", "", 0.0);
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
					temp->data.quantity -= quantity;
					return p;
				}
				temp = temp->next;
			}
			if (found_item == false) {
				cout << "Your product is not in Inventory List." << endl;
				return Product(0, 0, "", "", 0.0);;
			}
		}
	}

	Product get_Item() {
		
	}



};

class Inventory {
public:
	LinkedList l1;
	int add_item(int id, string name, int quantity, string company_name, long float price) {

		Product p;
		p = Product(id, quantity, name, company_name, price);
		l1.insertItem(p);
		return 1;
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

	Product select_product_to_buy(string name, string company_name, int quantity) {
		return l1.select_Product(name, company_name, quantity);
	}

	
}stock_List;


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

	void create_invoice(list<Product> orders_list) {
		list<Product> l1 = orders_list;
		double total_bill = 0.0;
		if (orders_list.size() == 0) {
			cout << "List is empty. We cannot generate any invoice." << endl;
		}
		else {
			cout << endl;
			cout << "---------------HAMZA MART---------------" << endl;
			while (!(l1.empty())) {
				Product p;
				p = l1.front();
				l1.pop_front();
				total_bill += p.price;
				cout << p.name << "     " << p.company_name << "     :     " << p.price << endl;
			}
			cout << endl << "Total Bill is :  " << total_bill << endl;

		}
	}

	void place_order() {
		srand(time(NULL));
		int id_of_Order;
		id_of_Order = rand();
		cout << "Enter items of your order : " << endl;
		//LinkedList listfor_items_in_placing_order;
		//Product* array_for_storing_orderList;
		list<Product> listfor_items_in_placing_order;
		while (true) {
			int size_of_orderList = 0;
			cout << "Enter 1 if you have done with your items otherwise Enter 0 : ";
			int choice;
			cin >> choice;
			cin.ignore();
			if (choice == 1) {
				break;
			}
			else {
				string product_Name = "", company_name="";
				int quantity_of_Product = 0;
				Product product;
				cout << "Enter Product Name : ";
				getline(cin, product_Name);
				cout << "Enter Company Name : ";
				getline(cin, company_name);
				cin.ignore();
				cout << "Enter quantity of this product you want : " << endl;
				cin >> quantity_of_Product;
				product = stock_List.select_product_to_buy(product_Name, company_name, quantity_of_Product);
				//array_for_storing_orderList = new Product[++size_of_orderList];
				listfor_items_in_placing_order.push_back(product);
				
			}
		}
		create_invoice(listfor_items_in_placing_order);



	}
};



class Functionality_ofcode {
public:
	void add_stock_item_inList() {
		srand(time(NULL));
		int id = 0, quantity = 0;
		string name = "";
		string company_name = "";
		long float price = 0.0;
		id = rand();
		cout << "Enter name of Product : ";
		getline(cin, name);
		cout << "Enter the company name for the product : ";
		getline(cin, company_name);
		cin.ignore();
		cout << "Enter the quantity of the product : ";
		cin >> quantity;
		cout << "Enter the price of the product : ";
		cin >> price;
		stock_List.add_item(id, name, quantity, company_name, price);

	}

	void placing_the_order() {
		Order order;
		order.place_order();
	}

	void Func() {
		int choice = 0;
		cout << "Enter 1 to add Item in Stock List : " << endl;
		cout << "Enter 2 to place the order : " << endl;
		cout << "Enter 3 if you want to see your full inventory list : " << endl;
		cin >> choice;
		cin.ignore();
		if (choice == 1) {
			add_stock_item_inList();
		}
		else if (choice == 2) {
			placing_the_order();
		}
		else if (choice == 3) {
			stock_List.display_inventory();
		}
	}
};

int main() {
	Functionality_ofcode work;
	int exit_or_not;
	do {
		cout << "Enter 0 for exit, otherwise enter any number to continue : ";
		cin >> exit_or_not;
		cin.ignore();
		if (exit_or_not == 0) {
			exit(0);
		}
		work.Func();
	} while (exit_or_not != 0);
	return 1;
}