#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static bool checkBST(struct TreeNode* root, struct TreeNode** prev) {
    if (root == NULL) return true;

    if (!checkBST(root->left, prev)) return false;

    if (*prev != NULL && root->val <= (*prev)->val) return false;
    *prev = root;

    if (!checkBST(root->right, prev)) return false;

    return true;
}

static int height(struct TreeNode* root) {
    if (root == NULL) return 0;

    int left = height(root->left);
    if (left == -1) return -1;

    int right = height(root->right);
    if (right == -1) return -1;

    int diff = left - right;
    if (diff < 0) diff = -diff;

    if (diff > 1) return -1;

    if (left > right) return left + 1;
    return right + 1;
}

bool isAVL(struct TreeNode* root) {
    struct TreeNode* prev = NULL;

    if (!checkBST(root, &prev)) return false;
    if (height(root) == -1) return false;

    return true;
}