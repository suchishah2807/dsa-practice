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

// leetcode 110
bool ans=true;
int heights(TreeNode* root){
    if(root==NULL) return -1;
    int left_height = heights(root->left);
    int right_height = heights(root->right);
    if(abs(left_height-right_height)>1) ans = false;
    return 1+max(left_height,right_height);
}
bool isBalanced(TreeNode* root){
    heights(root);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    bool res = isBalanced(root);
    cout<<res;

    return 0;
}