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
Solution in C++
----------------------------------------------------------------------------------------------------------------------------------------*/

class Solution{
    public:
    long long int verticallyDownBST(Node *root,int target){
        queue<Node*> q;
        q.push(root);
        long long ans=0;
        Node* tar=NULL;
        while(!q.empty()){
                Node* node=q.front();
                q.pop();
                if(node->data==target){
                    tar=node;
                    break;
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
        }
        if(tar==NULL) return -1;
        queue<pair<Node*,int>> x;
        if(tar->left){
            x.push({tar->left,-1});
        }
        if(tar->right){
            x.push({tar->right,+1});
        }
        while(!x.empty()){
            auto it=x.front();
            x.pop();
            Node *node=it.first;
            int level=it.second;
            if(level==0){
                ans+=node->data;
            }
            if(node->left){
                x.push({node->left,level-1});
            }
            if(node->right){
                x.push({node->right,level+1});
            }
        }
        return ans;
    }
};

