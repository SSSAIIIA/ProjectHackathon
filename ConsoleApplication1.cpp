#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class ITRE
{
private:
	char Surname[21];
	char Name[21];
	char Cathedra[5];
	char num[11];
	short int year;
	float AvgGrades;
public:
	void AddStudentManual(ITRE* Student, const char* fname, const char* lname, const char* Caphedra, short int yr, float Avg, const char* phone, short int& size)
	{
		strcpy(Student[size].Surname, fname);
		strcpy(Student[size].Name, lname);
		strcpy(Student[size].Cathedra, Caphedra);
		Student[size].year = yr;
		Student[size].AvgGrades = Avg;
		strcpy(Student[size].num, phone);
		size++;
	}
	void AddStudent(ITRE* Student, short int& size)
	{
		cin.ignore();

		cout << "Enter Surname for " << size + 1 << " student:" << endl;
		cin.getline(Student[size].Surname, sizeof(Student[size].Surname));

		cout << "Enter Name of " << size + 1 << " student:" << endl;
		cin.getline(Student[size].Name, sizeof(Student[size].Name));

		short int select;
		cout << "Select Cathedra of " << size + 1 << " student:" << endl;
		cout << "1-ELI\n2-EA\n3-TK\nSelect:";
		cin >> select;
		do {
			switch (select)
			{
			case 1:
				strcpy(Student[size].Cathedra, "ELI");
				break;
			case 2:
				strcpy(Student[size].Cathedra, "EA");
				break;
			case 3:
				strcpy(Student[size].Cathedra, "TK");
				break;
			default:
				cout << "Try again!" << endl;
				cin >> select;
				continue;
			}
			break;
		} while (true);

		cout << "Enter a year of entrance " << size + 1 << " student:" << endl;
		cin >> Student[size].year;

		cout << "Enter Average grade for " << size + 1 << " student:" << endl;
		cin >> Student[size].AvgGrades;

		cin.ignore();
		cout << "Enter phone number for " << size + 1 << " student:" << endl;
		cin.getline(Student[size].num, sizeof(Student[size].num));

		size++;
	}
	void DeleteStudent(ITRE* Student, short int& size)
	{
		int num;
		cout << "Enter number of student:" << endl;
		cin >> num;
		if (num > size || num < 1)
		{
			cout << "No these student" << endl;
			system("pause 0");
		}
		else
		{
			for (int i = num - 1; i < size; i++)
				swap(Student[i], Student[i + 1]);
			size--;
		}
	}
	void ShowallStudents(ITRE* Student, short int size)
	{
		system("CLS");
		for (int i = 0; i < size; i++)
		{
			cout << "------------------------------" << endl;
			cout << i + 1 << " - ";
			cout << Student[i].Surname << " - ";
			cout << Student[i].Name << " - ";
			cout << Student[i].Cathedra << " - ";
			cout << Student[i].year << " - ";
			cout << Student[i].AvgGrades << " - ";
			cout << Student[i].num << endl;
			cout << "------------------------------" << endl;
		}
		system("pause 0");
	}
	void ShowStudent(ITRE* Student, short int index)
	{
		cout << "------------------------------" << endl;
		cout << index + 1 << " - ";
		cout << Student[index].Surname << " - ";
		cout << Student[index].Name << " - ";
		cout << Student[index].Cathedra << " - ";
		cout << Student[index].year << " - ";
		cout << Student[index].AvgGrades << " - ";
		cout << Student[index].num << endl;
		cout << "------------------------------" << endl;
	}
	void SearchbySurname(ITRE* Student, short int size)
	{

		char TMP[21];
		cout << "Enter surname:";
		cin >> TMP;
		cout << "Was found:" << endl;
		for (int i = 0; i < size; i++)
			if (strcmp(TMP, Student[i].Surname) == 0)
				ShowStudent(Student, i);

		system("pause 0");
	}
	void SearchbyPhoneNumber(ITRE* Student, short int size)
	{
		char TMP[20];
		cout << "Enter phone number:";
		cin >> TMP;
		cout << "Was found:" << endl;
		for (int i = 0; i < size; i++)
			if (strcmp(TMP, Student[i].num) == 0)
				ShowStudent(Student, i);

		system("pause 0");
	}
	void ShowallinCathedra(ITRE* Student, short int size)
	{
		short int select;
		cout << "Select Cathedra:\n1-ELI\n2-EA\n3-TK\nSelect:";
		cin >> select;
		switch (select)
		{
		case 1:
			for (int i = 0; i < size; i++)
				if (strcmp("ELI", Student[i].Cathedra) == 0)
					ShowStudent(Student, i);
			break;
		case 2:
			for (int i = 0; i < size; i++)
				if (strcmp("EA", Student[i].Cathedra) == 0)
					ShowStudent(Student, i);
			break;
		case 3:
			for (int i = 0; i < size; i++)
				if (strcmp("TK", Student[i].Cathedra) == 0)
					ShowStudent(Student, i);
			break;
		default:
			cout << "No cathedra!" << endl;
			break;
		}
		system("pause 0");
	}
	void Showallbybestgrades(ITRE* Student, short int size)
	{
		for (int i = 1; i < size; i++)
		{
			if (Student[i - 1].AvgGrades < Student[i].AvgGrades)
			{
				swap(Student[i - 1], Student[i]);
				i = 0;
			}
		}
		ShowallStudents(Student, size);
	}
	void Showallbyworstgrades(ITRE* Student, short int size)
	{
		for (int i = 1; i < size; i++)
		{
			if (Student[i - 1].AvgGrades > Student[i].AvgGrades)
			{
				swap(Student[i], Student[i - 1]);
				i = 0;
			}
		}
		ShowallStudents(Student, size);
	}
	void ShowallbyAlphabeth(ITRE* Student, short int size)
	{
		bool perest;
		for (int i = 0; i < size - 1; i++)
		{
			perest = false;
			for (int j = 0; j < size - i - 1; j++)
			{
				if (strcmp(Student[j].Surname, Student[j + 1].Surname) > 0)
				{
					swap(Student[j], Student[j + 1]);
					perest = true;
				}
			}
			if (perest == 0)
				break;
		}

		ShowallStudents(Student, size);
	}
};
short int Menu()
{
	system("CLS");
	short int menu;
	cout << "1 - Add student" << endl;
	cout << "2 - Delete student" << endl;
	cout << "3 - Show all student" << endl;
	cout << "4 - Search by Surname" << endl;
	cout << "5 - Search by Phone number" << endl;
	cout << "6 - Show all in Cathedra" << endl;
	cout << "7 - Show all by best grades" << endl;
	cout << "8 - Show all by worst grades" << endl;
	cout << "9 - Show all by Alphabeth" << endl;
	cout << "0 - Exit" << endl << endl;
	cout << "Choose item:";
	cin >> menu;
	return menu;
}

