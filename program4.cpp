#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

struct Car {
	string make;
	string model;
	string year;
	string color;
	Car *next;
};

struct List
{
	// First car in the list. A value equal to NULL indicates that the
	// list is empty.
	Car *head;
	// Current car in the list. A value equal to NULL indicates a
	// past-the-end position.
	Car *current;
	// Pointer to the element appearing before 'current'. It can be NULL if
	// 'current' is NULL, or if 'current' is the first element in the list.
	Car *previous;
	// Number of cars in the list
	int count;
};

void insert_linkedList(List *list);
void ListInitialize(List *list);
void print_cars_list(List *list);
void sort_cars_by_color(List *list);
void print_duplicates(List *list);

//Create a linked list node with the car fields and a pointer.
//Provide a similar menu as the one used above with the necessary modifications to reflect the tasks
//below. Do not use arrays at any point in this program. Your linked list should be created in the main
//function and passed to other functions. It should not be global!
int main(){
	List list;				// Create the main list
	ListInitialize(&list);			// Initialize the list
	int option =0;
	while(option != 5)
	{
		cout << "------------------------------" << endl;
		cout << "Main menu: " << endl << endl;
		cout << "1. Print the cars list" << endl;
		cout << "2. Insert car records into a sorted list" << endl;
		cout << "3. Sort cars by year" << endl;
		cout << "4. Print duplicates" << endl;
		cout << "5. Exit" << endl;
		cout << "Select an option: ";
		cin >> option;
		cout << endl;
		switch(option){
			case 1 :
				print_cars_list(&list);
				break;
			case 2 : // insert car records into a sorted array
				insert_linkedList(&list);
				break;
			case 3 :
				sort_cars_by_color(&list);
				break;
			case 4 :
				print_duplicates(&list);
				break;
			case 5 :
				return 0;
				break;
			default :
				cout << "ERROR: option is invalid. Please select a valid option from the menu." << endl << endl;
				break;

		}
	}
}

void ListInsert(List *list, Car *car)
{
	// Set 'next' pointer of current element
	car->next = list->current;
	// Set 'next' pointer of previous element. Treat the special case where
	// the current element was the head of the list.
	if (list->current == list->head)
		list->head = car;
	else
		list->previous->next = car;
	// Set the current element to the new person
	list->current = car;
	list->count++;
}

void ListNext(List *list)
{
	if (list->current)
	{
		list->previous = list->current;
		list->current = list->current->next;
	}
}
// Move the current position to the first element in the list.
void ListHead(List *list)
{
	list->previous = NULL;
	list->current = list->head;
}

void ListInitialize(List *list)
{
	list->head = NULL;
	list->current = NULL;
	list->previous = NULL;
	list->count = 0;
}

void PrintCar(Car *car)
{
	cout << "Car make: " << car->make << endl;
	cout << "Car model: " << car->model << endl;
	cout << "Car year: " << car->year << endl;
	cout << "Car color: " << car->color << endl << endl;

}

// reads the 10 records from the file into a linked list.
void insert_linkedList(List *list){
	ifstream infile;
	string x, user_file = "CarRecords.txt";
	infile.open(user_file.c_str());
	// tests if the file opens correctly
	if(!infile)
	{
		exit(0);
	}
	// input file CarRecords.txt
	// reads the data into a matrix in the main program
	int count = 1;
	struct Car *cars;

	while(infile >> x)
	{
		switch(count) {
			case 1 : 
				cars = new Car;
				cars->make = x;
				count++;
				break;
			case 2 : 
				cars->model = x;
				count++;
				break;
			case 3 : 
				cars->year = x;
				count++;
				break;
			case 4 : 
				cars->color = x;
				ListInsert(list, cars);
				count = 1;
				break;
		}
	}
	infile.close();
}


//b.) Provide a function print_cars_list( ) that prints out the car records in the linked list.
void print_cars_list(List *list){
	ListHead(list);  // sets current to head
	PrintCar((list)->current); // prints current
	for(int i=1; i<list->count; i++){ // sets current to next and prints new current
		ListNext(list);
		PrintCar((list)->current);	
	}
}

void swap(struct Car *first, struct Car *second, struct Car *temp, struct Car *firstprev, struct Car *secondprev, List *list){
	if (first != NULL && second != NULL){
		string color = first->next->color;
		first->next = second->next;
		
		if(color == second->color){
			second->next = first;
		}
		else
		{
			second->next = temp;
		
			if(secondprev != NULL){
				secondprev->next = first;
			}
		}

		if(firstprev != NULL){
			firstprev->next = second;
		}
		else
		{
			list->head = second;
			list->previous = NULL;
		}
	}
	else
	{
		cout << "first or second was null!!" << endl;

	}

}

//c.) Provide a function sort_cars_by_color( ) that sorts the records in ascending order
////based on the color field. The sorting should be done by pointer manipulation.
void sort_cars_by_color(List *list){
	struct Car *first;
	struct Car *second;
	struct Car *temp;
	struct Car *firstprev;
	struct Car *secondprev;

	for(int i=0; i<list->count; i++)
	{
		ListHead(list);
		if(i>0){
			for(int k=1; k<=i; k++){
				ListNext(list);
			}
		}

		first = list->current;
		firstprev = list->previous;
		temp = first->next;
		string min = list->current->color;
		second = list->current;
		
		for(int j=i; j<list->count; j++)
		{
			if (list->current->color<min)
			{
				min=list->current->color;
				second = list->current;
				secondprev = list->previous;
			}
			ListNext(list);
		}
		if(first->color != second->color){
			swap(first, second, temp, firstprev, secondprev, list);
		}
	}	

}

//d.) Provide a function print_duplicates( ) that identifies any repeated records, and prints
////them out when found. Repeated records means that all the fields are the same
//void print_duplicates(List *list);
//
void print_duplicates(List *list){
	ListHead(list);	
    	sort_cars_by_color(list);
	for(int i=0; i<(list->count-1); i++){
		if(list->current->year == list->current->next->year){
			if(list->current->make == list->current->next->make && list->current->model == list->current->next->model && list->current->year == list->current->next->year){
				cout << "DUPLICATES FOUND: " << endl;
				cout << "---" << endl;
				cout << "Car make: " << list->current->make << endl;
				cout << "Car model: " << list->current->model << endl;
				cout << "Car year: " << list->current->year << endl;
				cout << "Car color: " << list->current->color << endl;
				cout << "AND" << endl;
				cout << "Car make: " << list->current->next->make << endl;
				cout << "Car model: " << list->current->next->model << endl;
				cout << "Car year: " << list->current->next->year << endl;
				cout << "Car color: " << list->current->next->color << endl;
				cout << "---" << endl;
			}
		}
		ListNext(list);
	}	
}
