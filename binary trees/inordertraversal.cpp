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
// HEIGHT: edges in longest path from node X to leaf node
// DEPTH : edges in path from node X to root node

// DFS - types of depth first search
// Traversal of binary tree with root node X occurs as follows: nodes to the left of X come before X, 
// then X itself, lastly the nodes to the right of X come after X and this occurs recursively
// left root right
/*vector<int> inorderTraversal(TreeNode* root){
    vector <int> ans;
    if(root==NULL) return;
    for(int x : inorderTraversal(root->left)) ans.push_back(x); //leftmost node
    ans.push_back(root->data); //parent of that leftmost node
    for(int x : inorderTraversal(root->right)) ans.push_back(x); //right of that parent
    return ans;
}
*/
vector <int> ans;
void inorder(TreeNode* root, vector<int>& ans){
    if(root==NULL) return;
    inorder(root->left, ans);   // go left
    ans.push_back(root->data);   // visit root
    inorder(root->right, ans);  // go right
}
// using stack
vector <int> depthfirstsearch(TreeNode* root){
    stack <TreeNode*> st;
    TreeNode* temp = root;
    vector <int> ans;
    while(temp || !st.empty()){
        // reach the leftmost node
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
        // temp becoems null so reset it to the leftmost node
        temp=st.top();
        st.pop();
        ans.push_back(temp->data);
        temp=temp->right;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    vector <int> ans = depthfirstsearch(root);  
    for(int num : ans){
        cout<<num<<" ";
    }
    return 0;
}