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


bool isMirror(TreeNode* left, TreeNode* right){
    if(left==NULL && right==NULL) return true;
    if(left==NULL || right==NULL) return false;
    if(left->data != right->data) return false;  // don't forget this!
    return isMirror(left->left, right->right) && 
        isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root){
    return isMirror(root->left, root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}