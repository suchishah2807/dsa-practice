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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root==NULL) return {};
    queue <TreeNode*> q;
    q.push(root);
    vector<vector<int>> ans;
    bool leftToRight=true;
    while(!q.empty()){
        vector <int> level;
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* ptr = q.front();
            q.pop();
            level.push_back(ptr->data);
            if(ptr->left) q.push(ptr->left);
            if(ptr->right) q.push(ptr->right);                
            }
    if(!leftToRight) reverse(level.begin(), level.end()); // ✓ just flip alternate levels
    ans.push_back(level);
    leftToRight = !leftToRight; // toggle
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}