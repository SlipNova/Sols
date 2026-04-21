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

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        if (root == nullptr) {
            return paths;
        }
        vector<int> path;
        stack<tuple<TreeNode*, int, bool>> st;
        st.push({root, targetSum, false});
        while (!st.empty()) {
            auto [node, rem, backtrack] = st.top();
            st.pop();
            if (backtrack) {
                path.pop_back();
                continue;
            }
            rem -= node -> val;
            path.push_back(node -> val);
            st.push({node, rem, true});
            if (node -> right == nullptr && node -> left == nullptr && rem == 0) {
                paths.push_back(path);
            }
            if (node -> right != nullptr) {
                st.push({node -> right, rem, false});
            }
            if (node -> left != nullptr) {
                st.push({node -> left, rem, false});
            }
        }
        return paths;
    }
};

