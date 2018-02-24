#include <iostream>
#include "Profile.h"

using namespace std;

int Profile:: id = 0;

// creating a new account
Profile::Profile(string username, string firstname, string lastname, string birth, string password)
{
  this->username = username;
  this->firstname = firstname;
  this->lastname = lastname;
  this->birth = birth;
  this->password = password;
  this->index = id;
  id++;
}

// adding a new friend
Profile::Profile(string username)
{
    this->username = username;
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

void Profile::checking(bool input)
{
    this->checked = input;
}

bool Profile::getCheck()
{
    return checked;
}

string Profile::getUserName()
{
    return this->username;
}





