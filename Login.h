#include<iostream>
#include<fstream>
#include<cstdlib>

#include "User.h"

using namespace std;

class Login
{
	private:
		int opt;
		string username;
		string password;
		fstream fLogin;
	
	public:
		int loginMenu();
		bool checkLogin();
};

int Login::loginMenu()
{
	ldoc:
		system("cls");
		cout<<"\t\t\t:: Login Screen ::\n\n";
		cout<<"\t\t\t1. Login\n";
		cout<<"\t\t\t2. User Management\n";
		cout<<"\t\t\t3. Exit\n\n";
		cout<<"\t\t\tEnter your option : ";
		cin>>opt;
		cout<<"\n";
		return opt;
}

bool Login::checkLogin()
{
	system("cls");
	
	cout<<"\nEnter your username : ";
	cin>>username;
	cout<<"\nEnter your password : ";
	cin>>password;

	fLogin.open("./Data/User.dat",ios::in|ios::out);
	if(!fLogin)
	{
		cout<<"NOT FOUND";
		return false;
	}
	fLogin.seekp(0,ios::beg);
	int k=0;
	while(!fLogin.eof())
	{
			if(fLogin.eof())
			{
					break;
			}
			int n;
			n=fLogin.tellg();
			User obUser;
			fLogin.read((char*)&obUser,sizeof(obUser));
			if(obUser.get__name()==username && obUser.get__password()==password)
			{
				return true;
			}
			else
			{
				cout<<"Incorrect Username or Password.";
			}
	}
	fLogin.close();
}