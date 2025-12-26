#include <iostream>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        string s1;
        string s2;
        cin >> s1;
        cin >> s2;
        int pf_sum1[26] = {0};
        int pf_sum2[26] = {0};
        for (int i = 0; i < s1.size(); i++)
        {
            pf_sum1[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++)
        {
            pf_sum2[s2[i] - 'a']++;
        }
        bool anagram = true;
        for (int i = 0; i < 26; i++)
        {
            if (pf_sum1[i] != 0)
            {
                if (pf_sum1[i] > pf_sum2[i])
                {
                    cout << "NO" << endl;
                    anagram = false;
                    break;
                }
            }
        }
        if (anagram == true)
        {
            cout << "YES" << endl;
        }
    }
}