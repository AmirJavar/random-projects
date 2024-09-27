#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bubbleSort(vector<string>&);
int main()
{
    cout << "Enter a word and press enter. When you are done adding words, type 'Done' and press enter." << endl;

    vector<string> words;
    string lastword;

    while (lastword != "Done")
    {
        cin >> lastword
        words.push_back(lastword);
    }

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
