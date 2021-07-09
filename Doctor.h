#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;

class Doctor
{
		private:
			int d_id;
			char name[30];
			char spec[30];
			fstream fDoctor;
		public:
			void enter();
			void disp();
			int doctorMenu();
			int get__d_id(){return d_id;}
			char *get__name(){return name;}
			char *get__spec(){return spec;}
};

void Doctor::enter()
{
		system("cls");
		cout<<"\nEnter Doctor Identification Number :";
		cin>>d_id;
		cin.ignore(5,'\n');
		cout<<"\nEnter Doctor's Name :";
		gets(name);
		cout<<"\nEnter Doctor's Speciality :";
		gets(spec);
}

void Doctor::disp()
{
		system("cls");
                cout << "\t\t\t*** Report - Doctor Details ***\n\n";
		cout<<"\nDoctor Identification Number :"<<d_id;
		cout<<"\nDoctor's Name :";
		puts(name);
		cout<<"Doctor's Speciality:";
		puts(spec);
}

int Doctor::doctorMenu()
{
    int opt;
	lDoctor:
		system("cls");
		cout<<"\t\t\t:: DOCTOR MANAGEMENT ::\n\n";
		cout<<"\t\t\t1. Add new Doctor\n";
		cout<<"\t\t\t2. Update existing Doctor details\n";
		cout<<"\t\t\t3. Remove a Doctor\n";
		cout<<"\t\t\t4. View Doctor Info\n";
		cout<<"\t\t\t5. Back\n\n\n";
		cout<<"\t\t\tEnter your option : ";
		cin>>opt;
                Doctor Doctor1;
		switch(opt)
		{	
                        case 1:
                        {
                                // Add new Doctor
                                fDoctor.open("./Data/Doctor.dat",ios::in|ios::out);
                                if(!fDoctor)
                                {
                                        cout<<"NOT FOUND";
                                        system("pause");
                                        goto lDoctor;
                                }
                                fDoctor.seekp(0,ios::end);
                                Doctor1.enter();
                                fDoctor.write((char*)&Doctor1,sizeof(Doctor1));
                                if(fDoctor.bad())
                                {
                                        cout<<"ERROR";
                                        system("pause");
                                        goto lDoctor;
                                }
                                cout<<"\nData Successfully Written..\n";
                                fDoctor.close();
                                system("pause");
                                goto lDoctor;
                        }
                        
                        case 2:
                        {
                                // Update existing Doctor details
                                system("cls");
                                fDoctor.open("./Data/Doctor.dat",ios::in|ios::out);
                                if(!fDoctor)
                                {
                                        cout<<"NOT FOUND";
                                        system("pause");
                                        goto lDoctor;
                                }
                                cout<<"\n\n\t\t\t\t\tCU CLINIC OPD SOFTWARE\n\n";
                                cout<<"\t\t\tUPDATE\n\n";
                                cout<<"Enter Doctor Identification Number :";
                                int i;
                                cin>>i;
                                fDoctor.seekp(0,ios::beg);
                                int k=0;
                                while(!fDoctor.eof())
                                {
                                        if(fDoctor.eof())
                                        {
                                                break;
                                        }
                                        int n;
                                        n=fDoctor.tellg();
                                        Doctor doc2;
                                        fDoctor.read((char*)&doc2,sizeof(doc2));
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
                                                fDoctor.seekp(n,ios::beg);
                                                fDoctor.write((char*)&doc2,sizeof(doc2));
                                                break;
                                        }
                                }
                                fDoctor.close();
                                if(k==0)
                                {	
                                        cout<<"\nNOT FOUND";
                                        system("pause");
                                        goto lDoctor;
                                }
                                goto lDoctor;
                        }
                        
                        case 3:
                        {
                                // Remove a Doctor
                                fDoctor.open("./Data/Doctor.dat",ios::in|ios::out);
                                system("cls");
                                if(!fDoctor)
                                {
                                        cout<<"File not found";
                                        system("pause");
                                        goto lDoctor;
                                }
                                ofstream tmp;
                                tmp.open("./Data/temdoc.dat",ios::out|ios::trunc);
                                int k=0;
                                int i=0;
                                cout<<"\n\n\t\t\tREMOVE\n\n";
                                cout<<"Enter Doctor Identification Number: \n";
                                cin>>i;
                                fDoctor.seekg(0,ios::beg);
                                while(!fDoctor.eof())
                                {
                                        if(fDoctor.eof())
                                        {
                                                break;
                                        }
                                        fDoctor.read((char*)&Doctor1,sizeof(Doctor1));
                                        if(Doctor1.get__d_id()==i)
                                        {
                                                Doctor1.disp();
                                                k=1;
                                                cout<<"Are you sure you want to delete this (yes=1 no=0)? _";
                                                int n;
                                                cin>>n;
                                                if(n==0)
                                                {
                                                        tmp.write((char*)&Doctor1,sizeof(Doctor1));
                                                }
                                        }
                                        else
                                        {
                                                tmp.write((char*)&Doctor1,sizeof(Doctor1));
                                        }
                                }
                                if(k==0)
                                {
                                        cout<<"Doctor not present\n";
                                        system("pause");
                                        goto lDoctor;
                                }
                                tmp.close();
                                fDoctor.close();
                                remove("./Data/Doctor.dat");
                                remove("./Data/Doctor.dat");
                                rename("./Data/temdoc.dat","./Data/Doctor.dat");
                                goto lDoctor;
                        }

                        case 4:
                        {
                                // View Details
                                system("cls");
                                fDoctor.open("./Data/Doctor.dat",ios::in|ios::out);
                                if(!fDoctor)
                                {
                                        cout<<"NOT FOUND";
                                        system("pause");
                                        goto lDoctor;
                                }
                                cout<<"\n\n\t\t\t\t\tCU CLINIC OPD SOFTWARE\n\n";
                                cout<<"Enter Doctor Id to view:";
                                int i;
                                cin>>i;
                                fDoctor.seekp(0,ios::beg);
                                int k=0;
                                while(!fDoctor.eof())
                                {
                                        if(fDoctor.eof())
                                        {
                                                break;
                                        }
                                        int n;
                                        n=fDoctor.tellg();
                                        Doctor doc2;
                                        fDoctor.read((char*)&doc2,sizeof(doc2));
                                        if(doc2.get__d_id()==i)
                                        {
                                                cout<<"\nOriginal :\n";
                                                doc2.disp();
                                                fDoctor.close();
                                                system("pause");
                                                goto lDoctor;
                                        }
                                }
                                fDoctor.close();
                                goto lDoctor;
                        }

                        case 5:
                        {
                                return 5;
                        }

                        default:
                        {
                                return 5;
                        }			
	}
}