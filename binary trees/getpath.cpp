#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* right;
    TreeNode* left;
    public:
    TreeNode(int data1, TreeNode* right1, TreeNode* left1){
        data=data1;
        right=right1;
        left=left1;
    }
    TreeNode(int data1){
        data=data1;
        right=nullptr;
        left=nullptr;
    }
};

bool getpath(TreeNode* root, vector <int> &arr, int x){
    if(!root) return false;
    arr.push_back(root->data);
    if(root->data==x) return true;
    if(getpath(root->right,arr,x) || getpath(root->left,arr,x)) return true;
    arr.pop_back();
    return false;
}

vector <int> printpath(TreeNode* root,int A){
    vector <int> arr;
    if(A==NULL) return {};
    getpath(root,arr,A);
    return arr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}