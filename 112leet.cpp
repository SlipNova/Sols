#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* root, int target) {
    if (root == nullptr)
        return false;
    stack<pair<TreeNode*, int>> st;
    st.push({root, target - root->val});
    while (!st.empty()) {
        auto [t, rem] = st.top();
        st.pop();
        if (t->right == nullptr && t->left == nullptr) {
            cout << rem << endl;
            if (rem == 0)
                return true;
        }
        if (t->right != nullptr) {
            st.push({t->right, rem - (t->right)->val});
        }
        if (t->left != nullptr) {
            st.push({t->left, rem - (t->left)->val});
        }
    }
    return false;
}

class Solution {
public:
    bool hasPathSum1(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return targetSum == root->val;
        return hasPathSum(root->right, targetSum - root->val) ||
               hasPathSum(root->left, targetSum - root->val);
        ;
    }
};