#include <iostream>
#include <string>
using namespace std;

struct node
{
    int nim;
    string name;
    node* next;
    node* prev;
};

node* START = NULL ;

void addnode () {
    node* newnode = new node() ; 
    cout << "\n Enter the roll number of student =";
    cin >> newnode -> nim ;
    cout << "\nEnter the name of the student = ";
    cin >> newnode->name;
}

