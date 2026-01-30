#include <bits/stdc++.h>
using namespace std;

// for example arr=[4,12,5,3,1,2,5,7]
// we know that to know next greater element we must know elements after that index so rather than 
// traversing through front, traverse through back.
// st= []
// for 7, st is empty so push 7 and assign 7->-1
// for 5, we see st.top()>5 so we assign 5->7 and add 5 to st
// ...st=[1,2,5,7]
// for 3, st.top()<3 so we pop till we get st.top>3 3->5 and then add 3 to st
// st=[3,x,x,5,7]
// removing 1,2 from st doesnt affect nge as 3 is nge so obviously for any element smaller than
// 1,2 would have 3 as their nge irrespective of 1,2 being in stack or not
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector <int> nums(n);
    vector <int> nge(n);
    stack <int> st;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    for(int i = n - 1; i >= 0; i--) {

        while(!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        if(st.empty()) nge[i] = -1;
        else nge[i] = st.top();

        st.push(nums[i]);
    }

    for(auto ge:nge){
        cout<<ge<<endl;
    }
    return 0;
}