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

bool findelement(TreeNode* root, int val){
    if(root == NULL) return false;
    if(root->data==val) return true;
    bool fil = findelement(root->left,val);
    if(fil) return true;
    bool fir = findelement(root->right,val);
    if(fir) return true;
    return false;
}

vector <int> path;
bool printpath(TreeNode* root, int val){
    if(root == NULL) return false;
    if(root->data==val) path.push_back(root->data); return true;
    
    bool fil = findelement(root->left,val);
    if(fil) path.push_back(root->data); return true;
    
    bool fir = findelement(root->right,val);
    if(fir) path.push_back(root->data); return true;
    
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}