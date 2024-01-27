#include <iostream>
#include <iomanip>
using namespace std;

void input(int [], int);
void selectionSort(int [],int, bool (*) (int, int));
void swap(int * const, int * const);
bool ascending(int, int);
bool descending(int, int);
void output(int [], int, int);
int main()
{
    // List's number of members is taken from user
    cout << "How many numbers would you like to sort ?\n ";
    int n, *list;
    cin >> n;
    list = new int[n];
    if (!n)
        cout << "Allocation failure.";
    input(list, n);
    //choice between asc and des sort is taken from user
    int choice;
    cout << "Type 1 and press enter to sort given " << n << " numbers in descending order.\n" <<
    "Type 2 and press enter to sort given " << n << " numbers in ascending order.\n";
    cin >> choice;
    if (choice == 1)
        selectionSort(list, n, descending);

    else if (choice == 2)
        selectionSort(list, n, ascending);
    else {
        cout << "!SORT FAILED! Please enter either 1 or 2";
        exit(0);
    }
    output(list, n, choice);
}
void input(int list[], int n)
{
    for (int i=0 ; i < n ; i++)
    {
        cout << "Please Enter number " << i+1 << " : ";
        cin >> list[i];
    }
}
void selectionSort(int *list,int n, bool (*compare) (int, int))
{
    int sol;
    for (int i=0 ; i<n-1 ; i++)
    {
        sol = i;
        for (int index=i+1 ; index < n ; index++)
        {
            if(!(*compare) (list[sol], list[index]))
                sol=index;
        }
        swap(&list[sol], &list[i]);
    }
}
void swap(int * const a, int * const b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
bool descending(int a, int b)
{
    return a>b;
}
bool ascending(int a, int b)
{
    return b>a;
}
void output(int list[], int n, int choice)
{
    string strChoice;
    if (choice == 1)
        strChoice = "descending";
    else
        strChoice = "ascending";
    cout << "Given numbers in " << strChoice << " order are : \n";
    for (int i=0 ; i < n ; i++)
        cout << setw(4) << list[i] << '\t';
}