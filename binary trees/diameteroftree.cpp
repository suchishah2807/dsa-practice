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
// leetcodd 543
int res = 0;

int dfs(TreeNode* root){
    if(!root) return -1; // if its a node with no children its height is considered 0
                         // but for the children the height is -1 as they are non existent
    
    int left = dfs(root->left);   // height of left subtree
    int right = dfs(root->right); // height of right subtree
    
    res = max(res, 2 + left + right); // diameter at this node, 
    
    return 1 + max(left, right);  // height of this node, we need height as it acts as left/right height of upper node(parent node)
                                  // for calculating diameter through the parent node
}

int diameterOfBinaryTree(TreeNode* root){
    dfs(root);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}