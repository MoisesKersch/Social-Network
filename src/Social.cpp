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
    list <Profile> profile;
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

}

void Social::showMyFriends(int index)
{

}

void Social::show()
{

    x = profileVector.begin();

    (*x).push_back(Profile("joseph", "third"));
    (*x).push_back(Profile("cool", "third"));
    (*x).push_back(Profile("dog", "third"));

    it = (*x).begin();

    for (auto& it: (*x))
    cout << (it).getFirstName();

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

















