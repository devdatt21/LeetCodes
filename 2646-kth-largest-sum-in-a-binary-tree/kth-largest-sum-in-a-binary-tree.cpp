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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        if(root==NULL) return -1;

        vector<long long> res;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            long long sum=0;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();

                if(node->left)
                {
                    q.push(node->left);
                }

                if(node->right)
                {
                    q.push(node->right);
                }
                
                if(node!=NULL) sum += node->val;
            }

            res.push_back(sum);

        }

        if(k > res.size()) return -1;
        
        sort(res.begin(),res.end(), greater<long long>());

        return res.empty() ? -1  : res[k-1] ; 

    }
};