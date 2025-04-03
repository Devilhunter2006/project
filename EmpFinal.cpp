#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>
using namespace std;

int i = 0;

struct emp
{
    int id;
    string aname;
    string pass;
    string name, address, phone, dept;
    string salary;
} e[50];
void ani()
{
    cout << "Processing your request ";
    for (int i = 0; i < 4; i++)
    {
        cout << " .";
        Sleep(500);
    }
}
bool verify()
{

    cout << "Enter Name" << endl;
    cin >> e[i].aname;
    cout << "Enter password" << endl;
    cin >> e[i].pass;
    if (e[i].aname == "Varun" && e[i].pass == "123#")
    {
        cout << "Welcome" << endl;
        ani();
        return true;
    }
    else
    {
        system("color 4");
        cout << "You are not authorized" << endl;
        Sleep(1000);
        return false;
    }
}

bool isNumeric(const string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]) && !isspace(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool isAlphabet(const string &str)
{
    for (char c : str)
    {
        if (!isalpha(c) && !isspace(c))
        {
            return false;
        }
    }
    return true;
}

void insert()
{
    system("cls");
    string idc;
    cout << "Insert Record" << endl;
    e[i].id = i + 1;

    cin.ignore();
    while (true)
    {
        cout << "Enter employee name : ";
        // cin.ignore();
        getline(cin, e[i].name);
        if (!isAlphabet(e[i].name))
        {
            cout << "Error: Employee name should not contain numbers." << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter employee department : ";
        getline(cin, e[i].dept);
        if (isNumeric(e[i].dept))
        {
            cout << "Error: Employee department should not contain numbers." << endl;
        }
        else
        {
            break;
        }
    }
    cout << "Enter employee address : ";
    getline(cin, e[i].address);
    while (true)
    {
        cout << "Enter employee phone : ";
        getline(cin, e[i].phone);
        if (!isNumeric(e[i].phone))
        {
            cout << "Error: Phone number must be numeric." << endl;
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << "Enter employee salary : ";
        getline(cin, e[i].salary);
        if (!isNumeric(e[i].salary))
        {
            cout << "Error:  salary must be numeric." << endl;
        }
        else
        {
            break;
        }
    }

    // cout << "Enter employee salary : ";
    // cin >> e[i].salary;
    i++;
    ani();
    cout << "\n\n ****Record Inserted**** ";
    Sleep(1000);
}
void searching()
{
    system("cls");

    if (i == 0)
    {
        cout << "\n\n DATABASE IS EMPTY";
        Sleep(1000);
    }
    else
    {
        string searching;
        int searchm;

        cout << "Enter search criteria:" << endl;
        cout << "1. Name" << endl;
        cout << "2. ID" << endl;
        cout << "3. Department" << endl;
        cout << "Enter your choice: ";
        cin >> searchm;
        if (searchm > 3)
        {
            cout << "Invalid chocie " << endl;
            return;
        }
        cin.ignore();
        cout << "Enter search term: ";
        getline(cin, searching);
        bool found = false;
        for (int a = 0; a < i; a++)
        {
            switch (searchm)
            {

            case 1:
                if (e[a].name.find(searching) != string::npos)
                {
                    cout << "Employee ID is " << e[a].id << endl;
                    cout << "Employee Name is " << e[a].name << endl;
                    cout << "Employee address is " << e[a].address << endl;
                    cout << "Employee phone number is " << e[a].phone << endl;
                    cout << "Employee department is " << e[a].dept << endl;
                    cout << "Employee salary is " << e[a].salary << endl;
                    cout << "\n\n";
                    found = true;
                }
                break;
            case 2:
                if (to_string(e[a].id) == searching)
                {
                    cout << "Employee ID is " << e[a].id << endl;
                    cout << "Employee Name is " << e[a].name << endl;
                    cout << "Employee address is " << e[a].address << endl;
                    cout << "Employee phone number is " << e[a].phone << endl;
                    cout << "Employee department is " << e[a].dept << endl;
                    cout << "Employee salary is " << e[a].salary << endl;
                    cout << "\n\n";
                    found = true;
                }
                break;
            case 3:
                if (e[a].dept.find(searching) != string::npos)
                {
                    cout << "Employee ID is " << e[a].id << endl;
                    cout << "Employee Name is " << e[a].name << endl;
                    cout << "Employee address is " << e[a].address << endl;
                    cout << "Employee phone number is " << e[a].phone << endl;
                    cout << "Employee department is " << e[a].dept << endl;
                    cout << "Employee salary is " << e[a].salary << endl;
                    cout << "\n\n";
                    found = true;
                }
                break;
            default:
                cout << "Invalid search criteria. Please try again." << endl;
                return;
            }
            break;
        }

        if (!found)
        {
            cout << "Record not found." << endl;
        }

        cout << "Press 1 to go back to the main menu: ";
        string choice;
        while (true)
        {
            cin >> choice;
            if (choice == "1")
            {
                break;
            }
            else
            {
                cout << "Invalid choice. Press 1 to go back to the main menu: ";
            }
        }
    }
}
void update()
{
    system("cls");
    int sid;

    if (i == 0)
    {
        cout << "\n\n DATABASE IS EMPTY";
        return;
    }

    cout << "Enter ID you want to update: ";
    cin >> sid;
    cin.ignore();

    bool found = false;
    for (int a = 0; a < i; a++)
    {
        if (sid == e[a].id)
        {
            found = true;

            while (true)
            {
                cout << "Enter new Employee Name: ";
                getline(cin, e[a].name);
                if (!isAlphabet(e[a].name))
                {
                    cout << "Error: Employee name should only contain letters and spaces. Please try again." << endl;
                }
                else
                {
                    break;
                }
            }

            cout << "Enter new Employee Address: ";
            getline(cin, e[a].address);

            while (true)
            {
                cout << "Enter new Employee Phone Number: ";
                getline(cin, e[a].phone);
                if (!isNumeric(e[a].phone))
                {
                    cout << "Error: Phone number must be numeric. Please try again." << endl;
                }
                else
                {
                    break;
                }
            }

            cout << "Enter new Employee Department: ";
            getline(cin, e[a].dept);

            while (true)
            {
                cout << "Enter new Employee ID: ";
                string new_id;
                getline(cin, new_id);
                if (!isNumeric(new_id))
                {
                    cout << "Error: ID must be numeric. Please try again." << endl;
                }
                else
                {
                    e[a].id = stoi(new_id);
                    break;
                }
            }

            // Update employee salary
            while (true)
            {
                cout << "Enter new Employee Salary: ";
                getline(cin, e[a].salary);
                if (!isNumeric(e[a].salary))
                {
                    cout << "Error: Salary must be numeric. Please try again." << endl;
                }
                else
                {
                    break;
                }
            }

            ani();
            cout << "Record Updated" << endl;
            // Break the loop after updating the record
            break;
        }
    }

    if (!found)
    {
        cout << "Record not found." << endl;
        system("color 4");
        Sleep(1000);
    }
}

void dele()
{
    system("cls");
    int sid;
    if (i == 0)
    {
        cout << "\n\n DATABASE IS EMPTY";
    }
    else
    {
        cout << "Enter id you want to delete: ";
        cin >> sid;
        for (int a = 0; a < i; a++)
        {
            if (sid == e[a].id)
            {
                for (int k = a; k < i - 1; k++)
                {
                    e[k] = e[k + 1];
                }
                i--;
                cout << "Record Deleted" << endl;
                return;
            }
        }
        cout << "Record Not available " << endl;
    }
}

void show()
{
    system("cls");
    if (i == 0)
    {
        cout << "\n\n DATABASE IS EMPTY" << endl;
    }
    else
    {
        for (int a = 0; a < i; a++)
        {
            cout << "Employee ID is " << e[a].id << endl;
            cout << "Employee Name is " << e[a].name << endl;
            cout << "Employee address is " << e[a].address << endl;
            cout << "Employee phone number is " << e[a].phone << endl;
            cout << "Employee department is " << e[a].dept << endl;
            cout << "Employee salary is " << e[a].salary << endl;
            cout << "\n\n";
        }
    }
    cout << "Press 1 to go back to the main menu: ";
    string choice;
    cin >> choice;
    while (choice != "1")
    {
        cout << "Invalid choice. Press 1 to go back to the main menu: ";
        cin >> choice;
    }
}
void centering(string st)
{
    int screenwidth = 80;
    int textwidth = 20;
    int padding = (screenwidth - textwidth);

    cout << setw(padding) << " " << st << " " << setw(padding) << right;
}

int main()
{

    centering("Verification");
    cout << "\n\n";
    system("color A");
    int attempts = 2;

    while (attempts--)
    {
        centering("Verification");
        cout << "\n\n";
        system("color A");

        if (verify())
        {
            // Successful verification
            break;
        }
        else
        {
            if (attempts > 0)
            {
                system("color 4");
                cout << "Incorrect credentials. Please try again.\n";
                Sleep(1000);
            }
            else
            {
                system("color 4");
                cout << "Too many failed attempts. Exiting...\n";
                Sleep(1000);
                return -1;
            }
        }
    }
    int schoice;
    int choices;
    string choice;
    // system("cls");
    while (choices != 6)
    {
        system("cls");
        centering("Employee Management System");

        system("color 1");

        cout << "\n\n Press 1 For New Employee" << endl;
        cout << "\n\n Press 2 For Searching Employee" << endl;
        cout << "\n\n Press 3 For Upadating Employee Details" << endl;
        cout << "\n\n Press 4 For Deleting" << endl;
        cout << "\n\n Press 5 List of Employee" << endl;
        cout << "\n\n 6 Exit" << endl;
        cout << "\n\n Enter your choice: ";
        cin >> choice;
        if (!isNumeric(choice))
        {
            system("color 2");
            cout << "Dont use alphabet or special characters " << endl;
            Sleep(1000);
            continue;
        }
        system("cls");
        system("color 1");
        choices = stoi(choice);
        switch (choices)
        {
        case 1:
            insert();
            break;
        case 2:
            searching();
            // system("cls");
            Sleep(1000);
            break;
        case 3:
            update();
            Sleep(1000);
            break;
        case 4:
            dele();
            Sleep(1000);
            break;
        case 5:
            show();
            Sleep(1000);
            break;
        case 6:

            cout << "BYE BYE";
            Sleep(1000);
            Sleep(1000);
            break;

        default:
            cout << "Wrong choice, try again" << endl;
            Sleep(1000);
            Sleep(1000);
            break;
        }
    }
    return 0;
}