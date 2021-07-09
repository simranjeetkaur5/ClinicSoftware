#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class User
{
private:
        int u_id;
        char name[30];
        char password[30];
        fstream fUser;

public:
        void enter();
        void disp();
        int userMenu();
        int get__u_id() { return u_id; }
        char *get__name() { return name; }
        char *get__password() { return password; }
};

void User::enter()
{
        system("cls");
        cout << "\nEnter User Identification Number :";
        cin >> u_id;
        cin.ignore(5, '\n');
        cout << "\nEnter User's Name :";
        gets(name);
        cout << "\nEnter User's Password :";
        gets(password);
}

void User::disp()
{
        system("cls");
        cout << "\t\t\t*** Report - User Details ***\n\n";
        cout << "\nUser Identification Number :" << u_id;
        cout << "\nUser's Name :";
        puts(name);
        cout << "User's Password :";
        puts(password);
}

int User::userMenu()
{
        int opt;
lUser:
        system("cls");
        cout << "\t\t\t:: USER MANAGEMENT ::\n\n";
        cout << "\t\t\t1. Add new User\n";
        cout << "\t\t\t2. Update existing User details\n";
        cout << "\t\t\t3. Remove a User\n";
        cout << "\t\t\t4. View User Info\n";
        cout << "\t\t\t5. Back\n\n\n";
        cout << "\t\t\tEnter your option : ";
        cin >> opt;
        User user1;
        switch (opt)
        {
                case 1:
                {
                        // Add new user
                        fUser.open("./Data/User.dat", ios::in | ios::out);
                        if (!fUser)
                        {
                                cout << "NOT FOUND";
                                system("pause");
                                goto lUser;
                        }
                        fUser.seekp(0, ios::end);
                        user1.enter();
                        fUser.write((char *)&user1, sizeof(user1));
                        if (fUser.bad())
                        {
                                cout << "ERROR";
                                system("pause");
                                goto lUser;
                        }
                        cout << "\nData Successfully Written..\n";
                        fUser.close();
                        system("pause");
                        goto lUser;
                }

                case 2:
                {
                        // Update existing User details
                        system("cls");
                        fUser.open("./Data/User.dat", ios::in | ios::out);
                        if (!fUser)
                        {
                                cout << "NOT FOUND";
                                system("pause");
                                goto lUser;
                        }
                        cout << "\n\n\t\t\t\t\tCU CLINIC OPD SOFTWARE\n\n";
                        cout << "\t\t\tUPDATE\n\n";
                        cout << "Enter User Identification Number :";
                        int i;
                        cin >> i;
                        fUser.seekp(0, ios::beg);
                        int k = 0;
                        while (!fUser.eof())
                        {
                                if (fUser.eof())
                                {
                                        break;
                                }
                                int n;
                                n = fUser.tellg();
                                User doc2;
                                fUser.read((char *)&doc2, sizeof(doc2));
                                if (doc2.get__u_id() == i)
                                {
                                        cout << "\nOriginal :\n";
                                        doc2.disp();
                                        k = 1;
                                        cout << "\n\n\t Press 0 to go ahead\n\tPress 1 to go back_ ";
                                        int m;
                                        cin >> m;
                                        if (m == 1)
                                        {
                                                continue;
                                        }
                                        cout << "\nEnter New One's :\n";
                                        doc2.enter();
                                        fUser.seekp(n, ios::beg);
                                        fUser.write((char *)&doc2, sizeof(doc2));
                                        break;
                                }
                        }
                        fUser.close();
                        if (k == 0)
                        {
                                cout << "\nNOT FOUND";
                                system("pause");
                                goto lUser;
                        }
                        goto lUser;
                }

                case 3:
                {
                        // Remove a User
                        fUser.open("./Data/User.dat", ios::in | ios::out);
                        system("cls");
                        if (!fUser)
                        {
                                cout << "File not found";
                                system("pause");
                                goto lUser;
                        }
                        ofstream tmp;
                        tmp.open("./Data/tem.dat", ios::out | ios::trunc);
                        int k = 0;
                        int i = 0;
                        cout << "\n\n\t\t\tREMOVE\n\n";
                        cout << "Enter User Identification Number: \n";
                        cin >> i;
                        fUser.seekg(0, ios::beg);
                        while (!fUser.eof())
                        {
                                if (fUser.eof())
                                {
                                        break;
                                }
                                fUser.read((char *)&user1, sizeof(user1));
                                if (user1.get__u_id() == i)
                                {
                                        user1.disp();
                                        k = 1;
                                        cout << "Are you sure you want to delete this (yes=1 no=0)? _";
                                        int n;
                                        cin >> n;
                                        if (n == 0)
                                        {
                                                tmp.write((char *)&user1, sizeof(user1));
                                        }
                                }
                                else
                                {
                                        tmp.write((char *)&user1, sizeof(user1));
                                }
                        }
                        if (k == 0)
                        {
                                cout << "User not present\n";
                                system("pause");
                                goto lUser;
                        }
                        tmp.close();
                        fUser.close();
                        remove("./Data/User.dat");
                        remove("./Data/User.dat");
                        rename("./Data/tem.dat", "./Data/User.dat");
                        goto lUser;
                }

                case 4:
                {
                        // View Details
                        system("cls");
                        fUser.open("./Data/User.dat", ios::in | ios::out);
                        if (!fUser)
                        {
                                cout << "NOT FOUND";
                                system("pause");
                                goto lUser;
                        }
                        cout << "\n\n\t\t\t\t\tCU CLINIC OPD SOFTWARE\n\n";
                        cout << "Enter User Id to view:";
                        int i;
                        cin >> i;
                        fUser.seekp(0, ios::beg);
                        int k = 0;
                        while (!fUser.eof())
                        {
                                if (fUser.eof())
                                {
                                        break;
                                }
                                int n;
                                n = fUser.tellg();
                                User doc2;
                                fUser.read((char *)&doc2, sizeof(doc2));
                                if (doc2.get__u_id() == i)
                                {
                                        cout << "\nOriginal :\n";
                                        doc2.disp();
                                        fUser.close();
                                        system("pause");
                                        goto lUser;
                                }
                        }
                        fUser.close();
                        goto lUser;
                }

                case 5:
                {
                        
                        return 5;
                }

                default:
                {
                        break;
                }
        }
}