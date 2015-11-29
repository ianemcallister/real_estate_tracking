// This program tracks houses served up by a real estate agent.
// Written by: Ian McAllister
// Date: 7/19/15
// Source: Class videos and C++ programming by D.S. Malik
// Notes: Utilized linked lists for both queue and stack models

#ifndef __project2__linkedstack__
#define __project2__linkedstack__

#include <stdio.h>
#include <iostream>
#include "data.h"

class stack
{
public:
    //constructors
    stack();
    stack(const stack& listOfObjects);     //copy constructor
    //destructors
    ~stack();
    //accessors
    void display();
    bool isEmptyStack();
    bool isFullStack();
    void copyStack(const stack& listOfObjects);
    //mutators
    bool push(data& aHouse);
    bool pop(data& aHouse);
    void initializeStack();
    
    //operator overloading
    const stack& operator=(const stack& listOfObjects);      //overloard assignment opperator
    
private:
    node * top;
};

#endif /* defined(__project2__linkedstack__) */
