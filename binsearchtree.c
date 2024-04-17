#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newnode(int item);
void inorder(struct node *root);
struct node *insert (struct node *node, int key);

struct node *newnode(int item){
    struct node *temp ;
    temp =  malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inorder(struct node * root){
    if (root != NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
struct node * insert(struct node *node,int key){
    if (node == NULL)
        return newnode(key);
    if (key < node->data)
        node->left = insert(node->left,key);
    else if (key > node->data)
        node->right = insert(node->right,key);
    return node;
}
int main(){
    struct node * root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    inorder(root);
    return 0;
    
}