#include<iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class bst {
    private:
    Node* root;

    

};