#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<char, string> m;
    map<string, char> rev;
    bool word_pattern = true;
    string pattern, s;
    cin >> pattern;
    cin.ignore();
    getline(cin, s);

    vector<string> words;
    istringstream iss(s);
    string word;

    while (iss >> word)
    {
        words.push_back(word);
    }
    
    // Check if pattern length matches words count
    if (pattern.size() != words.size())
    {
        cout << "false";
        return 0;
    }

    for (int i = 0; i < pattern.size(); i++)
    {
        if (m.count(pattern[i]) == 1 && m[pattern[i]] != words[i])
        {
            word_pattern = false;
            break;
        }

        if (rev.count(words[i]) == 1 && rev[words[i]] != pattern[i])
        {
            word_pattern = false;
            break;
        }

        m[pattern[i]] = words[i];
        rev[words[i]] = pattern[i];
    }

    if (word_pattern == true)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    
    return 0;
}