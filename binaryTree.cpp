#include <iostream>

using namespace std;

struct Node{
    Node *left = nullptr;
    Node *right = nullptr;

    int data = 0; 

    Node(int data){
        this->data = data;
    }
};

Node *insert(Node *root, int data){
    if(root == nullptr){
        root = new Node(data);
    }else{
        if(data < root->data){
            root->left = insert(root->left, data);
        }else if(data > root->data){
            root->right = insert(root->right, data);
        }
        //trzeci warunek - jeśli równe
    }

    return root;
}

void printTree(Node *root){
    if(root == nullptr){
        return;
    }

    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main(){
    Node *root = nullptr;

    int data[] = {10, 5, 15, 3, 7, 12, 18};
    int n = sizeof(data) / sizeof(data[0]);

    for(int i = 0; i < n; i++){
        root = insert(root, data[i]);
    }

    printTree(root);

    return 0;
}