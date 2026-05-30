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
int pathsum = INT_MIN;
int PathSum(TreeNode* root){
    if(root==NULL) return 0;
    int leftsum = PathSum(root->left);
    int rightsum = PathSum(root->right);
    pathsum = max(pathsum,root->data+max(leftsum,0) + max(rightsum,0));
    return root->data + max({leftsum, rightsum,0});
}
int maxPathSum(TreeNode* root) {
    PathSum(root);
    return pathsum;
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}