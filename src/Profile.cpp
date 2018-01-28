#include <iostream>
#include "Profile.h"

using namespace std;

int Profile:: id = 0;

// creating a new account
Profile::Profile(string firstname, string lastname, string birth, string password)
{
  this->firstname = firstname;
  this->lastname = lastname;
  this->birth = birth;
  this->password = password;
  this->index = id;
  id++;
}

// adding a new friend
Profile::Profile(string name, string lastname)
{
    this->firstname = name;
    this->lastname = lastname;
}

void Profile::setFirstName(string firstname)
{
  this->firstname = firstname;
}

void Profile::setLastName(string lastname)
{
  this->lastname = lastname;
}

void Profile::setBirth(string birth)
{
  this->birth = birth;
}

string Profile::getFirstName()
{
    return firstname;
}

string Profile::getLastName()
{
    return lastname;
}

string Profile::getBirth()
{
    return birth;
}

int Profile::getIndex()
{
    return index;
}

string Profile::getPassword()
{
    return password;
}

