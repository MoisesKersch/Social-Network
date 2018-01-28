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
            curIndex = profile[x].front().getIndex();
        }
    }
    return -1;
}

int Social::accountExist(string name, string lastname)
{
    for (int x = 0; x<10; x++)
    {
        if (name == profile[x].front().getFirstName() && lastname == profile[x].front().getLastName())
        {
             return profile[x].front().getIndex();
        }
    }
    return 0;
}

void Social::AddFriend(string name, string lastname, int index)
{
    if (accountExist(name, lastname))
    {
        profile[index].push_back(Profile(name, lastname));
        profile[accountExist(name, lastname)].push_back(Profile(profile[index].front().getFirstName(), profile[index].front().getLastName())); //wow hehe :D
        cout << "\tYou added: " << name << " " << lastname << endl;
    }
    else cout << "\tAccount does not exist! " << endl;
}

void Social::showMyFriends(int index)
{
    for(it=profile[index].begin(); it!=profile[index].end(); it++)
    {
        (*it).getFirstName() != profile[index].front().getFirstName() ?
        cout << "\t" << (*it).getFirstName() << " " << (*it).getLastName() << endl:
        cout << "";
        Sleep(200);
    }
}


bool Social::isFriend(string name, string lastname, int index)
{
    for(it=profile[index].begin(); it!=profile[index].end(); it++)
    {
       if((*it).getFirstName() != profile[index].front().getFirstName())
       {
            continue;
       }
       else if((*it).getFirstName() == name && (*it).getLastName() == lastname)
       {
           return true;
       }
    }
    return false;
}

string Social::getName()
{
    return profile[curIndex].front().getFirstName();
}

string Social::getLastName()
{
    return profile[curIndex].front().getLastName();
}

















