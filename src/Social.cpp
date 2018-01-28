#include <iostream>
#include <stdlib.h>
#include "Profile.h"
#include "Social.h"

using namespace std;

int Social::counter = 0;

Social::Social(){}

void Social::createAccount(string name, string lastname, string birth, string password)
{
    profile[counter].push_back(Profile(name, lastname, birth, password));
    counter++;
}

int Social::login(string name, string password)
{

    for (int x = 0; x<10; x++)
    {
        if (name == profile[x].front().getFirstName() && password == profile[x].front().getPassword())
        {
            return profile[x].front().getIndex();
        }
    }
    return -1;
}

bool Social::accountExist(string name, string lastname)
{
    for (int x = 0; x<10; x++)
    {
        if (name == profile[x].front().getFirstName() && lastname == profile[x].front().getLastName())
        {
            return true;
        }
    }
    return false;
}

void Social::showMyFriends(int index)
{
    for(it=profile[index].begin(); it!=profile[index].end(); it++)
    {
        (*it).getFirstName() != profile[index].front().getFirstName() ? cout << "\t" << (*it).getFirstName() << endl: cout << "";
    }
}

void Social::AddFriend(string name, string lastname, int index)
{
    if (accountExist(name, lastname))
    {
        profile[index].push_back(Profile(name, lastname));
        cout << "\tYou added " << name << " " << lastname << endl;
    }
    else cout << "\tAccount does not exist! " << endl;
}


