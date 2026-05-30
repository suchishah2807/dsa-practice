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
// root left right
/*vector<int> preorderTraversal(TreeNode* root){
    vector <int> ans;
    if(root==NULL) return;
    ans.push_back(root->data);
    for(int x : preorderTraversal(root->left)) ans.push_back(x);
    for(int x : preorderTraversal(root->right)) ans.push_back(x);
    return ans;
}
*/
vector <int> path;
void preorder(TreeNode* root, vector <int>& path){
    if(root == NULL) return;
    path.push_back(root->data);
    preorder(root->left,path);
    preorder(root->right,path);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
TreeNode* root = new TreeNode(4);
root->left = new TreeNode(9);
root->right = new TreeNode(0);
root->left->left = new TreeNode(5);
root->left->right = new TreeNode(1);
preorder(root,path);
for(int num : path){
    cout<<num<<" ";
}
    

    return 0;
}