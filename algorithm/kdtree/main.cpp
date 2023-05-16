#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
    double x, y;

    Point(double x = 0, double y = 0): x(x), y(y) {}

};

class Node {
public:
    Point point;
    Node *left;
    Node *right;


    Node(Point point) : point(point), left(NULL), right (NULL) {}

};

class KDTree {
public:
    Node *root;

    KDTree() : root(NULL) {}

    void insert(Point point){
        root = insertHelper(root, point, 0);
    }

    Node* insertHelper(Node *node, Point point, int depth){
        if (node == NULL){
            return new Node(point);
        }

        int currentDepth = depth % 2;

        if (point.x < node->point.x){
            node->left = insertHelper(node->left, point, depth+1);
        } else {
            node->right = insertHelper(node->right, point, depth+1);
        }

        return node;
    }

    void printInorder(Node *node){
        if (node != NULL){
            printInorder(node->left);
            cout << "(" << node->point.x << ", " << node->point.y << ")" << endl;
            printInorder(node->right);
        }
    }


};

int main(){

    KDTree kdtree;

    kdtree.insert(Point(3, 6));
    kdtree.insert(Point(17, 15));
    kdtree.insert(Point(9, 12));
    kdtree.insert(Point(32, 0));
    kdtree.insert(Point(2, 2));
    kdtree.insert(Point(3, 5));
    kdtree.insert(Point(7, -1));

    kdtree.printInorder(kdtree.root);


    return 0;
}