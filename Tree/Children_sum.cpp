class Solution {
public:
    int isSumProperty(Node *root) {
        if (!root) return 1;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            if (!curr->left && !curr->right) continue;

            int child_sum = 0;
            if (curr->left) {
                child_sum += curr->left->data;
                q.push(curr->left);
            }

            if (curr->right) {
                child_sum += curr->right->data;
                q.push(curr->right);
            }

            if (child_sum != curr->data) return 0;
        }

        return 1;
    }
};
