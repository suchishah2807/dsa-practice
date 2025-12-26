#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int a[4] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'r')
            {
                a[0]++;
            }
            else if (s[i] == 'u')
            {
                a[1]++;
            }
            else if (s[i] == 'b')
            {
                a[2]++;
            }
            else if (s[i] == 'y')
            {
                a[3]++;
            }
        }
        int min = a[3];
        for (int i = 0; i < 4; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
            }
        }
        cout << min << endl;
    }
}