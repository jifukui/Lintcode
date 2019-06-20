/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
#include <iostream>
using namespace std;
class Solution {
public:
    /*
     * @param root: the root of tree
     * @return: the max node
     */
    TreeNode * maxNode(TreeNode * root) {
        // write your code here
        queue<TreeNode*> q;
        TreeNode *max=NULL;
        TreeNode *node=NULL;
        max=root;
        q.push(root);
        while(!q.empty())
        {
            node=q.back();
            q.pop();
            cout<<node->val<<endl;
            while(node)
            {
               if(max->val<node->val)
               {
                   max=node;
               }
               if(node->right)
               {
                   q.push(node->right);
               }
               node=node->left;
            }
        }
        return max;
    }
};
int main()