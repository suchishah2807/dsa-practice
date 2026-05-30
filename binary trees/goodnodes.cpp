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
// leetcode 1448
int dfs(TreeNode* node, int maxSoFar){
    if(node==NULL) return 0;
    int good;
    if(node->data >= maxSoFar) good=1;
    else good=0;
    int currMax = max(maxSoFar,node->data);
    return good + dfs(node->right,currMax) + dfs(node->left,currMax);
}
int goodNodes(TreeNode* root) {
    return dfs(root,root->data);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}