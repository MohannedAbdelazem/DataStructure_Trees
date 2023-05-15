#include "BinaryTrees.h"
BST::Node* BST::insert(Node *node, Student stud){
    if(node == NULL){
        stdDp[stud.getDepartment()]++;
        size++;
        node = new Node();
        node->student->setStudent(stud);
    }
    else if(stud.getID() < node->student->getID()){
        node->left = insert(node->left, stud);
    }
    else if(stud.getID() > node->student->getID()){
        node->right = insert(node->right, stud);
    }
    return node;
}
void BST::printInOrder(BST::Node *node){
    if(node == NULL)
        return;
    printInOrder(node->left);
    node->student->print();
    cout << '\n';
    printInOrder(node->right);
}
BST::Node* BST::removeNode(Node *&node, Student stud){
    if(node == NULL){
        return node;
    }
    else if(stud.getID() < node->student->getID()){
        node->left = removeNode(node->left, stud);
    }
    else if(stud.getID() > node->student->getID()){
        node->right = removeNode(node->right, stud);
    }
    else{
        //which means stud.getID() == node->st->getID()
        stdDp[node->student->getDepartment()]--;
        if(node->left == NULL && node->right == NULL){
            delete node;
            node = NULL;
        }
        else if(node->left == NULL){
            Node* tmp = node;
            node = node->right;
            delete tmp;
        }
        else if(node->right == NULL){
            Node* tmp = node;
            node = node->left;
            delete tmp;
        }
        else{
            Node *predecessor = node->left;
            while(predecessor->right != NULL){
                predecessor = predecessor->right;
            }
            node->student->setStudent(*(predecessor->student));
            node->left = removeNode(node->left, *(predecessor->student));
        }
    }
    return node;
}
bool BST::search(Node *node, Student stud){
    bool result;
    if(node == NULL){
        return false;
    }
    if(node->student->getID() < stud.getID()){
        result = search(node->right, stud);
    }
    else if(node->student->getID() > stud.getID()){
        result = search(node->left, stud);
    }
    else{
        node->student->print();
        cout << '\n';
        return true;
    }
    return result;
}
int BST::getSize(){
    return size;
}
void BST::insert(Student stud){
    root = insert(root, stud);
}
void BST::print(){
    cout << "Print " << size << " Students\n";
    printInOrder(root);
    cout << "Students Per Departments\n";
    for (auto it = stdDp.begin(); it != stdDp.end(); it++){
        cout << it->first << " " << it->second << " Students\n";
    }
}
void BST::remove(Student stud){
    root = removeNode(root, stud);
}
bool BST::search(Student stud){
    bool result = search(root, stud);
    return result;
}