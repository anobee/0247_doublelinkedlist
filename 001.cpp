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

        if (START == NULL || newnode->nim <= START->nim)
        {
            cout << "\033[31mDulplicate roll numbers not allowed \033]0m" << endl;
            return;
        }
        newnode->next = START;
        if (START != NUll) {
            START->prev = newnode;
        }
        newnode->prev = NULL;
        START = newnode;
}

    else
    {
        node *current = START;
        node *previous = NULL;

        while (current != NULL && current->mhs < newnode->nim)
        {
            previous = current;
            current = current->next;
        }
        
        
    }


