// This program tracks houses served up by a real estate agent.
// Written by: Ian McAllister
// Date: 7/19/15
// Source: Class videos and C++ programming by D.S. Malik
// Notes: Utilized linked lists for both queue and stack models

#include "linkedstack.h"

//constructors
stack::stack() :top(NULL)
{
}

stack::stack(const stack& listOfObjects) :top(NULL)
{
    top = NULL;
    copyStack(listOfObjects);
}

//destructors
stack::~stack()
{
    if(top)
    {
        delete top;
        top = NULL;
    }
}

//accessors
void stack::display()
{
    //declare and initialize local variables
    node * curr = NULL;
    
    //iterate throught he nodes, printing to the screen
    for(curr = top; curr != NULL; curr = curr -> next)
    {
        cout << curr -> house << endl;
    }
}

bool stack::isEmptyStack()
{
    //if at least one node exists the list is not empty
    return (top == NULL);
}

bool stack::isFullStack()
{
    //useing nodes this will always be false
    return false;
}

void stack::copyStack(const stack& listOfObjects)
{
    //declare and initialize local variables
    node * newNode, * curr, * last;
    
    //if the stak is not empty, make it empty
    if(top != NULL)
        initializeStack();
    
    if(listOfObjects.top == NULL)
        top = NULL;
    else
    {
        //set the current pointer to point to the stack to be copied
        curr = listOfObjects.top;
        
        //copy the top element, create the node
        top = new node;
        
        //copy the info
        top -> house = curr -> house;
        
        //set the link to NULL
        top -> next = NULL;
        
        //set last to point to the node
        last = top;
        
        //set current to point to the next node
        curr = curr -> next;
        
        //cop the remaining stack
        while (curr != NULL)
        {
            newNode = new node;
            
            newNode -> house = curr-> house;
            newNode -> next = NULL;
            last -> next = newNode;
            last = newNode;
            curr = curr -> next;
        }
    }
}

//mutators
bool stack::push(data& aHouse)
{
    //declare and initialize local variables
    node * newNode;
    
    //dynamically create a new node
    newNode = new node;
    
    //store aHouse in the node
    newNode -> house = aHouse;
    newNode -> next = top;
    top = newNode;
    return true;
}

bool stack::pop(data& aHouse)
{
    //declare and initialize local variables
    node * temp;
    
    if(top != NULL)
    {
        temp = top;
        aHouse = temp -> house;
        top = top -> next;
        delete temp;
    }
    else
        return false;
    
    return true;
}

void stack::initializeStack()
{
    //declare & initialize local variables
    node * temp;
    
    while(top != NULL)
    {
        temp = top;
        top = top->next;
        delete temp;
    }
}

//operator overloading
const stack& stack::operator=(const stack& listOfObjects)
{
    if(this != &listOfObjects)
        copyStack(listOfObjects);
    
    return *this;
}