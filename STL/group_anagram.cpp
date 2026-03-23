#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
        vector <string> strs;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string word;
            cin>>word;
            strs.push_back(word);        }
        unordered_map<string, vector<string>> data;

        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end()); // anagrams share the same sorted form
            data[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto& pair : data) {
            result.push_back(pair.second);
        }
        
        for (auto& anagram : result) {
            for (auto& word : anagram) {
                cout << word << " ";
            }
            cout << "\n";
        }


    return 0;
}