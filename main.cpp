#include <iostream>
#include <list>
#include "Social.h"
#include <windows.h>


using namespace std;

Social mysocial;

void addFriend();

void createAccount()
{
    cout << "\t\tSetting up new accounts...\n" << endl;

    for (int x=0; x<10; x++)
    {
        string a;
        a = to_string(x);
        cout << "\tAccount "+a+" Joining" << endl;
        Sleep(100);
        mysocial.createAccount("Account "+a, "Joining", "101010", "root");
    }
    cout << "\n\t\tWe're setting an account for you, please wait...\n" << endl;
    Sleep(200);
    cout << "\tYour Account is: Account 0 <<<<<\n" << endl;
}

void loginAccount()
{

    cout << "\t\tLogin into your account please wait...\n" << endl;
    Sleep(1000);
    if (mysocial.login("Account 0", "root") != -1)
    {
        cout << "\tLogin Successful!\n" << endl;
    }
    else cout << "Wrong Acount!" << endl;
    Sleep(200);
}

void addFriend()
{
    cout << "\t\tNow we're gonna add some friends to your account please wait...\n" << endl;
    mysocial.AddFriend("Account 9", "Joining", mysocial.login("Account 0", "root"));
}

int main()
{

    createAccount();
    loginAccount();
    addFriend();

    cout << "\n\t\tDisplaying all your friends!\n" << endl;
    mysocial.showMyFriends(mysocial.login("Account 0", "root"));
    Sleep(2000);


}
