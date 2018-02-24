#include <iostream>
#include <list>
#include "Social.h"
#include <windows.h>
#include <iostream>
#include <fstream>

#include <DataBase.h> // if you get some error, you can comment this line, it means you're database mysql isn't properly configured in your machine.

// built by Moises Kerschner
// if you're in code blocks go to setting >> compiler >> Liker settings >> Add >> go to \Social-Network\lib\ and include "libmysql.a".

using namespace std;

string name[] = {"Master", "Rose", "Airto", "Rodrigo", "Martha", "Roberto", "Rafael", "Ana", "Lana", "Kirk"};
string lastname[] = {"Rupperts", "Almeida", "Oliveira", "Matos", "Huff", "Da Silva", "Santos", "Lima", "Del Rey", "Hemmet"};

//Social mysocial;
//DataBase database("localhost", "root", "", "register");
//
//void addFriend();
//
//
//void createAccount()
//{
//    string newname;
//    string newlastname;
//    cout << "\t\tWelcome to my social network, first please help us to create an account for you.\n" << endl;
//
//    cout << "Type your full name: ";
//    cin >> newname;
//    cin >> newlastname;
//
//    name[0] = newname;
//    lastname[0] = newlastname;
//
//    mysocial.createAccount(name[0], lastname[0], "101010", "root");
//
//    database.insertInto(name[0], lastname[0], "1000-10-10", "root");
//
//    cout << "\n\tCongratulations "+mysocial.getName()+" "+mysocial.getLastName()+", now you make part of this social network!\n" << endl;
//    Sleep(2000);
//    cout << "\t\tMore people are joining this social media, please wait...\n" << endl;
//    for (int x=1; x<10; x++)
//    {
//        cout << "\t" << name[x] << " " << lastname[x] << endl;
//        Sleep(500);
//        mysocial.createAccount(name[x], lastname[x], "101010", "root");
//        database.insertInto(name[x], lastname[x], "1000-10-10", "root");
//    }
//    Sleep(200);
//}
//
//void loginAccount(string name, string password)
//{
//
//    cout << "\n\t\tLogin into your account please wait...\n" << endl;
//    Sleep(1000);
//    if (mysocial.login(name, password) != -1)
//    {
//        cout << "\tBem Vindo " << mysocial.getName() << "\n" << endl;
//    }
//    else cout << "Wrong Acount!" << endl;
//    Sleep(200);
//}
//
//void addFriend()
//{
//    cout << "\t\tNow we're gonna add some friends to your account please wait...\n" << endl;
//
//    for (int x=2; x<8; x++)
//    {
//        mysocial.AddFriend(name[x], lastname[x], mysocial.login(name[0], "root"));
//        Sleep(100);
//    }
//}

int main()
{
//    createAccount();
//    loginAccount(name[0], "root");
//    addFriend();
//
//    cout << "\n\t\tDisplaying all your friends!\n" << endl;
//    mysocial.showMyFriends(mysocial.login(name[0], "root"));
//    Sleep(2000);
//
//    cout << "\n\t\tLet's now check if "+name[8]+" "+lastname[8]+" is your friend..." << endl;
//    Sleep(2000);
//    if (mysocial.isFriend(name[8], lastname[8], mysocial.login(name[0], "root")))
//    {
//        cout << "\n\tYes you guys are friends!" << endl;
//    }
//    else
//    {
//        cout << "\n\tNo, you're not friend with "+name[8]+" "+lastname[8]+"!" << endl;
//    }
//
//    Sleep(2000);
//    cout << "\n\t\tWait! what are you doing? I don't think you'll be capable to enter another person's account...";
//    Sleep(2000);
//    loginAccount(name[5], "root");
//
//    cout << "\t\tWow, you managed to hack "+mysocial.getName()+"'s account" << endl;
//    Sleep(2000);
//    cout << "\t\tWell since you're here, let's explore "+mysocial.getName()+"'s account" << endl;
//    Sleep(2000);
//    cout << "\t\tFirst let's take a look at his friends\n" << endl;
//    Sleep(2000);
//    mysocial.showMyFriends(mysocial.login(name[5], "root"));
//    cout << "\n\t\tMmm.. the only friend he's got is you" << endl;
//    Sleep(3000);
//    cout << "\n\t\tLet's add a few friends to this profile...." << endl;
//    Sleep(3000);
//    for (int x=6; x<10; x++)
//    {
//       mysocial.AddFriend(name[x], lastname[x], mysocial.login(name[5], "root"));
//    }
//
//    cout << "\n\t\tLet's see "+mysocial.getName()+"'s new friends..." << endl;
//    mysocial.showMyFriends(mysocial.login(name[5], "root"));
//    Sleep(3000);
//
//
//
//
//    for(int x = 0; x<10; x++)
//        social.createAccount(name[x], lastname[x], "0000", "root");
//
//
//        // master will add airton, rodrigo.
//
//    for(int x = 1; x<100000; x++)
//        social.AddFriend(to_string(x), to_string(x), 0);
//
//
//    social.showMyFriends(1);
//
//    social.showAllAccounts();

     Social social;
     ifstream file;
     string firstname, lastname;

     file.open("accounts.txt");

     if(file.is_open())
     {
         while (file >> firstname && file >> lastname)
         {
            social.createAccount(firstname, firstname, lastname, "1000-10-10", "root");
         }
     }
     file.close();

     social.createAccount("orthonn", "Moises", "Kerschner", "1000-10-10", "orthonn123");

     social.login("orthonn", "orthonn123");

     file.open("accounts.txt");
     if(file.is_open())
     {
         while (file >> firstname && file >> lastname)
         {
            social.AddFriend(firstname);
         }
     }
     file.close();

     social.showMyFriends();





}










