class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        int ans = 0;

        while (!q.empty()) {
            int size = q.size();

            unsigned long long first = q.front().second;
            unsigned long long last = first;

            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();

                TreeNode* node = curr.first;
                unsigned long long idx = curr.second;

                last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx + 1});

                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};