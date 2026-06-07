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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto& d : descriptions) {
            int parent = d[0], child = d[1], isLeft = d[2];
            if (!nodes[parent]) nodes[parent] = new TreeNode(parent);
            if (!nodes[child]) nodes[child] = new TreeNode(child);
            if (isLeft) nodes[parent]->left = nodes[child];
            else nodes[parent]->right = nodes[child];
            children.insert(child);
        }

        for (auto& d : descriptions)
            if (!children.count(d[0])) return nodes[d[0]];
        return nullptr;
    }
};