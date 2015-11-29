// This program tracks houses served up by a real estate agent.
// Written by: Ian McAllister
// Date: 7/19/15
// Source: Class videos and C++ programming by D.S. Malik
// Notes: Utilized linked lists for both queue and stack models

#include "linkedqueue.h"

//constructors
queue::queue() :queueFront(NULL), queueRear(NULL)
{
}

queue::queue(char fileName[]) :queueFront(NULL), queueRear(NULL)
{
    //declare and initialize local variables
    ifstream inFile;
    data aHouse;
    char tempAddress[MAX_CHAR] = { '\0' };
    char tempDescription[MAX_CHAR] = { '\0' };
    int tempFootage = 0;
    int tempBedrooms = 0;
    float tempBathrooms = 0.0;
    
    //open file
    inFile.open(fileName);
    if(!inFile)
    {
        inFile.clear();
        cout << endl << "Failed to open " << fileName << " for input!" << endl << endl;
        exit(1);
    }
    
    //load file data into member variables, name first
    inFile.get(tempAddress, MAX_CHAR, ';');
    
    //loop through file until all data is read
    while (!inFile.eof())
    {
        //clear buffer
        inFile.ignore(10, ';');
        //then location
        inFile.get(tempDescription, MAX_CHAR, ';');
        //clear buffer
        inFile.ignore(10, ';');
        //then year
        inFile>>tempFootage;
        //clear buffer
        inFile.ignore(10, ';');
        //then acres
        inFile>>tempBedrooms;
        //clear buffer
        inFile.ignore(10, ';');
        //then rating
        inFile>>tempBathrooms;
        //clear buffer
        inFile.ignore(10, '\n');
        
        //load all temp values in to place holder object
        aHouse.setAddress(tempAddress);
        aHouse.setDescription(tempDescription);
        aHouse.setFootage(tempFootage);
        aHouse.setBedrooms(tempBedrooms);
        aHouse.setBathrooms(tempBathrooms);
        
        //add task to list
        enqueue(aHouse);
        
        //start next record
        inFile.get(tempAddress, MAX_CHAR, ';');
    } //out of loop
    
    //close the resource file
    inFile.close();
}

queue::queue(const queue& listOfObjects)     //copy constructor
{
    queueFront = NULL;
    queueRear = NULL;
    copyQueue(listOfObjects);
}

//destructors
queue::~queue()
{
    if(queueFront)
    {
        delete queueFront;
        queueFront = NULL;
    }
    if(queueRear)
    {
        delete queueRear;
        queueRear = NULL;
    }
}

//accessors
void queue::display()
{
    //declare and initialize local variables
    node * curr = NULL;
    
    //iterate through nodes, printing them to the screen
    for(curr = queueFront; curr != NULL; curr = curr -> next)
    {
        cout << curr -> house << endl;
    }
}

bool queue::isEmptyQueue()
{
    //if at least one node exists return true
    return (queueFront == NULL);
}

bool queue::isFullQueue()
{
    //this will always be false while using linked lists
    return false;
}

void queue::copyQueue(const queue& listOfObjects)
{
    //declare and initialize local variables
    node * newNode, * curr, * last;
    
    //if the stak is not empty, make it empty
    if(queueFront != NULL)
        initializeQueue();
    
    if(listOfObjects.queueFront == NULL)
        queueFront = NULL;
    else
    {
        //set the current pointer to point to the stack to be copied
        curr = listOfObjects.queueFront;
        
        //copy the top element, create the node
        queueFront = new node;
        
        //copy the info
        queueFront -> house = curr -> house;
        
        //set the link to NULL
        queueFront -> next = NULL;
        
        //set last to point to the node
        last = queueFront;
        
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
bool queue::enqueue(data& aHouse)
{
    //declare & initialize local variables
    node * newNode = NULL;
    newNode = new node;
    
    //populate new node
    newNode -> house = aHouse;
    newNode -> next = NULL;
    
    //add node to queue
    if(queueFront == NULL)
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else
    {
        queueRear->next = newNode;
        queueRear = queueRear -> next;
    }
    
    return true;
}

bool queue::dequeue(data& aHouse)
{
    node * temp = NULL;
    
    if(!isEmptyQueue())
    {
        //point temp to the first node
        temp = queueFront;
        aHouse = temp->house;
        
        //advance the queueFront
        queueFront = queueFront->next;
        
        //delete the first node
        delete temp;
        
        //if the queue is now empty, set the queueRear to NULL
        if(queueFront == NULL)
            queueRear = NULL;
    }
    else
        return false;
    
    return true;
}

void queue::initializeQueue()
{
    //declare and initialize local variables
    node * temp;
    
    while(queueFront != NULL)
    {
        //set temp to point to the current node
        temp = queueFront;
        
        //advance first to the next node
        queueFront = queueFront -> next;
        
        //deallocate memory occupied at temp
        delete temp;
    }
}

//operator overloading
const queue& queue::operator=(const queue& listOfObjects)
{
    if(this != &listOfObjects)
        copyQueue(listOfObjects);
    
    return *this;
}