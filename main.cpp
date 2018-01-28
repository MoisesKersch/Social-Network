#include <iostream>
#include <list>
#include "Social.h"
#include <windows.h>


using namespace std;
string name[] = {"Maria", "Rose", "Airto", "Rodrigo", "Martha", "Roberto", "Rafael", "Ana", "Lana", "Kirk"};
string lastname[] = {"Rupperts", "Almeida", "Oliveira", "Matos", "Huff", "Da Silva", "Santos", "Lima", "Del Rey", "Hemmet"};

Social mysocial;

void addFriend();

void createAccount()
{
    cout << "\t\tSetting up new accounts...\n" << endl;

    for (int x=0; x<10; x++)
    {
        string a;
        a = to_string(x);
        cout << "\t" << name[x] << " " << lastname[x] << endl;
        Sleep(100);
        mysocial.createAccount(name[x], lastname[x], "101010", "root");
    }
    cout << "\n\t\tWe're setting an account for you, please wait...\n" << endl;
    Sleep(200);
    cout << "\tYour Account is: "+name[0]+"  <<<<<\n" << endl;
}

void loginAccount(string name, string password)
{

    cout << "\t\tLogin into your account please wait...\n" << endl;
    Sleep(1000);
    if (mysocial.login(name, password) != -1)
    {
        cout << "\tBem Vindo"<< endl;
    }
    else cout << "Wrong Acount!" << endl;
    Sleep(200);
}

void addFriend()
{
    cout << "\t\tNow we're gonna add some friends to your account please wait...\n" << endl;

    for (int x=2; x<8; x++)
    {
        mysocial.AddFriend(name[x], lastname[x], mysocial.login(name[0], "root"));
        Sleep(100);
    }
}

int main()
{

    createAccount();
    loginAccount(name[0], "root");
    addFriend();

    cout << "\n\t\tDisplaying all your friends!\n" << endl;
    mysocial.showMyFriends(mysocial.login(name[0], "root"));
    Sleep(2000);

    cout << "\n\t\tLet's now check if "+name[8]+" "+lastname[8]+" is your friend..." << endl;
    Sleep(2000);
    if (mysocial.isFriend(name[8], lastname[8], mysocial.login(name[0], "root")))
    {
        cout << "\n\tYes you guys are friends!" << endl;
    }
    else
    {
        cout << "\n\tNo, you're not friend with "+name[8]+" "+lastname[8]+"!" << endl;
    }

    cout << "this account : " << mysocial.getName() << endl;
    loginAccount(name[2], "root");
    cout << "this account : " << mysocial.getName() << endl;




}
