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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*> que;
        que.push(root);

        vector<int> ans;
        TreeNode* front=NULL;

        while(!que.empty())
        {
            int sz = que.size();    
            while(sz--)
            {
                front = que.front();
                que.pop();
                if(front->left != NULL)
                {
                    que.push(front->left);
                }
                if(front->right != NULL)
                {
                    que.push(front->right);
                }
            }          
            ans.push_back(front->val);
        }
        return ans;
        
    }
};
