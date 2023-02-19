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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        
        if(root == NULL )
        {
            return ans;
        }

        queue<TreeNode*> queueDs;
        queueDs.push(root) ;
        bool directionRL = true;

        while(!queueDs.empty())
        {
            int QueueSize = queueDs.size();
            vector<int> vect(QueueSize);
            for(int i= 0 ;i<QueueSize ;i++)
            {
                TreeNode* node = queueDs.front();
                queueDs.pop();
                int idx = directionRL ? i : (QueueSize-1-i);
                vect[idx] = node->val;

                if(node->left)
                    queueDs.push(node->left);
                
                if(node->right)
                    queueDs.push(node->right);

            }
            directionRL = !directionRL;
            ans.push_back(vect);
        }
        return ans;
    }
};
