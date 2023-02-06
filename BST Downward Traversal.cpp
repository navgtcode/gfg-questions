/* 
#########################################################################################################################################
Problem :
Given a Binary Search Tree with unique node values and a target value. You have to find the node whose data is equal to target and return
the sum of all descendant node's data which are vertically below the target node. Initially, you are at the root node.
Note: If target node is not present in bst then return -1.

Example 1:
BST : 25 20 35 15 22 30 45 32
input: 35
output : 32

example 2:
BST: 25 20 35 15 22 30 45 32
Target = 25
Output: 52

Your Task:
You don't need to read input or print anything. Your task is to complete the function verticallyDownBST() which takes BST(you are given 
root node of bst ) and target as input, and return an interger value as the sum of vertically down nodes from target. If target is not 
present in bst then return -1.

Expected Time Complexity: O( n ), n is number of nodes.
Expected Auxiliary Space: O(Height of the tree).

#########################################################################################################################################



-----------------------------------------------------------------------------------------------------------------------------------------
Brute force approach
----------------------------------------------------------------------------------------------------------------------------------------*/

int sum = 0;
void findSum(Node *root, int target) {
    if (!root) return;
    if (root->data == target) {
        sum += root->left ? root->left->data : 0;
        sum += root->right ? root->right->data : 0;
        findSum(root->left, target);
        findSum(root->right, target);
    } else {
        findSum(root->left, target);
        findSum(root->right, target);
    }
}

int verticallyDownBST(Node *root, int target) {
    findSum(root, target);
    return sum;
    //github.com/Sugaax/Gfg-Problem-of-the-Day
}


/*
-----------------------------------------------------------------------------------------------------------------------------------------
Optimized Solution
---------------------------------------------------------------------------------------------------------------------------------------*/

int verticallyDownBST(Node *root, int target, int hd) {
    if (!root) return 0;
    
    if (root->data == target) {
        int sum = 0;
        if (root->left) {
            sum += root->left->data + verticallyDownBST(root->left, target, hd - 1);
        }
        if (root->right) {
            sum += root->right->data + verticallyDownBST(root->right, target, hd + 1);
        }
        return sum;
    }
    return verticallyDownBST(root->left, target, hd - 1) + verticallyDownBST(root->right, target, hd + 1);
    //github.com/Sugaax/Gfg-Problem-of-the-Day
}


