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
    TreeNode* replaceValueInTree(TreeNode* root) {
        //BFS

        queue<TreeNode*> q;

        root->val=0;

        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            int sum=0;
            
            vector<TreeNode*> buffer;

            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                buffer.push_back(node);
                if(node->left) {sum += node->left->val; q.push(node->left);}
                if(node->right) {sum += node->right->val; q.push(node->right);}
                
            }

            for(auto node : buffer)
            {
                int t=sum;

                if(node->left) t -= node->left->val;
                if(node->right) t -= node->right->val;

                if(node->left) node->left->val = t;
                if(node->right) node->right->val = t;
            }


        }

        return root;
    }
};