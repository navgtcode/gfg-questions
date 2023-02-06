/* 
----------------------------------------------------------------------------------------------------------------------------------------
Brute force approach
----------------------------------------------------------------------------------------------------------------------------------------
The problem is to find a node in a binary search tree (BST) with a specific value and return the sum of all descendant nodes' values that 
are vertically below the target node. The function should work with an expected time complexity of O(n) and expected auxiliary space of 
O(height of the tree).

The brute force solution to this problem would be to perform a depth-first search (DFS) on the BST to find the target node and then use 
DFS again to sum all the values of the descendant nodes.
----------------------------------------------------------------------------------------------------------------------------------------
*/

class Solution{
public:
    long long int verticallyDownBST(Node *root, int target) {
        if (root == NULL) return -1; 

        long long int sum = 0;  
        if (root->data == target) {  
            if (root->left) { 
                Node *temp = root->left;
                while (temp != NULL) {
                    sum += temp->data;
                    temp = temp->right;
                }
            }
            if (root->right) { 
                Node *temp = root->right;
                while (temp != NULL) {
                    sum += temp->data;
                    temp = temp->left;
                }
            }
        }
        else if (root->data > target) { 
            sum = verticallyDownBST(root->left, target);
        }
        else {  
            sum = verticallyDownBST(root->right, target);
        }
        return sum;
    } //github.com/Sugaax/Gfg-Problem-of-the-Day
};


/*
----------------------------------------------------------------------------------------------------------------------------------------
Optimized Solution
----------------------------------------------------------------------------------------------------------------------------------------
Here's an optimized solution to the problem using a hash map to store the node's data and its vertical distance from the target node, 
and using the level order traversal.

A HashMap can be used to store the level of each node of a binary search tree as the key and sum of all nodes in the same level as the 
value. This way, we can keep track of the sum of nodes in each level and return the sum of nodes at the level of the target node. This 
helps us to optimize the solution as it avoids unnecessary traversal of the tree and directly returns the sum of nodes at the level of 
the target node.
----------------------------------------------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    int verticallyDownBST(Node *root, int target) {
        unordered_map<int, long long> map;
        int level = 0;
        int ans = 0;
        levelOrder(root, map, level, target, ans);

        if (map.empty())
            return -1;

        return ans;
    }

    void levelOrder(Node *root, unordered_map<int, long long> &map, int level, int target, int &ans) {
        if (!root)
            return;

        if (root->data == target) {
            map[level] = root->data;
            level++;
            if (root->left)
                levelOrder(root->left, map, level, target, ans);
            if (root->right)
                levelOrder(root->right, map, level, target, ans);
        } else {
            levelOrder(root->left, map, level, target, ans);
            levelOrder(root->right, map, level, target, ans);
        }

        if (map.count(level - 1)) {
            ans += root->data;
            map[level] = root->data;
        }
    } //github.com/Sugaax/Gfg-Problem-of-the-Day
};
