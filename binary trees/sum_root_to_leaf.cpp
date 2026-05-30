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

int dfs(TreeNode* node,int sum){
    if(!node) return 0;
    sum = (sum*10) + node->data;
    if(!node->right && !node->left) return sum;
    return dfs(node->left,sum) + dfs(node->right,sum);
}
int sumNumbers(TreeNode* root) {
    int ans = dfs(root,0);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}