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

void addnode() {
    node* newnode = new node() ; 
    cout << "\n Enter the roll number of student =";
    cin >> newnode -> nim ;
    cout << "\nEnter the name of the student = ";
    cin >> newnode->name;

        if (START == NULL || newnode->nim <= START->nim)

        {

            if (START != NULL && newnode->nim == START->nim)
            {
                cout << "\033[31mDulplicate roll numbers not allowed \033[0m" << endl;
                return;
            }
            newnode->next = START;
            if (START != NULL) {
                START->prev = newnode;
            }
            newnode->prev = NULL;
            START = newnode;
        }
         else
    {
        node *current = START;
        node *previous = NULL;

        while (current != NULL && current->nim < newnode->nim)
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
        cin >> rollNo;
        if (START == NULL)
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
            cout << "\033[31mThe record with roll number" << rollNo << "not found\033[0m" << endl;
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
            cout << "\x1b[32mRecord with roll number" << rollNo << "deleted\x1b[0m"<< endl;
    }

    bool listempty ()
        {
            return (START == NULL);
        }
   

    void traverse()
    {
        if (listempty())
        cout << "\nList is empty" << endl;
        else
        {
            cout << "\nRecors in ascending order of roll number are :" << endl;
            node *currentnode = START;
            while (currentnode != NULL)
            {
                cout << currentnode->nim << " " << currentnode->name << endl;
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
            cout << "\nRecord in descending order of roll number are :" << endl;
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

    void searchdata()
    {
        if (listempty()== true)
        {
            cout << "\nlist is empty" << endl;
        }
        node *prev, *curr;
        prev = curr = NULL;
        cout << "\nEnter the roll number of the student whose record you want to search =";
        int num;
        cin >> num;
        if (search (num, &prev, &curr)== false)
            cout << "\nrecord not found" << endl;
        else
        {
            cout << "\nRecord found" << endl;
            cout << "\nRoll number =" <<curr->nim << endl;
            cout << "\nname =" << curr->name << endl;
        }
    }

    int main()
    {
        while (true)
        {
            try
            {
                cout << "\nMenu" << endl;
                cout << "1. add a record to the list" << endl;
                cout << "2. delete a record from the list" << endl;
                cout << "3  view all records in the ascending oreder of roll numbers" << endl;
                cout << "4. view all records in the descending order of roll numbers" << endl;
                cout << "5. search for a record in the list" << endl;
                cout << "6. exit"<< endl;
                cout << "\nEnter your choice 1-6 =";
                char ch;
                cin >> ch;
            
                switch (ch)
                {
                    case '1':
                        addnode();
                        break;
                    case '2':
                        deletenode();
                        break;
                    case '3':
                        traverse();
                        break;
                    case '4':
                        retraverse();
                        break;
                    case '5':
                        searchdata();
                        break;
                    case '6':
                        return 0;
                    default:
                        cout << "\nInvalid option" << endl;
                        break;
                    
                }
            }
            catch (exception &e)
            {
                cout << "check for the values entered." << endl;
            }
            
        }
    }