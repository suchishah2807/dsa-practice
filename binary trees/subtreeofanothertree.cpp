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

    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p==NULL & q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        if(p->data != q->data) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL) return true;
        if(root==NULL) return false;
        if((isSameTree(root,subRoot))) return true;
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
TreeNode* root = new TreeNode(3);
root->left = new TreeNode(4);
root->right = new TreeNode(5);
root->left->left = new TreeNode(1);
root->left->right = new TreeNode(2);
root->left->right->left = new TreeNode(6);

TreeNode* subRoot = new TreeNode(4);
subRoot->left = new TreeNode(1);
subRoot->right = new TreeNode(2);
cout<< isSubtree(root,subRoot);
    

    return 0;
}