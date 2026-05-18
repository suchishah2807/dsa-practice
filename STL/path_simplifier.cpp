#include <bits/stdc++.h>
using namespace std;
stack <string> reverseStack(stack<string>& original) {
stack<string> aux;
while (!original.empty()) {
    aux.push(original.top());
    original.pop();
}
return aux;
}

string simplifyPath(string path) {
    stack <string> st;
    stringstream ss(path);  // treat string like a stream
    string token;
    while(getline(ss, token, '/')){  // read chunk by chunk, split on '/'
        // token = one directory name at a time
        if(token=="") continue;
        else if(token==".") continue;
        else if(token==".."){
            if(!st.empty()) st.pop();
        }
        else st.push(token);
    }
    stack <string> rev = reverseStack(st);
    string ans="";
    if(rev.empty()) return "/";
    while(!rev.empty()){
        ans=ans+"/"+rev.top();
        rev.pop();
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string path = "/home/user/Documents/../Pictures";
    string ans = simplifyPath(path);
    cout<<ans;

    return 0;
}