#include <iostream>
#include <vector>
using namespace std;

// Definition of binary tree node
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
    int kthSmallest(TreeNode* root, int k) {
        // In-order traversal of a BST gives sorted order
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            
            k--;
            if (k == 0) {
                return curr->val;
            }
            
            curr = curr->right;
        }
        
        return -1; // shouldn't reach here if k is valid
    }
};
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int main() {
    TreeNode* root = nullptr;
    vector<int> values = {3, 1, 4, 2};
    for (int v : values) root = insert(root, v);
    
    Solution sol;
    int k = 1;
    cout << "Kth (k=" << k << ") smallest element: " << sol.kthSmallest(root, k) << endl; 
    
    k = 2;
    cout << "Kth (k=" << k << ") smallest element: " << sol.kthSmallest(root, k) << endl;
    
    return 0;
}
