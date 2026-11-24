#include<iostream>
using std::cout;

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int val){
        value=val;
        left=nullptr;
        right=nullptr;
    }
};

class bst {
    private:
    Node* root;

    public:
    bst(){
        root = nullptr;
    }
    ~bst(){}

    void insert(const int& value){
        if(root == nullptr) {
            root = new Node(value);
            return;
        }   

        Node* current = root;

        while(true){
            if(value<current->value){
                if(current->left==nullptr){
                    current->left = new Node(value);
                    return;
                }

                current = current->left;
            }
            else if(value>current->value){
                if(current->right==nullptr){
                    current->right = new Node(value);
                    return;
                } 
                current = current->right;
            }
            else return;
        }
    }

    bool search(const int& value){
        Node* current = root;

        while(current!=nullptr){
            if(value == current->value)
                return true;
            else if(value < current->value)
                current = current->left;
            else current = current->right;
        }
        return false;
    }

    void erase(const int& value){
        Node* current = root;
        Node* parent = nullptr;

        while(current != nullptr && current->value != value){
            parent = current;

            if(value<current->value) current = current->left;
            else current = current->right;
        }

        if (current == nullptr) {
            return;
        }

        if(current->left != nullptr && current->right != nullptr){
            Node* next = current->right;
            Node* nextParent = current;

            while (next->left != nullptr) {
                nextParent = next;
                next = next->left;
            }

            current->value = next->value;
            current = next;
            parent = nextParent;
    }

    Node* child = nullptr;

    if (current->left != nullptr) {
        child = current->left;
    }
    else {
        child = current->right;
    }

    if (parent == nullptr) {
        root = child;
    }
    else if (parent->left == current) {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    delete current;
    }


};

int main(){

    bst tree;

    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(7);

    tree.erase(1);  // chuni child
    cout << tree.search(1) << std::endl;   // 0

    tree.erase(6);  // childy 7
    cout << tree.search(6) << std::endl;   // 0
    cout << tree.search(7) << std::endl;   // 1

    tree.erase(8);  // 2 child
    cout << tree.search(8) << std::endl;   // 0
    cout << tree.search(3) << std::endl;   // 1
    cout << tree.search(7) << std::endl;   // 1
    cout << tree.search(10) << std::endl;  // 1

    tree.erase(100);
    return 0;
}
