#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// --- INSERTING NODES ---
TreeNode* insert(TreeNode* root, int val){
    if (root == NULL){
        return new TreeNode(val);
    }
    
    if (val < root->val){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

void preOrderTransversal(TreeNode* root){
    if (root != NULL){
        cout << root->val << " ";
        preOrderTransversal(root->left);
        preOrderTransversal(root->right);
    }
}

void inOrderTransversal(TreeNode* root){
    if (root != NULL){
        inOrderTransversal(root->left);
        cout << root->val << " ";
        inOrderTransversal(root->right);
    }
}

void postOrderTransversal(TreeNode* root){
    if (root != NULL){
        postOrderTransversal(root->left);
        postOrderTransversal(root->right);
        cout << root->val << " ";
    }
}


int main(){
    TreeNode* root = NULL;
    
    root = insert(root, 9);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 13);
    insert(root, 8);
    insert(root, 22);

    preOrderTransversal(root);
    cout << endl;
    inOrderTransversal(root);
    cout << endl;
    postOrderTransversal(root);

    return 0;
}