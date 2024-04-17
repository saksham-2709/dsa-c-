#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct node {
    int data;
    struct node *link;
};

// Global pointer to the first node of the circular linked list
struct node *first = NULL;

// Function to create a circular linked list
struct node *create() {
    char ch;
    struct node *ptr, *cpt;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for first node: ");
    scanf("%d", &ptr->data);
    ptr->link = ptr; // Linking the first node to itself
    first = ptr;
    printf("Enter 'y' for next node and 'n' for exit: ");
    scanf(" %c", &ch);
    while (ch == 'y' || ch == 'Y') {
        cpt = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for next node: ");
        scanf("%d", &cpt->data);
        ptr->link = cpt;
        cpt->link = first; // Linking the last node to the first node
        ptr = cpt;
        printf("Enter 'y' for next node and 'n' for exit: ");
        scanf(" %c", &ch);
    }
    return first;
}

// Function to display a circular linked list
void display(struct node *first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *ptr = first;
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    } while (ptr != first);
    printf("\n");
}

int main() {
    first = create(); // Create circular linked list
    printf("Circular linked list: ");
    display(first);   // Display circular linked list
    return 0;
}
