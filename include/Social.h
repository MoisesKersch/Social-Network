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
    vector <list<Profile>> profileVector;

    list<Profile>::iterator li; // list iterrator
    vector<list<Profile>>::iterator vi; // vector iterrator

    static int counter;
    static int totalAccounts;
    int accountid;

    bool accountExist(string username);
    bool isUniqueUserName(string username);
public:
    Social();
    bool createAccount(string username, string name, string lastname, string birth, string password);
    void showAllAccounts();

    void login(string name, string lastname);

    void AddFriend(string username);
    void showMyFriends();
    bool isFriend(string name, string lastname, int index);
    bool deleteAfriend(string username);
    bool deleteAccount();

    string getName();
    string getLastName();
};

#endif // SOCIAL_H
