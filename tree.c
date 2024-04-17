#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right ;

};
struct node * root;
struct node * create();
void display(struct node*);
void construct();
int height (struct node * root);
void main(){
    construct();
    display(root);
    printf("height of tree is %d\n",height(root));
}
void construct(){
    root = create();
    root->data = 50;
    root -> left = create();
    root -> left -> data = 20;
    root -> right = create();
    root -> right -> data = 30;
    root -> left -> left = create();
    root -> left ->left -> data = 70;
    root -> left -> right = create();

    root -> left -> right -> data = 80;
}
struct node * create(){
    struct node * ptr;
    ptr = (struct node *)malloc (sizeof(struct node));
    ptr -> left = NULL;
    ptr -> right = NULL;

} 
void display(struct node * ptr){
    if (ptr != NULL){
        display(ptr-> left);
        printf("%d\t",ptr -> data);
        display(ptr -> right);
    }

}
int height (struct node * root){
    int lh,rh;
    if (root ==NULL){
        return 0;

    }
else{
    lh = height(root ->left);
    rh = height(root -> right);}
    if (lh > rh){
        return lh +1;
    }else{
        return rh +1;
    }

}