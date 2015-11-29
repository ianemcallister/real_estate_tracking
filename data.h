// This program tracks houses served up by a real estate agent.
// Written by: Ian McAllister
// Date: 7/19/15
// Source: Class videos and C++ programming by D.S. Malik
// Notes: Utilized linked lists for both queue and stack models

#ifndef __project2__data__
#define __project2__data__

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iomanip>
#include <fstream>

const int MAX_CHAR = 301;

using namespace std;

class data
{
public:
    //constructor
    data();
    data(const data& aHouse);       //copy constructor
    //destructor
    ~data();
    //accessor
    void getAddress(char * address) const;
    void getdescription(char * description) const;
    int getFootage();
    int getBedrooms();
    float getBathrooms();
    
    //mutator
    void setAddress(const char * address);
    void setDescription(const char * description);
    void setFootage(const int footage);
    void setBedrooms(const int bedrooms);
    void setBathrooms(const float bathrooms);
    
    //operator overloading
    friend ostream& operator<< (ostream& out, const data& aHouse);
    const data& operator=(const data& aHouse);      //overloard assignment opperator
    
private:
    char * address;
    char * description;
    int footage;
    int bedrooms;
    float bathrooms;
};


struct node
{
    data house;
    node * next;
};

#endif /* defined(__project2__data__) */
