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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}