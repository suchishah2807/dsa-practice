#include <bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack <int> st;
        vector <int> result(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                result[i]=0;
            }
            else{
                result[i]=st.top()-i;
            }
            st.push(i);
        }
        return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(temperatures);
    
    

    return 0;
}