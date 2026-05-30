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
// recursive DFS
int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    int maxl = maxDepth(root->left);
    int maxr = maxDepth(root->right);
    return 1+max(maxl,maxr);
}
// iterative DFS
int maxDepth1(TreeNode* root){
    if(root==NULL) return 0;
    int maxdepth = 0;
    stack <pair<TreeNode*,int>> st;
    st.push({root,1});
    int depth=1;
    while(!st.empty()){
        TreeNode* top = st.top().first;
        int depth = st.top().second;
        maxdepth = max(maxdepth,depth);
        st.pop();
        if(top->left) st.push({top->left,depth+1});
        if(top->right) st.push({top->right,depth+1});
    }
}
// iterative BFS, basically just counting number of levels in iteration of BFS
int maxDepth2(TreeNode* root){
    queue <TreeNode*> q;
    int level = 0;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size){
            TreeNode* ptr = q.front();
            q.pop();
            if(ptr->left) q.push(ptr->left);
            if(ptr->right) q.push(ptr->right);
            size--;
        }
        level++;
    }
    return level;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}