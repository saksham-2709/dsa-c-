#include<stdio.h>
#include<stdlib.h>
struct node {
int data;
struct node *left;
struct node *right;
};
struct node * root;
struct node * create();
void display(struct node *);
void construct();
void main()
{
construct();
display(root);
}
void construct()
{
root=create();
root->data = 50;
root->left = create();
root->left->data =20;
root-> right = create();
root->right->data = 60;
root->left->left =create();
root->left->left->data = 70;
root->left->right =create();
root->left->right->data = 80;

}
struct node * create()
{
struct node *p;
p=(struct node *)malloc(sizeof(struct node));
p->left=NULL;
p->right=NULL;
return p;
}
void display(struct node *p)
{
if(p!=NULL)
{
display(p->left);
printf("%d\t",p->data);
display(p->right);
}
}