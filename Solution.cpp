/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * @brief Build an undirected graph (adjacency list) from the binary tree.
     * 
     * Each node is connected to its left and right child (if they exist), 
     * and the connections are bidirectional to simulate graph traversal.
     * 
     * @param root Current node in the binary tree.
     * @param mp Adjacency list representing the graph.
     */
    void relations(TreeNode* root, unordered_map<int, vector<int>>& mp) {
        if (!root) return;

        if (root->left) {
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if (root->right) {
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }

        // Recurse on left and right subtrees
        relations(root->left, mp);
        relations(root->right, mp);
    }

    /**
     * @brief Calculate the time needed to infect the entire tree starting from a given node.
     * 
     * This simulates infection spread using BFS from the 'start' node.
     * 
     * @param root Root of the binary tree.
     * @param start Starting node for infection.
     * @return int Maximum time (in minutes) to infect all nodes.
     */
    int amountOfTime(TreeNode* root, int start) {
        // Edge case: tree has only one node, which is the starting node
        if (!root->left && !root->right && root->val == start)
            return 0;

        // Convert binary tree into an undirected graph
        unordered_map<int, vector<int>> mp;
        relations(root, mp);

        // Perform BFS starting from the 'start' node
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        int level = 0;

        // BFS loop
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int top = q.front();
                q.pop();

                for (int neighbor : mp[top]) {
                    if (!visited.count(neighbor)) {
                        q.push(neighbor);
                        visited.insert(neighbor);
                    }
                }
            }
            // Only increment time if there are more nodes to process
            if (!q.empty())
                level++;
        }

        return level;
    }
};
