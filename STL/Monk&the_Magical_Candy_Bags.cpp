#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        multiset<long long> num;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            num.insert(x);
        }
        long long candies = 0;
        while (k--)
        {
            auto it = num.end();
            it--;
            long long candy_count = *it;
            candies += (candy_count);
            num.erase(it);
            num.insert(candy_count / 2);
        }
        cout << candies << endl;
    }
}
// O(10*(3*N+N*(NlogN)))=O10*(3N+N^2LOGN)=O()