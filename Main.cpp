#include<iostream>
#include<fstream>
#include<cstdlib>

#include "Login.h"
#include "Doctor.h"
#include "Dashboard.h"
#include "Patients.h"
#include "Room.h"
#include "Bill.h"
#include "RoomAssignmentDoctors.h"

using namespace std;

			
int main()
{
	// Objects
	Login objLogin;
	User objUser;
	Doctor objDoctor;
	Patient objPatient;
	Dashboard objDashboard;
	Room objRoom;
	RoomAssignmentDoctors objDoctorRooms;

	system("cls");
	for (int i = 0; i <= 100; i++)
	{
		cout<<"-";
	}
      cout<<"\n\n\t\t\t\t\tCU CLINIC OPD SOFTWARE\n\n";
	for (int i = 0; i <= 100; i++)
	{
		cout<<"-";
	}
	cout<<"\n\n";

	system("pause");

	loginScreen:
		int loginResult = objLogin.loginMenu();
		switch (loginResult)
		{
			case 1:
			{
				bool result = objLogin.checkLogin();
				if(result)
				{
						// Show Dashboard
				showDashboard:
					int DashboardResult = objDashboard.dashboardMenu();
					switch (loginResult)
					{
						case 1:
						{
							// Show Dashboard
							if(objDoctor.doctorMenu()==5)
							{								
								goto showDashboard;
							}
							break;
						}

						case 2:
						{
							objPatient.patientMenu();
							goto showDashboard;
							break;
						}

						case 3:
						{
							objRoom.roomMenu();
							goto showDashboard;
							break;
						}

						case 4:
						{
							cout<<"Doctor Room Assignment";
							break;
						}

						case 5:
						{
							cout<<"Patient Bill and Discharge";
							break;
						}

						case 6:
						{
							// Exit
							cout<<"Exiting...";
							return 0;
							break;
						}
					}
			
				}	
				else
				{
					system("pause");
					goto loginScreen;
				}
			}

			case 2:
			{
				
				if(objUser.userMenu()==5)
				{
					goto loginScreen;
				}
				else
				{
					break;
				}
			}

			case 3:
			{
				return 0;
			}

			default:
				break;
		}
		
	return 0;
}