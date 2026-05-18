#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector <int> left(n); // arr to store the indice of closest element on left of ith element that is smaller than ith element
    stack <int> st1;
    for(int i=0;i<n;i++){
        while(!st1.empty() && heights[st1.top()]>=heights[i]){
            st1.pop();
        }
        if(st1.empty()){
            left[i]=-1;
        }
        else{
            left[i] = st1.top();
        }
        st1.push(i);
    }
    vector <int> right(n);  // arr to store the indice of closest element on right of ith element that is smaller than ith element.
    stack <int> st2;
    for(int i=n-1;i>-1;i--){
        while(!st2.empty() && heights[st2.top()]>heights[i]){
            st2.pop();
        }
        if(st2.empty()){
            right[i]=n;
        }
        else{
            right[i] = st2.top();
        }
        st2.push(i);
    }
    int max_area = 0;
    for(int i=0;i<n;i++){
        max_area = max(max_area,heights[i]*(right[i]-left[i]-1));
    }
    return max_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> heights = {2,1,5,6,2,3};
    int ans = largestRectangleArea(heights);
    cout<<ans;
    

    return 0;
}