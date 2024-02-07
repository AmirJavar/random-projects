#include <iostream>
#include <string>
using namespace std;

void multiply(int numArr[], int &size, int x);
void factorial(int num);
int main()
{
	cout << "Please enter a positive integer number : ";
	int num;
	cin >> num;
	factorial(num);
}

void factorial(int num)
{
	int size = 1;
	int* numArr = new int[size];
	numArr[0] = 1;

	for (int i = 2; i < num + 1; i++)
		multiply(numArr, size, i);

	for (int i = size-1; i > -1; i--)
		cout << numArr[i];
}

void multiply(int numArr[], int &size, int x)
{
	int carry = 0;
	for (int i = 0; i < size; i++)
	{
		int prod = numArr[i] * x + carry;
		numArr[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry)
	{
		numArr[size] = carry % 10;
		carry /= 10;
		size++;
	}
}



//Easter egg ;)