#include <iostream>
#include <stack>
#include <stdlib.h>
#include "Profile.h"
#include "Social.h"
#include <algorithm>

// hello

using namespace std;

int Social::counter = 0;

Social::Social(){}

void Social::createAccount(string username, string name, string lastname, string birth, string password)
{
<<<<<<< HEAD
    list<Profile>profile;
    profile.push_back(Profile(username, name, lastname, birth, password));
=======
    profile.push_back(Profile(name, lastname, birth, password));
>>>>>>> 6f03483b9b6ea67133384881a36fd21d9c1cc52c
    profileVector.push_back(profile);
}

int Social::login(string name, string password){}

bool Social::isUniqueUserName(string username)
{
    stack<Profile> profilestack;

    for (auto& vi: profileVector)
        (vi).front().checking(false);

    vi = profileVector.begin();


//    while(true)
//
        if(!(*vi).front().getCheck())
        {
            cout << "Searched.. " << (*vi).front().getCheck() << "\n";
            (*vi).front().checking(true);

            profilestack.push((*vi).front());
        }

        Profile prof = (*vi).front();


        cout << prof.getFirstName();






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
<<<<<<< HEAD
    vi = profileVector.begin(); // vi turns into the list class "profile" from vector class "profileVector"
    advance(vi, index);

    li = (*vi).begin(); // li turns into the Profile class from "profile" list class

    for(int x=0; x <(*vi).size()-1; x++)
    {
        advance(li, 1);
        cout << (*li).getFirstName() << endl;
    }
}

void Social::showAllAccounts()
{
     for (auto& vi: profileVector)
        cout << (vi).front().getFirstName() << endl;
=======
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

>>>>>>> 6f03483b9b6ea67133384881a36fd21d9c1cc52c
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









<<<<<<< HEAD


=======
>>>>>>> 6f03483b9b6ea67133384881a36fd21d9c1cc52c
