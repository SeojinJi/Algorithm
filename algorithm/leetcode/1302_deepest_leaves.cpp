#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> deepest = {0};
    vector<int> arr = {0};
    void DFS(TreeNode* root, int depth){
        deepest[0] = max(deepest[0], depth);
        if (root->left != nullptr){
            DFS(root->left, depth+1);
        }
        if(root->right != nullptr){
            DFS(root->right, depth+1);
        }
    }
    void find(TreeNode* root, int depth){
        if (depth == deepest[0]) {
            arr[0] += root->val;
        }
        if(root->left != nullptr){
            find(root->left, depth+1);
        }
        if(root->right != nullptr){
            find(root->right, depth+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        DFS(root, 0);
        find(root, 0);
        return arr[0];
    }
};

int main(){
    int null = 0;
    vector<int> keys = {1,2,3,4,5,null,6,7,null,null,null,null,8};
    TreeNode* root = new TreeNode(keys[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < keys.size()){
        TreeNode* current = q.front();
        q.pop();
        if (keys[i] != null){
            current->left = new TreeNode(keys[i]);
            q.push(current->left);
        }
        i += 1;
        if (i < keys.size() && keys[i] != null){
            current->right = new TreeNode(keys[i]);
            q.push(current->right);
        }
        i += 1;
    }

    Solution solution;
    int result = solution.deepestLeavesSum(root);

    cout << result << endl;
    return 0;
}