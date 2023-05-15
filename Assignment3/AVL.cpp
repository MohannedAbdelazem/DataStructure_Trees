#include "BinaryTrees.h"
int AVL::calculateHeight(Node* node){
    if(node == NULL){
        return -1;
    }
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }else{
        return rightHeight + 1;
    }
}
int AVL::calculateBalance(Node* node){
    if(node==NULL){
        return -1;
    }
    return (calculateHeight(node->left) - calculateHeight(node->right));
}
AVL::Node* AVL::rightRotate(Node* node){
    Node *otherNode = node->left;
    Node *subTree = otherNode->right;
    otherNode->right = node;
    node->left = subTree;
    return otherNode;
}
AVL::Node* AVL::leftRotate(Node *node) {
    Node *otherNode = node->right;
    Node *subTree = otherNode->left; 
    otherNode->left = node;
    node->right = subTree;
    return otherNode;
}
AVL::Node* AVL::insert(Node* node, Student stud) {
    node = BST::insert(node, stud);
    int balanceFactor = calculateBalance(node);

    // Left Left Case
    if (balanceFactor > 1 && stud.getID() < node->left->student->getID())
        return rightRotate(node);

    // Right Right Case
    if (balanceFactor < -1 && stud.getID() > node->right->student->getID())
        return leftRotate(node);

    // Left Right Case
    if (balanceFactor > 1 && stud.getID() > node->left->student->getID()) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balanceFactor < -1 && stud.getID() < node->right->student->getID()) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
AVL::Node* AVL::removeNode(Node* node, Student stud) {
    node = BST::removeNode(node, stud);
    if (node == NULL)
        return node;

    int balanceFactor = calculateBalance(node);

    if (balanceFactor > 1 && calculateBalance(node->left) >= 0)
        return rightRotate(node);

    if (balanceFactor > 1 && calculateBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balanceFactor < -1 && calculateBalance(node->right) <= 0)
        return leftRotate(node);

    if (balanceFactor < -1 && calculateBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void AVL::insert(Student stud) {
    root = AVL::insert(root, stud);
}
void AVL::remove(Student stud){
    root = AVL::removeNode(root, stud);
}