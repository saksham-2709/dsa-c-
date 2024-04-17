#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;

};
struct node * first;
void display(){
    struct node * ptr ;
    ptr = first;
    int sum = 0;
    while(ptr != NULL){
        printf("%d\t",ptr-> data);
        
        
        ptr = ptr -> link;

    }

}

struct node * create(){
    char ch;
    struct node * ptr,*cpt;
   ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data for first node:");
    scanf("%d",&ptr->data);
    ptr->link = NULL;
    first = ptr;
    do{
        cpt = (struct node *)malloc(sizeof(struct node));
        printf("enter data for next node:");
        scanf("%d",&cpt->data);
        ptr->link=cpt;
        ptr = cpt;
        printf("enter y for next node and n for exit:");
        scanf(" %c", &ch);
    }
     while(ch== 'y'||ch=='Y');

    ptr->link = NULL;
    return first;
}
void reverse(){
    struct node * prev,* next,*curr;
    curr = first;
    prev = NULL;
    next = NULL;

    while (curr != NULL){
        next = curr -> link;
        curr ->link = prev;
        prev = curr;
        curr = next;

    }
    first = prev;

}
int main(){
    struct node *head =    create();
    display();
    // reverse();
    // display();
    return 0;
}