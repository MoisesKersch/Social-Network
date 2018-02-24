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
  string username;
  bool checked;
  static int id;
  int index;
public:
  Profile(string username, string firstname, string lastname, string birth, string password);
  Profile(string username);

  void setFirstName(string firstname);
  void setLastName(string lastname);
  void setBirth(string birth);
  void getFriends();
  void checking(bool input);

  string getUserName();
  string getFirstName();
  string getLastName();
  string getBirth();
  string getPassword();
  int getIndex();
  bool getCheck();
};
#endif // PROFILE_H
