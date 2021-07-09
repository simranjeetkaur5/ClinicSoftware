
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