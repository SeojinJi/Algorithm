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

        TreeNode* deleteRoot(TreeNode *root, int key){
            if(root == nullptr){
                return root;
            }
            else if(key < root->val){
                root->left = deleteRoot(root->left, key);
            }
            else if(key > root->val){
                root->right = deleteRoot(root->right, key);
            }
            else{
                //case1
                if(root->left == nullptr && root->right == nullptr){
                    delete root;
                    root = nullptr;    
                }

                //case2
                if(root->left == nullptr || root->right == nullptr){
                    if(root->left == nullptr){
                        TreeNode *tmp = root;
                        root = root->right;
                        delete tmp;
                    }
                    else{
                        TreeNode *tmp = root;
                        root = root->left;
                        delete tmp;
                    }
                }

                //case3
                else{
                    TreeNode *tmpParent = root;
                    TreeNode *tmp = root->right;
                    while(tmp->left != nullptr){
                        tmpParent = tmp;
                        tmp = tmp->left;
                    }
                    if(tmpParent != root){
                        tmpParent->left = tmp->right;
                    }
                    else{
                        tmpParent->right = tmp->right;
                    }
                    root->val = tmp->val;
                    delete tmp;
                }
            }
            return root;
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

    vector<int> result = solution.inorderTraversal(root);
    cout << "Before Deletion, Inorder Traversal Result : " ;
    for(int val : result){
        cout << val << " ";
    } 
    cout << endl;

    root = solution.deleteRoot(root, 1);

    result = solution.inorderTraversal(root);

    cout << "After Deletion, Inorder Traversal Result : " ;
    for(int val : result){
        cout << val << " ";
    } 
    cout << endl;

    delete rightright;
    delete rightleft;
    delete right;
    delete leftleft;
    delete left;
    delete root;

    return 0;
}