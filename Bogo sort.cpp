#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

bool isSorted(vector<int> numList);
int main()
{
	cout << "Enter as many numbers as you like and press enter :)\n" <<
		"when you were finished just type Done and press enter." << endl;

	vector<int> numList;
	string tempString;

	while (cin >> tempString && tempString != "Done")
		numList.push_back(stoi(tempString)); // here stoi() function turns string into integers automatically. its from string library
	
	while (!isSorted(numList))
	{
		cout << "\nITS NOT SORTED YET\n";

		random_device seed; //creates a see to be given to our randomizer algorithm
		mt19937 randomizer(seed()); // this algo uses our seed and creates a new random algo each time
		shuffle(numList.begin(), numList.end(), randomizer); // and now our vector is randomized with that new algo

		for (int i = 0; i < numList.size(); i++)
			cout << numList[i] << ' ';
	}
	if (isSorted(numList))
		cout << "\nFinally :)";

}
bool isSorted(vector<int> numList)
{
	for (int i = 0; i < numList.size() - 1; i++)
	{
		if (numList[i] > numList[i + 1])
			return false;
	}
	return true;
}