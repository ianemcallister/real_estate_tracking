// This program tracks houses served up by a real estate agent.
// Written by: Ian McAllister
// Date: 7/19/15
// Source: Class videos and C++ programming by D.S. Malik
// Notes: Utilized linked lists for both queue and stack models

#ifndef __project2__linkedqueue__
#define __project2__linkedqueue__

#include <stdio.h>
#include <iostream>
#include "data.h"

using namespace std;

class queue
{
public:
    //constructors
    queue();
    queue(char fileName[]);
    queue(const queue& listOfObjects);     //copy constructor
    //destructors
    ~queue();
    //accessors
    void display();
    bool isEmptyQueue();
    bool isFullQueue();
    void copyQueue(const queue& listOfObjects);
    
    //mutators
    bool enqueue(data& aHouse);
    bool dequeue(data& aHouse);
    void initializeQueue();
    //operator overloading
    const queue& operator=(const queue& listOfObjects);      //overloard assignment opperator
    
private:
    node * queueFront;
    node * queueRear;
    
};

#endif /* defined(__project2__linkedqueue__) */
