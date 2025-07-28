class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long ans = 0;

        while (!q.empty()) {
            int s = q.size();
            long long m = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < s; i++) {
                long long id = q.front().second - m;
                TreeNode* curr = q.front().first;
                q.pop();

                if (i == 0) first = id;
                if (i == s - 1) last = id;

                if (curr->left) q.push({curr->left, 2 * id + 1});
                if (curr->right) q.push({curr->right, 2 * id + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};
// TC -> O(N)
// SC -> O(N)
