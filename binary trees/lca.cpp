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

bool getpath(TreeNode* root, vector <TreeNode*> &arr, TreeNode* x){
    if(!root) return false;
    arr.push_back(root);
    if(root->data==x->data) return true;
    if(getpath(root->right,arr,x) || getpath(root->left,arr,x)) return true;
    arr.pop_back();
    return false;
}

vector <TreeNode*> printpath(TreeNode* root,TreeNode* A){
    vector <TreeNode*> arr;
    if(A==NULL) return {};
    getpath(root,arr,A);
    return arr;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector <TreeNode*> path1 = printpath(root, p);
    vector <TreeNode*> path2 = printpath(root, q);
    reverse(path1.begin(),path1.end());
    reverse(path2.begin(),path2.end());
    int i = path1.size()-1;
    int j = path2.size()-1;

    while(i>=0 && j>=0){
        if(path1[i]->data == path2[j]->data){
            i--; j--;
        } else {
            break;
        }
    }
    // first common node is at i+1 or j+1
    TreeNode* lca = path1[i+1];
    return lca;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}