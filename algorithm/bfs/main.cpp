#include <iostream>
#include <queue>

using namespace std;

struct Node {

    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void bfs(Node* root){
    if (root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()){
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left != NULL){
            q.push(curr->left);
        }

        if (curr->right != NULL){
            q.push(curr->right);
        }
    }
}

void dfs(Node* root){
    if (root == NULL){
        return;
    }
    cout << root->data << " "; // Visit the node
    dfs(root->left); // search on the left subtree
    dfs(root->right); // search on the right subtree
}

int main(){
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
    GRAPHICAL REPRESENTATION OF THIS TREE

    Breadth first search - from the root (or some node in graphs) BFS search level by level, 1 lvl deeper,
    2 lvl deeper and so on.

    Depth first search - from the root, DFS search from the left subtree on recursion.

        1
       / \
      2   3
     / \ / \
    4  5 6  7

    */

    bfs(root); // 1 2 3 4 5 6 7
    cout << endl;
    dfs(root); // 1 2 4 5 3 6 7

    return 0;
}