#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bubbleSort(vector<string>& words);
int main()
{
    cout << "Enter a word and press enter. When you are done adding words, type 'Done' and press enter." << endl;

    vector<string> words;
    string lastword;

    while (cin >> lastword && lastword != "Done")
    {
        words.push_back(lastword);
    }

    // Sorting using the custom sorting algorithm
    bubbleSort(words);

    int counter = 0;
    for (int i = 0; i < words[0].size(); i++)
    {
        if (words[0].at(i) == words[words.size() - 1].at(i))
            counter++;
        else
            break;
    }


    cout << "Longest prefix is: \"" << words[0].substr(0, counter) << "\"" << endl;

    return 0;
}

void bubbleSort(vector<string>& words)
{
    int n = words.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (words[j] > words[j + 1])
            {
                swap(words[j], words[j + 1]);
            }
        }
    }
}
