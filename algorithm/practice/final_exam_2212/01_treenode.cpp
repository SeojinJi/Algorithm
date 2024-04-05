#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TreeSolution{
    public :
        TreeSolution(){TreeNode *root = new TreeNode();}
        TreeSolution(int k){TreeNode *root = new TreeNode(k);}
        TreeNode* insert(TreeNode *root, int key);
        void Traversal(TreeNode *root, int mode);
        void preorder(TreeNode *root);
        void inorder(TreeNode *root);
        void postorder(TreeNode *root);
        TreeNode* search(TreeNode *root, int k);
        TreeNode* iterative_search(TreeNode *root, int k);
        int minimum(TreeNode *root);
        int maximum(TreeNode *root);
        int findSuccessor(TreeNode *root, int k);
        int findPredecessor(TreeNode *root, int k);
        TreeNode* deleteNode(TreeNode *root, int key);
};

TreeNode* TreeSolution::insert(TreeNode *root, int key){
    if(root == nullptr){
        return new TreeNode(key);
    }
    if(key < root->val){
        root->left = insert(root->left, key);
    }
    else if(key > root->val){
        root->right = insert(root->right, key);
    }
    return root;
}

void TreeSolution::Traversal(TreeNode *root, int mode){
    if(mode == 1){
        preorder(root);
    }
    else if(mode == 2){
        inorder(root);
    }
    else if(mode == 3){
        postorder(root);
    }
}

void TreeSolution::preorder(TreeNode *root){
    if(root != NULL){
        cout << root -> val << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void TreeSolution::inorder(TreeNode *root){
    if(root != NULL){
        inorder(root->left);
        cout << root -> val << endl;
        inorder(root->right);
    }
}

void TreeSolution::postorder(TreeNode *root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root -> val << endl;
    }
}

TreeNode* TreeSolution::search(TreeNode *root, int k){ 
    if(root == NULL){
        cout << "This Tree is Null" << endl;
        return root;
    }
    if(k == root->val){
        return root;
    }
    else if(k < root->val){
        return search(root->left, k);
    }
    else{
        return search(root->right, k);
    }
}

TreeNode* TreeSolution::iterative_search(TreeNode *root, int k){ 
    while(root != NULL && k != root->val){
        if(k < root->val){
            root = root->left;
        }
        else{
            root = root -> right;
        }
    }
    return root;
}

int TreeSolution::minimum(TreeNode* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->val;
}

int TreeSolution::maximum(TreeNode *root){
    while(root->right != NULL){
        root = root -> right;
    }
    return root->val;
}

int TreeSolution::findSuccessor(TreeNode *root, int k){
    TreeNode* tree = search(root, k);
    if(tree == nullptr){
        cout << "Can not find successor!" << endl;
        return -1;
    }
    if(tree->right != NULL){          // right subtree of node x is nonempty,
        return minimum(tree->right);  // then the successor is leftmost node in x's right subtree
    }                                
    else{ // if right subtree of node x is empty, then y is the lowest ancestor of x
        TreeNode* successor = nullptr;
        TreeNode* ancestor = root;

        while(ancestor != tree){ // think example
            if(tree->val < ancestor -> val){
                successor = ancestor; // successor : the left child of its parent
                ancestor = ancestor -> left; 
            }
            else{ 
                ancestor = ancestor -> right;
            }
        }
        if(successor != nullptr){
            return successor->val;
        }
        else{
            return -1;
        }
    }
    
}

int TreeSolution::findPredecessor(TreeNode *root, int k){
    TreeNode* tree = search(root, k);
    if(tree == nullptr){
        cout << "Can not find successor!" << endl;
        return -1;
    }
    if(tree->left != NULL){           // left subtree of node x is nonempty,
        return maximum(tree->left);   // then the predecessor is rightmost node in x's right subtree
    }
    else{ // find the largest ancestor of x whose right child is an ancestor of x
        TreeNode* predecessor = nullptr;
        TreeNode* ancestor = root;

        while(predecessor != tree){
            if(tree->val > ancestor -> val){
                predecessor = ancestor;
                predecessor = predecessor -> right;
            }
            else{
                ancestor = ancestor -> left;
            }
        }
        if(predecessor != nullptr){
            return predecessor->val;
        }
        else{
            return -1;
        }
    }
}

TreeNode* TreeSolution::deleteNode(TreeNode *root, int key){
    TreeNode* tree = search(root, key);
    TreeNode* parent = root;
    while(parent->left != tree && parent->right != tree && parent != tree){ // find parent
        if(parent->val < key){
            parent = parent->right;
        }
        else{
            parent = parent->left;
        }
    }
    if(tree == nullptr){
        cout << "Can not find this value" << endl;
        return root;
    }
    if(tree->left == nullptr && tree->right == nullptr){ // not child node
        if(parent -> left == tree){ 
            parent->left = nullptr; // delete node
        }
        else if(parent -> right == tree){
            parent->right = nullptr; // delete node
        }
        delete tree;
        return root;
    }
    else if(tree->right == nullptr || tree->left == nullptr){ // one child node
        TreeNode* tmp;
        if(tree->right == nullptr){
            tmp = tree->left;
        }
        else{
            tmp = tree->right;
        }
        if(parent->left->val == tree->val){
            parent->left = tmp; // left of parent is child node of key
        }
        else{
            parent->right = tmp; // right of parent is child node of key
        }
        return root;
    }
    else{ // two child nodes
        int successor = findSuccessor(root, key); // find successor value
        tree->val = successor; 
        tree->right = deleteNode(tree->right, successor); // delete successor node
        return root;                                      // if successor is smallest ancestor of x 
    }                                                     // whose left child is an ancestor of x???
}

int main(void){
    TreeSolution solution;
    TreeNode* root = nullptr;
    vector<int> keys = {4,2,1,7,3};
    for(int key : keys){
        root = solution.insert(root,key);
    }
    
    TreeNode* tree = solution.search(root, 2);
    solution.Traversal(tree, 1);
    
   
    return 0;
}
