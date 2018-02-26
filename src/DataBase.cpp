#include "DataBase.h"

#include <iostream>

#include <winsock.h>
#include "mysql.h"


DataBase::DataBase(string localhost, string user, string password, string database)
{
  connection = mysql_init(NULL);

  if (connection == NULL)
  {
      //fprintf(stderr, "%s\n", mysql_error(connection));
      exit(1);
  }

  if (mysql_real_connect(connection, localhost.c_str(), user.c_str(), password.c_str(), NULL, 0, NULL, 0) == NULL)
  {
      //fprintf(stderr, "%s\n", mysql_error(connection));
      mysql_close(connection);
      exit(1);
  }
  createScheme(database);
}

void DataBase::createScheme(string database)
{
      query = "Create database if not exists "+database+" default character set utf8 default collate utf8_general_ci;";
      if (mysql_query(connection, query.c_str()))
      {
          fprintf(stderr, "%s\n", mysql_error(connection));
          mysql_close(connection);
          exit(1);
      }

      query = "use "+database;

      if (mysql_query(connection, query.c_str()))
      {
          fprintf(stderr, "%s\n", mysql_error(connection));
          mysql_close(connection);
          exit(1);
      }

      if (mysql_query(connection, getFiles().c_str()))
      {
          fprintf(stderr, "%s\n", mysql_error(connection));
          mysql_close(connection);
          exit(1);
      }
}

void DataBase::insertInto(string username, string name, string lastname, string birth, string password)
{
    query = "insert into person (username, name, lastname, birthday, password) value ('"+username+"', '"+name+"', '"+lastname+"', '"+birth+"', '"+password+"');";

    if (connection != 0 && !(querystate = mysql_query(connection, query.c_str())))
    {
        cout << "\t\tData saved successfully!!" << endl;
    }
    else
    {
        cout << "\t\tSorry, your data could not be saved!" << endl;
    }
}

bool DataBase::clearTable()
{
    query = "truncate table person;";
    if (connection != 0 && !(querystate = mysql_query(connection, query.c_str())))
    {
        cout << "Table successfully cleared!" << endl;
    }
    else
    {
        cout << "Sorry, your table could not be cleared!" << endl;
    }
}

void DataBase::displayAllRecords()
{
    querystate = mysql_query(connection, "select* from person");

        if (!querystate)
        {
            //get all records from conn object to res pointer
            result = mysql_store_result(connection);
            // read and display all records
            bool check = false;
            while (row = mysql_fetch_row(result))
            {
                check = true;
                cout << "\n";
                cout << "Name: " << row[2] << " " << row[3] << endl;
                cout << "Birthday : " << row[4] << endl;
            }
            if (!check)
                cout << "Nothing to be shown, table is clear!" << endl;
        }
}

string DataBase::getFiles()
{
     file.open("./files/databaseTable.txt");

     string tempt;
     query = " ";
     if(file.is_open())
     {
         while (file >> tempt)
         {
            query+= " "+tempt;
         }
     }
     file.close();
     return query;
}







