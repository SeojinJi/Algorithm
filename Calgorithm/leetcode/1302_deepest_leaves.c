#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void DFS(struct TreeNode* root, int depth, int* deepest){
    if(*deepest < depth){
        *deepest = depth;
    }
    if(root->left != NULL){
        DFS(root->left, depth+1, deepest);
    }
    if(root->right != NULL){
        DFS(root->right, depth+1, deepest);
    }
}

void find(struct TreeNode* root, int depth, int deepest, int *arr){
    if(deepest == depth){
        *arr += root->val;
    }
    if(root->left != NULL){
        find(root->left, depth+1, deepest, arr);
    }
    if(root->right != NULL){
        find(root->right, depth+1, deepest, arr);
    }
}

int deepestLeavesSum(struct TreeNode* root) {
    if(root == NULL){
        return 0;
    }
    int arr = 0;
    int deepest = 0;
    DFS(root, 0, &deepest);
    printf("%d", deepest);
    find(root, 0, deepest, &arr);
    return arr;
}