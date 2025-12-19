#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

};

class BinaryTree{
    public:

    bool search(Node* root, int key){ // O(n)
        if(root == nullptr){
            return false;
        }
        if(root->data == key){
            return true;
        }
        bool leftFound = search(root->left, key);
        if(leftFound){
            return true;
        }
        bool rightFound = search(root->right, key);
        if(rightFound){
            return true;
        }

        return false;
    };
};

int main(){
    int data = 1;
    Node* root = new Node(data);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);
    Node* seventh = new Node(7);
    Node* eighth = new Node(8);

    root->left = second;
    root->right = third;
    second->left = fourth;
    second->right = fifth;
    third->left = sixth;
    third->right = seventh;
    seventh->right = eighth;

    int key = 6;
    BinaryTree tree;
    bool value = tree.search(root, key);
    cout << value << endl;

}
