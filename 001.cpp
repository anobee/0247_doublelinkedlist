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

            if (START != NULL && newnode->nim == START->nim)
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
        
        newnode->next = current;
        newnode->prev = previous;
        
        if (current != NULL)

        {
            current->prev =newnode;
        }

        if (previous != NULL)
        {
            previous->next = newnode;
        }
        else
        {
            START = newnode;
        }
        
    }

}

    bool search (int rollNo, node **previous, node **current)
    {
        *previous = NULL;
        *current = START;
         while (*current != NULL && (*current)->nim != rollNo)
         {
            *previous = *current;
            *current = (*current)->next;

         }
         return (*current != NULL);
    }
    void deletenode()
    {
        node *previous, *current;
        int rollNo;

        cout << "\nEnter the roll number of the student whose record is to be deleted =";
        cin >> rollNo
        if (START==NULL)
        {
            cout << "list is empty" << endl;
            return;
        }
        current = START;
        previous =NULL;

        while (current != NULL && current->nim != rollNo)
        {
            previous = current;
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\033[31mThe record with roll number" << rollNo << "not found\033[0m]" << endl;
            return;
        }

        if (current == START)
        {
            START = START->next;
            if (START != NULL)
            {
                START->prev =NULL;
            }
        }
        else
        {
            previous->next = current->next;
            if (current->next != NULL)
            {
                current->next->prev = previous;
            }
        }

            delete current;
            cout << "\x1b[32mRecord with roll number" << rollNo << "deleted\x1b[0m"<< endl
    }

    bool listempty ()
        {
            return (START=NULL);
        }
   

    void traverse()
    {
        if (listempty())
        cout << "\nList is empty" << endl;
        else
        {
            cout << "\nRecors in ascending order of roll number are =" << endl;
            node *currentnode = START;
            while (currentnode != NULL)
            {
                cout << currentnode->nim << " " << currentnode << endl;
                currentnode = currentnode->next;
            }
        }
    }

    void retraverse()
    {
        if (listempty())
        cout << "\nList is Empty" << endl;
        else
        {
            cout << "\nRecord in descending order of roll number are =" << endl;
            node *currentnode = START;
            while (currentnode->next != NULL)
                currentnode = currentnode->next;
                while (currentnode != NULL)
                {
                    cout << currentnode->nim << " " << currentnode->name << endl;
                    currentnode = currentnode->prev;
                }
        }
    }