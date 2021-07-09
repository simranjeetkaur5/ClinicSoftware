#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

class Room
{
		private:
			int d_id;
			char name[30];
			char spec[30];
			fstream fRoom;
		public:
			void enter();
			void disp();
			void roomMenu();
			int get__d_id(){return d_id;}
			char *get__name(){return name;}
			char *get__spec(){return spec;}
};

void Room::enter()
{
		system("cls");
		cout<<"\nEnter Room Identification Number :";
		cin>>d_id;
		cin.ignore(5,'\n');
		cout<<"\nEnter Room's Name :";
		gets(name);
		cout<<"\nEnter Room's Speciality :";
		gets(spec);
}

void Room::disp()
{
		system("cls");
                cout << "\t\t\t*** Report - Room Details ***\n\n";
		cout<<"\nRoom Identification Number :"<<d_id;
		cout<<"\nRoom's Name :";
		puts(name);
		cout<<"Room's Speciality:";
		puts(spec);
}

void Room::roomMenu()
{
    int opt;
	lRoom:
		system("cls");
		cout<<"\t\t\t:: ROOM MANAGEMENT ::\n\n";
		cout<<"\t\t\t1. Add new Room\n";
		cout<<"\t\t\t2. Update existing Room details\n";
		cout<<"\t\t\t3. Remove a Room\n";
		cout<<"\t\t\t4. View Room Info\n";
		cout<<"\t\t\t5. Back\n\n\n";
		cout<<"\t\t\tEnter your option : ";
		cin>>opt;
        Room Room1;
		switch(opt)
		{	
            case 1:
            {
                // Add new Room
                fRoom.open("./Data/Room.dat",ios::in|ios::out);
                if(!fRoom)
                {
                        cout<<"NOT FOUND";
                        system("pause");
                        goto lRoom;
                }
                fRoom.seekp(0,ios::end);
                Room1.enter();
                fRoom.write((char*)&Room1,sizeof(Room1));
                if(fRoom.bad())
                {
                        cout<<"ERROR";
                        system("pause");
                        goto lRoom;
                }
                cout<<"\nData Successfully Written..\n";
                fRoom.close();
                system("pause");
                goto lRoom;
            }
            
            case 2:
            {
                // Update existing Room details
                system("cls");
                fRoom.open("./Data/Room.dat",ios::in|ios::out);
                if(!fRoom)
                {
                        cout<<"NOT FOUND";
                        system("pause");
                        goto lRoom;
                }
                cout<<"\n\n\t\t\t\t\tCU CLINIC OPD SOFTWARE\n\n";
                cout<<"\t\t\tUPDATE\n\n";
                cout<<"Enter Room Identification Number :";
                int i;
                cin>>i;
                fRoom.seekp(0,ios::beg);
                int k=0;
                while(!fRoom.eof())
                {
                        if(fRoom.eof())
                        {
                                break;
                        }
                        int n;
                        n=fRoom.tellg();
                        Room doc2;
                        fRoom.read((char*)&doc2,sizeof(doc2));
                        if(doc2.get__d_id()==i)
                        {
                                cout<<"\nOriginal :\n";
                                doc2.disp();
                                k=1;
                                cout<<"\n\n\t Press 0 to go ahead\n\tPress 1 to go back_ ";
                                int m;
                                cin>>m;
                                if(m==1)
                                {
                                        continue;
                                }
                                cout<<"\nEnter New One's :\n";
                                doc2.enter();
                                fRoom.seekp(n,ios::beg);
                                fRoom.write((char*)&doc2,sizeof(doc2));
                                break;
                        }
                }
                fRoom.close();
                if(k==0)
                {	
                        cout<<"\nNOT FOUND";
                        system("pause");
                        goto lRoom;
                }
                goto lRoom;
            }
            
            case 3:
            {
                // Remove a Room
                fRoom.open("./Data/Room.dat",ios::in|ios::out);
                system("cls");
                if(!fRoom)
                {
                        cout<<"File not found";
                        system("pause");
                        goto lRoom;
                }
                ofstream tmp;
                tmp.open("./Data/temRoom.dat",ios::out|ios::trunc);
                int k=0;
                int i=0;
                cout<<"\n\n\t\t\tREMOVE\n\n";
                cout<<"Enter Room Identification Number: \n";
                cin>>i;
                fRoom.seekg(0,ios::beg);
                while(!fRoom.eof())
                {
                        if(fRoom.eof())
                        {
                                break;
                        }
                        fRoom.read((char*)&Room1,sizeof(Room1));
                        if(Room1.get__d_id()==i)
                        {
                                Room1.disp();
                                k=1;
                                cout<<"Are you sure you want to delete this (yes=1 no=0)? _";
                                int n;
                                cin>>n;
                                if(n==0)
                                {
                                        tmp.write((char*)&Room1,sizeof(Room1));
                                }
                        }
                        else
                        {
                                tmp.write((char*)&Room1,sizeof(Room1));
                        }
                }
                if(k==0)
                {
                        cout<<"Room not present\n";
                        system("pause");
                        goto lRoom;
                }
                tmp.close();
                fRoom.close();
                remove("./Data/Room.dat");
                remove("./Data/Room.dat");
                rename("./Data/temRoom.dat","./Data/Room.dat");
                goto lRoom;
            }

            case 4:
            {
                // View Details
                system("cls");
                fRoom.open("./Data/Room.dat",ios::in|ios::out);
                if(!fRoom)
                {
                        cout<<"NOT FOUND";
                        system("pause");
                        goto lRoom;
                }
                cout<<"\n\n\t\t\t\t\tCU CLINIC OPD SOFTWARE\n\n";
                cout<<"Enter Room Id to view:";
                int i;
                cin>>i;
                fRoom.seekp(0,ios::beg);
                int k=0;
                while(!fRoom.eof())
                {
                        if(fRoom.eof())
                        {
                                break;
                        }
                        int n;
                        n=fRoom.tellg();
                        Room doc2;
                        fRoom.read((char*)&doc2,sizeof(doc2));
                        if(doc2.get__d_id()==i)
                        {
                                cout<<"\nOriginal :\n";
                                doc2.disp();
                                system("pause");
                                goto lRoom;
                        }
                }
                fRoom.close();
                goto lRoom;
            }

            case 5:
            {
                cout<<"Exit";
                break;
            }

			default:
            {
                break;
            }			
		}
}