#include <iostream>
#include <stdlib.h>
#include "Profile.h"
#include "Social.h"

// hello

using namespace std;

int Social::counter = 0;

Social::Social(){}

void Social::createAccount(string name, string lastname, string birth, string password)
{
    profile.push_back(Profile(name, lastname, birth, password));
    profileVector.push_back(profile);
}

int Social::login(string name, string password)
{

}

int Social::accountExist(string name, string lastname)
{

}

void Social::AddFriend(string name, string lastname, int index)
{
    vi = profileVector.begin();
    advance(vi, index);
    (*vi).push_back(Profile(name, lastname));
}

void Social::showMyFriends(int index)
{
    vi = profileVector.begin();

    advance(vi, index);

    li = (*vi).begin();

    advance(li, 1);

    cout << (*li).getFirstName();

    int x = 0;
    for (auto& li: (*vi))
    {
         cout << (li).getFirstName() << " " << x << endl;
         x++;
    }

}

void Social::show()
{
}

bool Social::isFriend(string name, string lastname, int index)
{

}

string Social::getName()
{

}

string Social::getLastName()
{
}









