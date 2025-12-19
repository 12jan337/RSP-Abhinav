#include <iostream>
#include <map>

using namespace std;

class Node{
    public:
        unordered_map<char, Node*> children;
        bool endOfWord;

        Node(){
            this->endOfWord = false;
        }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }

        void insert(string key){
            Node* temp = root;

            for(int i = 0; i < key.size(); i++){
                if(temp->children.count(key[i]) == 0){
                    temp->children[key[i]] = new Node();
                }
                temp = temp->children[key[i]];
            }
            temp->endOfWord = true;
        }
       
       bool search (string key) {// O(L)
            Node* temp = root;
            for (int i =0; i<key.size(); i++) {
            if(temp->children.count(key[i])){
            temp = temp->children[key[i]];
            }else {
            return false;
            }
        }
    return temp->endOfWord;
    }

};
        
