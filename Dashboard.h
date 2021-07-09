#include<iostream>
using namespace std;

class Dashboard
{
	private:
		int opt;
	
	public:
		int dashboardMenu();
	
};

int Dashboard::dashboardMenu()
{
	lDashboard:
		system("cls");
		cout<<"\t\t\t:: Dashboard ::\n\n";
		cout<<"\t\t\t1. Doctor Management\n";
		cout<<"\t\t\t2. Patient Management\n";
        cout<<"\t\t\t3. Room Management\n";
        cout<<"\t\t\t4. Doctor Room Assignment\n";
        cout<<"\t\t\t5. Patient Bill & Discharge\n";
		cout<<"\t\t\t6. Exit\n\n";
		cout<<"\t\t\tEnter your option : ";
		cin>>opt;
		cout<<"\n";
		return opt;
}