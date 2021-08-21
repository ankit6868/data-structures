#include <stdio.h>
#include <stdlib.h>

// Structure of linked-list node
struct node {
    int data;
    struct node *prev, *next;
};

/* UTILITY FUNCTIONS */

/* 
    Counts the number of nodes in linked list
    Parameters: (Linked list)
*/
int count(struct node *head) {
    int count = 0;
    while(head != NULL) {
        ++count;
        head = head->next;
    }
    return count;
}

/* 
    Inserts a node at front of the linked list
    Parameters: (Linked list, Value to be inserted)
*/
struct node * insertFront(struct node *head, int val) {
    struct node *new = (struct node *)malloc(sizeof(*new));
    if(new == NULL) {
        printf("Error: Heap memory overflow!\n");
        return head;
    }
    new->data = val;
    new->prev = NULL;
    new->next = head;
    if(head == NULL)
        return new;
    head->prev = new;
    return new;
}

/* 
    Inserts a node at end of the linked list
    Parameters: (Linked list, Value to be inserted)
*/
struct node * insertEnd(struct node *head, int val) {
    struct node *new = (struct node *)malloc(sizeof(*new));
    if(new == NULL) {
        printf("Error: Heap memory overflow!\n");
        return head;
    }
    new->next = NULL;
    if(head == NULL) {
        new->prev = NULL;
        return new;
    }
    struct node *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->prev = ptr;
    return head;
}

/* 
    Deletes front node of the linked list
    Parameters: (Linked list)
*/
struct node * deleteFront(struct node *head) {
    if(head == NULL) {
        printf("Error: Index out of bound!\n");
        return head;
    }
    struct node *ptr = head;
    head = head->next;
    if(head == NULL) {
        free(ptr);
        return head;
    }
    head->prev = NULL;
    free(ptr);
    return head;
}

/* 
    Deletes last node of the linked list
    Parameters: (Linked list)
*/
struct node * deleteEnd(struct node *head) {
    if(head == NULL) {
        printf("Error: Index out of bound");
        return head;
    }
    if(head->next == NULL) {
        free(head);
        return NULL;
    }
    struct node *ptr1 = head, *ptr2;
    while(ptr1->next != NULL) {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }
    ptr2->next = NULL;
    free(ptr1);
    return head;
}

/* OPERATIONS ON LINKED LIST */

/* 
    Inserts a node at the specified index in the linked list
    Parameters: (Linked list, Index, Value to be inserted)
*/
struct node * insert(struct node *head, int index, int val) {
    int len = count(head);
    if(index > len) {
        printf("Error: Index out of bound!\n");
        return head;
    }
    if(index == 0)
        return insertFront(head, val);
    if(index == len)
        return insertEnd(head, val);
    struct node *new = (struct node *)malloc(sizeof(*new));
    if(new == NULL) {
        printf("Error: Heap memory overload!\n");
        return head;
    }
    new->data = val;
    struct node *ptr1 = head, *ptr2;
    while(index != 0) {
        ptr2 = ptr1;
        ptr2 = ptr2->next;
        --index;
    }
    new->next = ptr1;
    new->prev = ptr2;
    ptr1->prev = new;
    ptr2->next = new;
    return head;
}

/* 
    Deletes a node at the specified index in the linked list
    Parameters: (Linked list, Index)
*/
struct node * delete(struct node *head, int index) {
    int len = count(head);
    if(index >= len) {
        printf("Error: Index out of bound!\n");
        return head;
    }
    if(index == 0)
        return deleteFront(head);
    if(index == len-1)
        return deleteEnd(head);
    struct node *ptr1 = head, *ptr2;
    while(index != 0) {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        --index;
    }
    ptr2->next = ptr1->next;
    ptr1->next->prev = ptr2;
    free(ptr1);
    return head;
}

/* 
    Prints all the data in the linked list
    Parameters: (Linked list)
*/
void printList(struct node *head) {
    printf("Linked list: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    struct node *head = NULL;

    head = insert(head, 0, 10);
    head = insertFront(head, 20);
    head = delete(head, 1);
    printList(head);

    return 0;
}