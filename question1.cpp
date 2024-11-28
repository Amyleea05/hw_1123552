//Amylea
//1123552
//2024.11.28
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to build the binary tree from level-order input
TreeNode* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

// Function to calculate the diameter of the binary tree
int diameterHelper(TreeNode* root, int& height) {
    if (root == nullptr) {
        height = 0;
        return 0;
    }

    int leftHeight = 0, rightHeight = 0;

    // Recursive calls to find the diameter and height of the left and right subtrees
    int leftDiameter = diameterHelper(root->left, leftHeight);
    int rightDiameter = diameterHelper(root->right, rightHeight);

    // Update the height for the current node
    height = max(leftHeight, rightHeight) + 1;

    // The diameter is the maximum of:
    // 1. The diameter of the left subtree
    // 2. The diameter of the right subtree
    // 3. The longest path through the current node
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

// Function to find the diameter of the binary tree
int diameterOfBinaryTree(TreeNode* root) {
    int height = 0;
    return diameterHelper(root, height);
}

int main() {
    // Input the level-order traversal
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<int> nodes(n);
    cout << "Enter the level-order traversal (use -1 for null nodes): " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i];
    }

    // Build the binary tree
    TreeNode* root = buildTree(nodes);

    // Calculate and print the diameter of the binary tree
    cout << "Diameter of the binary tree is: " << diameterOfBinaryTree(root) << endl;

    return 0;
}
