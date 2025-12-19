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
        };
};

class LinkedList{
    private:
        Node* head;
    public:

    LinkedList(){
        head = nullptr;
    }

    Node* insertInFront(int data){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return newNode;
    }
    void insertInEnd(int data){
        Node* newNode = new Node(data);
        Node* current = head;

        if(current == nullptr){
            head = newNode;
            return;
        }

        while(current->next != nullptr){
            current = current->next;
        }

        current->next = newNode;
    }

    void insertInPos(int data, int pos){
        Node* newNode = new Node(data);
        Node* current = head;

        if(current == nullptr){
            head = newNode;
            return;
        }
        if(pos <= 1){
        newNode->next = head;
        head = newNode;
        return;
    }

        int count = 1;

        while(current->next != nullptr && count < pos - 1){
            current = current->next;
            count++;
        }

        newNode->next = current->next;
        current->next= newNode;


    }

    Node* deleteinFront(){
        if(head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return head;
    }

     void deleteValue(int value){
        if(head == nullptr){
            return;
        }
        if(head->data == value){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        
        Node* current = head;

        while(current->next != nullptr && current->next->data != value){
            current = current->next;
        }
        if(current->next == nullptr){
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;

    }

    int search(int target){
        if(head == nullptr){
            return -1;
        }
    
        Node* current = head;
        int count = 0;

        while(current != nullptr && current->data != target){
            current = current->next;
            count++;

        }
        if(current == nullptr){
            return -1;
        }

        return count;
    }

};
