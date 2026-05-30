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

int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int l_size = countNodes(root->left);
        int r_size = countNodes(root->right);
        return 1 + l_size + r_size;
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}