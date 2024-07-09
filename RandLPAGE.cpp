#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

// functions of the content
void Login();
void Registration();
void Forgot();

int main()
{
        // intro
        int choose;

        cout << " \t\t\t_______________________________________________________________________________\n\n\n";
        cout << " \t\t\t-------------------------------------Welcome----------------------------------\n\n\n";
        cout << " \t\t\t_______________________________________________________________________________\n\n\n";

        // choice page

        cout << "1. Enter 1 Login\n\n";

        cout << "2. Enter 2 New Registration\n\n";

        cout << "3. Enter 3 Forgot Password\n\n";

        cout << "4. Enter 4 Exit\n\n";

        cout << "choose from the options"<<endl<<endl;

        cin >> choose;

        // input case

        switch (choose)
        {
        case 1:
                Login();
                break;
        case 2:
                Registration();
                break;
        case 3:
                Forgot();
                break;
        case 4:
                cout << " \t\t\t\t\t\t || Thank You Please visit Again ||";
                break;

        default:
                system("cls");
                cout << " \t\t\t\t\t\t || please enter the number from the above list ||";
                main();
        }
}

// Function for login form

void Login()
{

        int count;
        string username, password, user, pass;
        system("cls");

        cout << " * Enter the Username -- " << endl;
        cin >> username;
        cout << " * Enter the Password -- " << endl;
        cin >> password;

        ifstream input("data.txt");
        while (input >> user >> pass)
        {

                if (user == username && pass == password)
                {
                        count = 1;
                        system("cls");
                }
        }

        input.close();
        if (count == 1)
        {
                cout << " || Login Successfull || \n ||  Welcome!  ||";
                main();
        }
        else
        {
                cout << " || Login Failed || \n || Please Register Yourself || \n";
                main();
        }
}
// function for registration form

void Registration()
{
        string nusername, npassword, nuser, npass;

        cout << " * Enter New Username -- \n";
        cin >> nusername;
        cout << " * Enter the New Password -- \n";
        cin >> npassword;

        system("cls");
        ofstream f2("data.txt", ios::app);
        f2.close();
        f2 << nuser << npass << endl;
        system("cls");
        cout << " || Registration successfull || \n";
        main();
}

// function for login form

void Forgot()
{
        int option;
        system("cls");
        cout << " || Forgot Password || \n || No Worries || \n\n ";
        cout << " * Press 1 to search your id by username *" << endl
             << endl;
        cout << "  * Press 2 to go back to main menu *" << endl;
        cout << "\t\t\n    || Enter your choice || :  ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
                int count = 0;
                string suserid, sid, spass;
                cout << " * Enter the username : " << endl;
                cin >> suserid;

                ifstream f1("data.txt");
                while (f1 >> sid >> spass)
                {
                        if (sid == suserid)
                        {
                                count = 1;
                        }
                }
                f1.close();
                if (count == 1)
                {
                        cout << " || Your account has been found ||\n";
                        cout << " || Your password is :  " << spass;
                        main();
                }
                else
                {
                        cout << " || OOPS ! Looks like we do not have your account || \n || Please register yourself ||\n\n ";
                        main();
                }
                break;
        }
        case 2:
        {
                main();
        }
        default:
                cout << "\t\t\t  || Please select from the options  || \n\n"
                     << endl;
                Forgot();
        }
}
