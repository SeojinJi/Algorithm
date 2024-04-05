#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public :
        vector<int> Traversal(TreeNode* root, int mode){
            vector<int> res;
            if(mode == 1){
                preorderHelper(root, res);
            }
            else if(mode == 2){
                inorderHelper(root, res);
            }
            else if(mode == 3){
                postorderHelper(root, res);
            }
            return res;
        }

        void inorderHelper(TreeNode *root, vector<int>& res){
            if(root != NULL){
                inorderHelper(root->left, res);
                res.push_back(root->val);
                inorderHelper(root->right, res);
            }
            
        }

        void preorderHelper(TreeNode *root, vector<int>& res){
            if(root != NULL){
                res.push_back(root->val);
                preorderHelper(root->left, res);
                preorderHelper(root->right, res);
            }
        }

        void postorderHelper(TreeNode *root, vector<int>& res){
            if(root != NULL){
                postorderHelper(root->left, res);
                postorderHelper(root->right, res);
                res.push_back(root->val);
            }
        }
};

int main(void){
    TreeNode *rightright = new TreeNode(4);
    TreeNode *rightleft = new TreeNode(3);
    TreeNode *right = new TreeNode(2, rightleft, rightright);

    TreeNode *leftleft = new TreeNode(6);
    TreeNode *left = new TreeNode(5, leftleft, NULL);
    TreeNode *root = new TreeNode(1, left, right);
    
    Solution solution;

    vector<int> result1 = solution.Traversal(root,1);
    vector<int> result2 = solution.Traversal(root,2);
    vector<int> result3 = solution.Traversal(root,3);

    cout << "Preorder Traversal Result : " ;
    for(int val : result1){
        cout << val << " ";
    } 
    cout << endl;

    cout << "Inorder Traversal Result : " ;
    for(int val : result2){
        cout << val << " ";
    } 
    cout << endl;

    cout << "Postorder Traversal Result : " ;
    for(int val : result3){
        cout << val << " ";
    } 
    cout << endl;

    delete rightleft;
    delete right;
    delete root;

    return 0;
}