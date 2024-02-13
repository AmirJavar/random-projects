#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	cout << "Please enter a string : ";
	string str, temp = "";
	getline(cin, str);
	
	for (int i = 0; i < str.length(); i++)
		for (char j = 'a'; j <= 'z'; j++)
		{
			system("color 02");
			Sleep(25);
			cout << temp << j << endl;
			if (str[i] == ' ')
			{
				temp += ' ';
				break;
			}
			else if (str[i] == j)
			{
				temp += str[i];
				break;
			}
		}
}