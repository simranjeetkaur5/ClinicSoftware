#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Patient
{
private:
        int patientId;
        string patientName;
        int age;
        string disease;
        fstream fPatient;

public:
        void enter();
        void disp();
        void patientMenu();
        int get_patientId() { return patientId; }
        string get_name() { return patientName; }
        int get_age() { return age; }
        string get_disease() { return disease; }
};

void Patient::enter()
{
        system("cls");
        cout << "\nEnter Patient Id Number :";
        cin >> patientId;
        //cin.ignore(5, '\n');
        cout << "\nEnter Patient's Name :";
        //gets(patientName);
        cin>> patientName;
        cout << "\nEnter Patient's Age :";
        //gets(age);
        cin>> age;
        cout << "\nEnter Patient's Disease :";
        cin>> disease;

}

void Patient::disp()
{
        system("cls");
        cout << "\t\t\t*** Report- Patient Details ***\n\n";
        cout << "\nPatient Identification Number :" << patientId;
        cout << "\nPatient's Name :" << patientName;
        // puts(patientName);
        cout << "Patient's Age:" << age;
        cout << "Patient's Disease:" << disease;
        //puts(age);
}

void Patient::patientMenu()
{
        int opt;
lPatient:
        system("cls");
        cout << "\t\t\t:: PATIENT MANAGEMENT ::\n\n";
        cout << "\t\t\t1. Add new Patient\n";
        cout << "\t\t\t2. Update existing Patient details\n";
        cout << "\t\t\t3. Remove a Patient\n";
        cout << "\t\t\t4. View Patient Info\n";
        cout << "\t\t\t5. Back\n\n\n";
        cout << "\t\t\tEnter your option : ";
        cin >> opt;
        Patient Patient1;
        switch (opt)
        {
                case 1:
                {
                        // Add new Patient
                        fPatient.open("./Data/Patient.dat", ios::in | ios::out);
                        if (!fPatient)
                        {
                                cout << "NOT FOUND";
                                system("pause");
                                goto lPatient;
                        }
                        fPatient.seekp(0, ios::end);
                        Patient1.enter();
                        fPatient.write((char *)&Patient1, sizeof(Patient1));
                        if (fPatient.bad())
                        {
                                cout << "ERROR";
                                system("pause");
                                goto lPatient;
                        }
                        cout << "\nData Successfully Written..\n";
                        fPatient.close();
                        system("pause");
                        goto lPatient;
                }

                case 2:
                {
                        // Update existing Patient details
                        system("cls");
                        fPatient.open("./Data/Patient.dat", ios::in | ios::out);
                        if (!fPatient)
                        {
                                cout << "NOT FOUND";
                                system("pause");
                                goto lPatient;
                        }
                        cout << "\n\n\t\t\t\t\tCU CLINIC OPD SOFTWARE\n\n";
                        cout << "\t\t\tUPDATE\n\n";
                        cout << "Enter Patient Identification Number :";
                        int i;
                        cin >> i;
                        fPatient.seekp(0, ios::beg);
                        int k = 0;
                        while (!fPatient.eof())
                        {
                                if (fPatient.eof())
                                {
                                        break;
                                }
                                int n;
                                n = fPatient.tellg();
                                Patient patient1;
                                fPatient.read((char *)&patient1, sizeof(patient1));
                                if (patient1.get_patientId() == i)
                                {
                                        cout << "\nOriginal :\n";
                                        patient1.disp();
                                        k = 1;
                                        cout << "\n\n\t Press 0 to go ahead\n\tPress 1 to go back_ ";
                                        int m;
                                        cin >> m;
                                        if (m == 1)
                                        {
                                                continue;
                                        }
                                        cout << "\nEnter New One's :\n";
                                        patient1.enter();
                                        fPatient.seekp(n, ios::beg);
                                        fPatient.write((char *)&patient1, sizeof(patient1));
                                        break;
                                }
                        }
                        fPatient.close();
                        if (k == 0)
                        {
                                cout << "\nNOT FOUND";
                                system("pause");
                                goto lPatient;
                        }
                        goto lPatient;
                }

                case 3:
                {
                        // Remove a Patient
                        fPatient.open("./Data/Patient.dat", ios::in | ios::out);
                        system("cls");
                        if (!fPatient)
                        {
                                cout << "File not found";
                                system("pause");
                                goto lPatient;
                        }
                        ofstream tmp;
                        tmp.open("./Data/tempatient.dat", ios::out | ios::trunc);
                        int k = 0;
                        int i = 0;
                        cout << "\n\n\t\t\tREMOVE\n\n";
                        cout << "Enter Patient Identification Number: \n";
                        cin >> i;
                        fPatient.seekg(0, ios::beg);
                        while (!fPatient.eof())
                        {
                                if (fPatient.eof())
                                {
                                        break;
                                }
                                fPatient.read((char *)&Patient1, sizeof(Patient1));
                                if (Patient1.get_patientId() == i)
                                {
                                        Patient1.disp();
                                        k = 1;
                                        cout << "Are you sure you want to delete this (yes=1 no=0)? _";
                                        int n;
                                        cin >> n;
                                        if (n == 0)
                                        {
                                                tmp.write((char *)&Patient1, sizeof(Patient1));
                                        }
                                }
                                else
                                {
                                        tmp.write((char *)&Patient1, sizeof(Patient1));
                                }
                        }
                        if (k == 0)
                        {
                                cout << "Patient not present\n";
                                system("pause");
                                goto lPatient;
                        }
                        tmp.close();
                        fPatient.close();
                        remove("./Data/Patient.dat");
                        remove("./Data/Patient.dat");
                        rename("./Data/tempatient.dat", "./Data/Patient.dat");
                        goto lPatient;
                }

                case 4:
                {
                        // View Details
                        system("cls");
                        fPatient.open("./Data/Patient.dat", ios::in | ios::out);
                        if (!fPatient)
                        {
                                cout << "NOT FOUND";
                                system("pause");
                                goto lPatient;
                        }
                        cout << "\n\n\t\t\t\t\tCU CLINIC OPD SOFTWARE\n\n";
                        cout << "Enter Patient Id to view:";
                        int i;
                        cin >> i;
                        fPatient.seekp(0, ios::beg);
                        int k = 0;
                        while (!fPatient.eof())
                        {
                                if (fPatient.eof())
                                {
                                        break;
                                }
                                int n;
                                n = fPatient.tellg();
                                Patient doc2;
                                fPatient.read((char *)&doc2, sizeof(doc2));
                                if (doc2.get_patientId() == i)
                                {
                                        cout << "\nOriginal :\n";
                                        doc2.disp();
                                        fPatient.close();
                                        system("pause");
                                        goto lPatient;
                                }
                        }
                        fPatient.close();
                        goto lPatient;
                }

                case 5:
                {
                        break;
                }

                default:
                {
                        break;
                }
        }
}