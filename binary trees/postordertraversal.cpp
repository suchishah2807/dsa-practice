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
// left right root
/*
vector<int> postorderTraversal(TreeNode* root){
    vector <int> ans;
    if(root==NULL) return;
    for(int x : postorderTraversal(root->left)) ans.push_back(x);
    for(int x : postorderTraversal(root->right)) ans.push_back(x);
    ans.push_back(root->data);
    return ans;

} */
vector <int> ans;
void postorder(TreeNode* root, vector<int>& ans){
    if(root==NULL) return;
    postorder(root->left, ans);   // go left
    postorder(root->right, ans);  // go right
    ans.push_back(root->data);   // visit root
}
// using stack
vector <int> depthfirstsearch(TreeNode* root){
    stack <TreeNode*> st;
    TreeNode* ptr = root;
    while(ptr){
        if(st.empty()) {st.push(ptr);}
        if(ptr->right!=nullptr) st.push(ptr->right);
        if(ptr->left!=nullptr) st.push(ptr->left);
        ptr=st.top();
    }
    vector <int> ans;
    while(!st.empty()){
        if(st.top()->left || st.top()->right){
            if(st.top()->right!=nullptr) st.push(st.top()->right);
            if(st.top()->left!=nullptr) st.push(st.top()->left);
        }
        ans.push_back(st.top()->data);
        st.pop();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}