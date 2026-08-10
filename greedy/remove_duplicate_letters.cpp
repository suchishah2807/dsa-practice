#include <bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
    // basically goal is to make sure occurence of every small(lexographically) letter is as early as possible
    // create a vector to keep track of last index of all chars, to know if that character occurs after current index
    // add characters in a stack so that it follows the order
    vector<int> last_index(26,0);
    vector<bool> in_stack(26,false);
    stack <char> st;
    for(int i=0;i<s.length();i++){
        last_index[s[i]-'a']=i;
    }
    for(int i=0;i<s.length();i++){
        char c =s[i];
        if(in_stack[c-'a']) continue; // if it already exists, then skip
        while(!st.empty() && st.top()>c && last_index[st.top()-'a']>i){ // if the last char>current char and last char has a
            // occurence later in the string then pop the last occurence
            in_stack[st.top()-'a']=false;
            st.pop();
        }
        st.push(c);
        in_stack[c-'a']=true;
    }
    string ans="";
    while(!st.empty()){
        ans = st.top()+ans; // reverse adding
        st.pop();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}