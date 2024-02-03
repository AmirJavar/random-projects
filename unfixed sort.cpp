#include <iostream>
#include <string>
using namespace std;

bool Ascending(string, string);
bool Descending(string, string);
void swap(string* const, string* const);
void outputArr(string [], int);
void selectionSort(string arrStuNames[], int stuSize, bool (*compare) (string, string));
int main()
{
	cout << "Please enter students names and type done when you where done." << endl;

	int stuSize = 0;
	string * arrStuNames = new string [stuSize];
	string stuName;

	while (stuName != "done")
	{
		cout << "Enter student " << stuSize + 1 << "'s full name : "; //students names get added to "arrStuNames" array and size grows by 1
		getline(cin, stuName);
		arrStuNames[stuSize] = stuName;
		stuSize++;
	}
	stuSize--;
	cout << "How would you like the list sorted ? \n" << "1. Ascending \n 2. Descending\n" << "Type your choice and press enter : ";
	int choice;
	cin >> choice;

	if (choice == 1)
		selectionSort(arrStuNames, stuSize, Ascending);
	else if (choice == 2)
		selectionSort(arrStuNames, stuSize, Descending);
	else
		cout << "Entered choice is not valid.";

	outputArr(arrStuNames, stuSize);
	delete arrStuNames;
}
void selectionSort(string arrStuNames[], int stuSize, bool (*compare) (string, string))
{
	int temp;
	for (int i = 0; i < stuSize - 1; i++)
	{
		temp = i;
		for (int j = i + 1; j < stuSize; j++)
		{
			if (!(*compare) (arrStuNames[temp], arrStuNames[j]))
				temp = j;
		}
		swap(&arrStuNames[temp], &arrStuNames[i]);
	}
}
bool Ascending(string a, string b)
{
	return b > a;
}
bool Descending(string a, string b)
{
	return a > b;
}
void swap(string* const a, string* const b)
{
	string temp = *a;
	*a = *b;
	*b = temp;
}
void outputArr(string arrStuNames[], int stuSize)
{
	cout << "Students names sorted \n" << "==================\n";
	for (int i = 0; i < stuSize; i++)
	{
		cout << arrStuNames[i] << endl;
	}
	cout << "==================";
}