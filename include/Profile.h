#ifndef PROFILE_H
#define PROFILE_H

#include <iostream>

using namespace std;

class Profile
{
private:
  string firstname;
  string lastname;
  string birth;
  string password;
  static int id;
  int index;
public:
  Profile(string firstname, string lastname, string birth, string password);
  Profile(string name, string lastname);
  void setFirstName(string firstname);
  void setLastName(string lastname);
  void setBirth(string birth);
  void getFriends();


  string getFirstName();
  string getLastName();
  string getBirth();
  string getPassword();
  int getIndex();
};
#endif // PROFILE_H
