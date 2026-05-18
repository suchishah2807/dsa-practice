#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "abbaca";
        stack <char> st;
        for(char ch : s){
            if(!st.empty()){
                char top = st.top();
            }
            st.push(ch);
            if(st.top()==ch){
                st.pop();
                st.pop();
            }
        }
        string ans;
        stack <char> revstring;
        while(!st.empty()){
            char rev = st.top();
            st.pop();
            revstring.push(rev);
        }
        while(!revstring.empty()){
            char rev = revstring.top();
            revstring.pop();
            ans+=rev;
        }
    cout<< ans;

    return 0;
}