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

int minDepth(TreeNode* root) {
    if(root==NULL) return 0;
    queue <TreeNode*> q;
    q.push(root);
    int depth = 0;
    while(!q.empty()){
        int size=q.size();
        depth++;
        for(int i=0;i<size;i++){
            TreeNode* ptr = q.front();
            q.pop();
            if(!ptr->left && !ptr->right) return depth; // ✓ first leaf found
            if(ptr->left) q.push(ptr->left);
            if(ptr->right) q.push(ptr->right);
        }
    }
    return depth;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}