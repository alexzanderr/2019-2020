#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>

using namespace std;

void input();
void search();
void edit();
void displayAll();


int main()
{
	system("cls");
	system("title Employee Databse Program");
	cout << "Enter choice:\n" << endl;
	cout << "[1].Input new employee" << endl;
	cout << "[2].Search for an employee by ID number" << endl;
	cout << "[3].Edit an existing employee's information" << endl;
	cout << "[4].Display all Employees" << endl;
	cout << "[5].Exit" << endl;

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		input();
		break;
	case 2:
		search();
		break;
	case 3:
		edit();
		break;
	case 4:
		displayAll();
		break;
	case 5:
		return 0;
	}
	return 0;
}

void input()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	string fileName;
	double salary;
	int empId;
	int age;

	cout << "Input first name:";
	cin >> fname;
	cout << "Input middle name:";
	cin >> mname;
	cout << "Input last name:";
	cin >> lname;
	cout << "Input employee age:";
	cin >> age;
	cout << "Input employee salary:";
	cin >> salary;
	cout << "Input Id number:";
	cin >> empId;
	string empId2 = to_string(empId);
	empId2.append(".txt");

	ofstream newemployee(empId2);
	newemployee << fname << ' ' << mname << ' ' << lname << ' ' << empId << ' ' << salary << ' ' << age << endl;
	newemployee.close();
	ofstream dir("directory.txt", ios::app);
	dir << fname << ' ' << mname << ' ' << lname << ' ' << empId << ' ' << salary << ' ' << age << endl;
	dir.close();
	main();
}
void search()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	string fileName;
	double salary;
	int empId;
	int thrw;
	int age;
	cout << "Enter emplyee ID number:";
	cin >> empId;
	string empId2 = to_string(empId);
	empId2.append(".txt");

	ifstream employee(empId2);
	while (employee >> fname >> mname >> lname >> thrw >> salary >> age)
	{
		int mnameLength = mname.size();
		int lnameLength = lname.size();
		int fnameLength = fname.size();
		int lengthTotal = fnameLength + lnameLength + mnameLength;

		string answer;
		cout << "Is this the correct employee?[y/n]" << endl;
		cout << fname << ' ' << mname << ' ' << lname << endl;
		cin >> answer;

		if (answer == "y")
		{
			system("cls");
			cout << "Name";
			for (int y = 1; y < lengthTotal; y++)
			{
				cout << " ";
			}
			cout << "Age";
			for (int z = 1; z < 2; z++)
			{
				cout << " ";
			}
			cout << "Salary";
			cout << "ID#" << endl;
			for (int x = 1; x < lengthTotal + 20; x++)
			{
				cout << "-";
			}
			cout << ' ' << endl;
			cout << fname << ' ' << mname << ' ' << lname << ' ' << age << ' ' << "$" << salary << ' ' << empId << endl;
		}

	}
	system("pause");
	main();
}

void edit()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	string newfname;
	string newmname;
	string newlname;
	string decision;
	int empId;
	int age;
	int newage;
	int thrw;
	double salary;
	double newsalary;
	cout << "Enter the Employee ID of the Employee whose data you wish to edit:";
	cin >> empId;
	string empId2 = to_string(empId);
	empId2.append(".txt");
	ifstream employee(empId2);
	while (employee >> fname >> mname >> lname >> thrw >> salary >> age)
	{
		cout << "Is this the Employee that you wish to edit?[y/n]" << endl;
		cout << fname << ' ' << mname << ' ' << lname << endl;
		cin >> decision;
		if (decision == "y")
		{
			system("cls");
			cout << "Current information:" << endl;

			int mnameLength = mname.size();
			int fnameLength = fname.size();
			int lnameLength = lname.size();
			int lengthTotal = lnameLength + fnameLength + mnameLength;
			cout << "Name";
			for (int y = 1; y < lengthTotal; y++)
			{
				cout << " ";
			}
			cout << "Age";
			for (int z = 1; z < 2; z++)
			{
				cout << " ";
			}
			cout << "Salary";
			cout << "ID#" << endl;
			for (int x = 1; x < lengthTotal + 17; x++)
			{
				cout << "-";
			}
			cout << ' ' << endl;


			cout << fname << ' ' << mname << ' ' << lname << ' ' << age << ' ' << salary << ' ' << empId << endl;
			cout << "Enter new first name:";
			cin >> newfname;
			cout << "Enter new middle name:";
			cin >> newmname;
			cout << "Enter new last name:";
			cin >> newlname;
			cout << "Enter new age:";
			cin >> newage;
			cout << "Enter new salary";
			cin >> newsalary;
		}
		if (decision == "n")
		{
			main();
		}
		employee.close();
		ofstream employee2(empId2);
		employee2 << newfname << ' ' << newmname << ' ' << newlname << ' ' << empId << ' ' << newsalary << ' ' << newage << endl;
		employee2.close();
	}

	main();
}
void displayAll()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	int age;
	double salary;
	int empId;

	cout << "Entire Employee database" << endl;
	cout << "------------------------" << endl;
	ifstream dir("directory.txt");
	while (dir >> fname >> mname >> lname >> age >> empId >> salary)
	{
		cout << fname << ' ' << mname << ' ' << lname << ' ' << age << ' ' << salary << empId << endl;
	}
	system("pause");
	main();
}