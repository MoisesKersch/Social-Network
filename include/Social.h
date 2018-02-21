#ifndef SOCIAL_H
#define SOCIAL_H

#include <iostream>
#include <list>
#include "Profile.h"
#include <vector>
#include <algorithm>
#include "windows.h"

using namespace std;

class Social
{
private:
    list <Profile>* profile = new list<Profile>[10]; // deprecated

    vector <list<Profile>> profileVector;
    list<Profile>::iterator li; // list iterrator
    vector<list<Profile>>::iterator vi; // vector iterrator

    static int counter;
    static int totalAccounts;
    int curIndex;
public:
    Social();
    void createAccount(string name, string lastname, string birth, string password);
    void show();


    int login(string name, string lastname);
    void AddFriend(string name, string lastname, int index);
    void showMyFriends(int index);
    int accountExist(string name, string lastname);
    bool isFriend(string name, string lastname, int index);
    string getName();
    string getLastName();
};

#endif // SOCIAL_H
