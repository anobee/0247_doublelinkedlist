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
