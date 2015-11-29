// This program tracks houses served up by a real estate agent.
// Written by: Ian McAllister
// Date: 7/19/15
// Source: Class videos and C++ programming by D.S. Malik
// Notes: Utilized linked lists for both queue and stack models

#include "data.h"

//constructor
data::data() :address(NULL), description(NULL), footage(0), bedrooms(0), bathrooms(0.0)
{
}

data::data(const data& aHouse) :address(NULL), description(NULL), footage(0), bedrooms(0), bathrooms(0.0)
{
    setAddress(aHouse.address);
    setDescription(aHouse.description);
    setFootage(aHouse.footage);
    setBedrooms(aHouse.bedrooms);
    setBathrooms(aHouse.bathrooms);
}

//destructor
data::~data()
{
    if(address)
    {
        delete [] address;
        address = NULL;
    }
    if(description)
    {
        delete [] description;
        description = NULL;
    }
}

//accessor
void data::getAddress(char * address) const
{
    strcpy(address, this->address);
}

void data::getdescription(char * description) const
{
    strcpy(description, this->description);
}

int data::getFootage()
{
    return footage;
}

int data::getBedrooms()
{
    return bedrooms;
}

float data::getBathrooms()
{
    return bathrooms;
}

//mutator
void data::setAddress(const char * address)
{
    //release the existing memory if there is any
    if(this -> address)
    {
        delete [] this -> address;
        this -> address = NULL;
    }
    
    
    //set new address
    this -> address = new char[strlen(address + 1)];
    strcpy(this -> address, address);
}

void data::setDescription(const char * description)
{
    //release the existing memory if there is any
    if(this -> description)
        delete [] this -> description;
    
    //set new address
    this -> description = new char[strlen(description + 1)];
    strcpy(this -> description, description);
}

void data::setFootage(const int footage)
{
    this -> footage = footage;
}

void data::setBedrooms(const int bedrooms)
{
    this -> bedrooms = bedrooms;
}

void data::setBathrooms(const float bathrooms)
{
    this -> bathrooms = bathrooms;
}

//operator overloading
ostream& operator<< (ostream& out, const data& aHouse)
{
    out << aHouse.address << ";" << aHouse.description << ";" << aHouse.footage << ";" << aHouse.bedrooms;
    out << ";" << aHouse.bathrooms << endl;
    return out;
}

const data& data::operator=(const data& aHouse)
{
    //if it is a self copy don't do anything
    if(this == &aHouse)
        return *this;
    //make current object *this a copy of the passed in winery
    else
    {
        setAddress(aHouse.address);
        setDescription(aHouse.description);
        setFootage(aHouse.footage);
        setBedrooms(aHouse.bedrooms);
        setBathrooms(aHouse.bathrooms);;
        return *this;
    }

}