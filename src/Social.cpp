#include <iostream>
#include <stack>
#include <stdlib.h>
#include "Profile.h"
#include "Social.h"
#include <algorithm>
#include <typeinfo>

// (*vi).begin() == list
// (vi) == vector iterator
// (li) == list iterator
// (*li) == profile
// get varible type cout << typeid(variable).name() << endl;
using namespace std;

int Social::counter = 0;

Social::Social()
{
    logged = false;
}

/// server side
bool Social::createAccount(string username, string name, string lastname, string birth, string password)
{
    list<Profile>profile;

    if (profileVector.size() == 0)
    {
         profile.push_back(Profile(username, name, lastname, birth, password));
         profileVector.push_back(profile);
    }
    else if (isUniqueUserName(username))
    {
        profile.push_back(Profile(username, name, lastname, birth, password));
        profileVector.push_back(profile);
    }
    else
    {
        return false;
    }
    return true;
}

void Social::login(string username, string password)
{
    vi = profileVector.begin();
    int x = 0;
    bool found = false;
    for (auto& vi: profileVector)
    {
         if (((vi).front().getUserName() == username)&& ((vi).front().getPassword() == password))
         {
            cout << "\n\nLogin successful! ";
            found = true;
            logged = true;
            break;
         }
         x++;
    }

    if (found)
    {
        advance(vi, x);
        cout << "Welcome "+vi->front().getFirstName()+" "+vi->front().getLastName() << endl;
        this->accountid = x;
        return;
    }
    cout << "Login failed!" << endl;
        return;
}

bool Social::isUniqueUserName(string username)
{
    vi = profileVector.begin();
    for (auto& vi: profileVector)
    {
         if ((vi).front().getUserName() == username)
            return false;
    }
    return true;
}

void Social::showAllAccounts()
{
     for (auto& vi: profileVector)
        cout << "User Name: "+(vi).front().getUserName() << " | Account: " << (vi).front().getFirstName() << " " << (vi).front().getLastName() << endl;
}
bool Social::accountExist(string username){}

/// client side // after login successful
void Social::AddFriend(string username)
{
     vi = profileVector.begin();
     advance(vi, accountid);

     if(!isUniqueUserName(username) and (*vi).front().getUserName() != username and isFriend(username))
     {
         advance(vi, accountid);
         (*vi).push_back(Profile(username));
         cout << "You added "+username << endl;
     }
     else
     {
        if (!isFriend(username))
            cout << "You already added "+username+"." << endl;
        else if(isUniqueUserName(username))
            cout << "Error adding "+username+" account doesn't exists! " << endl;
        else cout << "Error adding "+username+" you can't add yourself! " << endl;
     }
}

void Social::showMyFriends()
{
    if (logged == true)
    {
        vi = profileVector.begin(); // vi turns into the list class "profile" from vector class "profileVector"
        advance(vi, accountid);
        li = (*vi).begin(); // li turns into the Profile class from "profile" list class

        int x = 0;
        for(x; x <(*vi).size()-1; x++)
        {
            advance(li, 1);
            cout << (*li).getUserName() << endl;
        }

        if (x == 0)
        {
            cout << "\nYou don't have any friends";
        }
    }
    else
    {
        cout << "Error your not logged in!" << endl;
    }
}

bool Social::deleteAfriend(string username)
{
    vi = profileVector.begin(); // vi turns into the list class "profile" from vector class "profileVector"
    advance(vi, accountid);
    li = (*vi).begin(); // li turns into the Profile class from "profile" list class

    int x = 0;
    for(x; x <(*vi).size()-1; x++)
    {
        advance(li, 1);
        if ((*li).getUserName() == username)
        {
             cout << "The user name "+(*li).getUserName()+" was deleted!" << endl;
             li = (*vi).erase(li);
             return true;
        }
    }
    cout << "The user name doesn't exits!" << endl;
    return false;
}

bool Social::deleteAccount()
{
   profileVector.erase (profileVector.begin()+accountid);
}

bool Social::isFriend(string username)
{
    vi = profileVector.begin(); // vi turns into the list class "profile" from vector class "profileVector"
    advance(vi, accountid);
    li = (*vi).begin(); // li turns into the Profile class from "profile" list class

    for(int x = 0; x <(*vi).size()-1; x++)
    {
        advance(li, 1);
        if ((*li).getUserName() == username)
            return false;
    }
    return true;
}
string Social::getName(){}
string Social::getLastName()
{

}