int main()
{
	ITRE* Student = new ITRE[100];
	short int count = 0;

	Student->AddStudentManual(Student, "Draganchuk", "Oleksandr", "ELI", 2021, 58.5, "0502221229", count);
	Student->AddStudentManual(Student, "Khomik", "Maksym", "TK", 2022, 50.5, "0991458455", count);
	Student->AddStudentManual(Student, "Smyk", "Dem", "EA", 2019, 85.2, "0667774566", count);
	Student->AddStudentManual(Student, "Guk", "Victor", "ELI", 2022, 69.9, "067654444l", count);
	Student->AddStudentManual(Student, "Karpov", "Nazar", "TK", 2021, 59.1, "0506545222", count);

	do
	{
		switch (Menu())
		{
		case 1:
			Student->AddStudent(Student, count);
			break;
		case 2:
			Student->DeleteStudent(Student, count);
			break;
		case 3:
			Student->ShowallStudents(Student, count);
			break;
		case 4:
			Student->SearchbySurname(Student, count);
			break;
		case 5:
			Student->SearchbyPhoneNumber(Student, count);
			break;
		case 6:
			Student->ShowallinCathedra(Student, count);
			break;
		case 7:
			Student->Showallbybestgrades(Student, count);
			break;
		case 8:
			Student->Showallbyworstgrades(Student, count);
			break;
		case 9:
			Student->ShowallbyAlphabeth(Student, count);
			break;

		case 0:delete[]Student;
			return 0;
		default:
			cout << "There is no such menu item!" << endl;
			system("pause 0");
			break;
		}
	} while (true);

	cout << endl << endl;

	system("color F0");
	system("pause 0");
	return 0;
}