/*
    Given root of binary tree, return values that can only be seen from the right side

    BFS traversal, push right first before left, store only first value

    Time: O(n)
    Space: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int count = q.size();
            res.push_back(q.back()->val);
            for(int i = 0; i < count; i++){
                root = q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right){                
                    q.push(root->right);
                }
            }
        }
        return res;
    }
};
