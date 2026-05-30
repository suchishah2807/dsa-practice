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
//leetcode 112
    bool dfs(TreeNode* node, int currsum,int targetSum){
        if(node==NULL) return false;
        currsum+=node->data;
        if(!node->right && !node->left) return currsum==targetSum;
        return dfs(node->right,currsum,targetSum) || dfs(node->left,currsum,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,0,targetSum);
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}