#include <iostream>
using namespace std;
struct Node{
    int id;
    Node *left,*right;
};
Node* newNode(int id){
    Node* n=new Node(); n->id=id; n->left=n->right=NULL; return n;
}
Node* insert(Node* root,int id){
    if(!root) return newNode(id);
    if(id<root->id) root->left=insert(root->left,id);
    else root->right=insert(root->right,id);
    return root;
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->id<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(!root) return;
    cout<<root->id<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node* root=NULL;
    int ids[]={50,30,70,20,40,60,80};
    int n=7;
    // For your input: 50 30 70 20 40 60 80
    for(int i=0;i<n;i++) root=insert(root,ids[i]);
    cout<<"BST Inorder (sorted IDs): ";
    inorder(root); cout<<endl;
    cout<<"BST Preorder: ";
    preorder(root); cout<<endl;
    cout<<"\nStructure: 50 is root, 30 left, 70 right etc.\n";
    return 0;
}