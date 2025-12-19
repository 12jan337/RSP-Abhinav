#include <iostream>
#include <vector>

using namespace std;

class Node{
    
    public:
        Node* next;
        int data;
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }

};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = nullptr;
        }

        void insertNode(int data){
            Node* newNode = new Node(data);

            if(head == nullptr){
                head = newNode;
            }
            if(head->next == nullptr){
                newNode->next = head;
                head = newNode;
            }
        }

        void deleteNode(int target){
            if(head == nullptr){
                return;
            }
            if(head->data == target){
                Node* temp = head;
                head = head->next;
                delete temp;
            }

            int count = 1;
            Node* current = head;

            while(current->next != nullptr && current->next->data != target){
                current = current->next;
            }

            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;

        }

};// To insert in the front it takes O(1), in the end O(n), and at a specific position it takes O(n) as well, in case of a singly linked list