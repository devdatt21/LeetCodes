/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root==NULL) return {};

        queue<Node*> q;
        vector<vector<int>> ans;

        q.push(root);

        while(!q.empty())
        {
            int qSize = q.size();
            vector<int> vec;

            for(int i=0;i<qSize;i++)
            {
                Node* currNode = q.front();
                q.pop();

                vec.push_back(currNode->val);

                for(auto n : currNode->children)
                {
                    q.push(n);
                }
            }

            ans.push_back(vec);

        }

        return ans;
        

    }
};