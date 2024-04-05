#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public :
        vector<int> inorderTraversal(TreeNode* root){
            vector<int> res;
            helper(root, res);
            return res;
        }

        void helper(TreeNode *root, vector<int>& res){
            if(root != NULL){
                helper(root->left, res);
                res.push_back(root->val);
                helper(root->right, res);
            }
        }
};

int main(void){
    TreeNode *rightleft = new TreeNode(3);
    TreeNode *right = new TreeNode(2, rightleft, NULL);
    TreeNode *root = new TreeNode(1, NULL, right);
    
    Solution solution;

    vector<int> result = solution.inorderTraversal(root);

    cout << "Inorder Traversal Result : " ;
    for(int val : result){
        cout << val << " ";
    } 
    cout << endl;

    delete rightleft;
    delete right;
    delete root;

    return 0;
}