#include <iostream>

using namespace std;

/*
    N : nodes === N - 1 : Edges

    Depth of x = length of path from root to z or No. of edges in path from root to z
    Height of x = No. of edges in longest path from x to a leaf
    Binary tree = a tree in which each node can have at most 2 children

    -- Aplications --
    1 - Storing naturally hierachical data -> e.g: file system

    2 - Organize data for quick search, insertion, deletion -> e.g: binary search trees

    3 - Trie -> dictionary

    4 - Network routing algorithm

    ::::: TOPIC: BINARY TREE :::::

    * Max no. of nodes at level i = 2^i
    
    * Maximum no. of nodes in a b-tree with heigh h = 2^(no. of levels) - 1 || h = log2 (n+1) - 1
    
    * Balanced binary tree === difference between height of left and right subtree for every node is not more than K
    mostly equals to 1.

    diff = | Hleft - Hright | < = 1 ---> FOR ANY NODE

    ::::: TOPIC: BINARY SEARCH TREE :::::

    - Big-O for Insert, remove and search is O(log n)
    - a BST in which for each node, value of all the nodes in left subtree is lesser or equal and value of all the nods
    in right subtree is greater

         15
       /    \
      10     20
     / \    / \
    8   12 17  25

*/

// Node from a binary tree
struct Node {
    int val;
    Node* right;
    Node* left;

    // Constructors
    Node(int val){
        this->val = val;
        right = nullptr;
        left = nullptr;
    }
};

class SearchBinaryTree {
    public:
        SearchBinaryTree(){
            root = nullptr;
        }

        // destruct that free the tree memory
        ~SearchBinaryTree(){
            destroySubtree(root);
        }

        void insert(int val){
            root = insertRecursive(root, val);
        }

        bool search(int val) {
            return searchRecursive(root, val);
        }

    private:
        Node* root;

        Node* insertRecursive(Node* node, int val){
            if (node == nullptr){
                return new Node(val);
            }

            if (val <= node->val){
                node->left = insertRecursive(node->left, val);
            } else {
                node->right = insertRecursive(node->right, val);
            }

            return node;
        }

        bool searchRecursive(Node* node, int val){
            if (node == nullptr){
                return false;
            }

            if (val == node->val){
                return true;
            } else if (val < node->val){
                return searchRecursive(node->left, val);
            } else {
                return searchRecursive(node->right, val);
            }
        }

        void destroySubtree(Node* node){
            if (node != nullptr){
                destroySubtree(node->left);
                destroySubtree(node->right);
                delete node;
            }
        }

        Node* leftRotate(Node* root) {
            if (root == nullptr || root->right == nullptr) {
                return root; // não pode rotacionar
            }

            Node* newRoot = root->right;
            root->right = newRoot->left;
            newRoot->left = root;

            return newRoot;
        }

        Node* rightRotate(Node* root) {
            if (root == nullptr || root->left == nullptr)
                return root;

            Node* newRoot = root->left;
            root->left = newRoot->right;
            newRoot->right = root;

            return newRoot;
        }
};

int main(){

    SearchBinaryTree tree;

    tree.insert(5);
    tree.insert(1);
    tree.insert(9);
    tree.insert(65);
    tree.insert(-2);
    tree.insert(452);
    tree.insert(-4);
    tree.insert(0);
    tree.insert(5);

    cout << tree.search(5) << endl;
    cout << tree.search(99) << endl;

    return 0;
}