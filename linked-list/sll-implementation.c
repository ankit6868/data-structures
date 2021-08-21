#include <stdio.h>
#include <stdlib.h>

// Structure of linked-list node
struct node {
    int data;
    struct node *next;
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
    new->next = head;
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
    new->data = val;
    new->next = NULL;
    if(head == NULL) {
        head = new;
        return head;
    }
    struct node *ptr = head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }, Value to be inserted
    ptr->next = new;
    return head;
}

/* 
    Deletes front node of the linked list
    Parameters: (Linked list)
*/
struct node * deleteFront(struct node *head) {
    if(head == NULL) {
        printf("Error: Linked list is already empty!\n");
        return NULL;
    }
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

/* 
    Deletes last node of the linked list
    Parameters: (Linked list)
*/
struct node * deleteEnd(struct node *head) {
    if(head == NULL) {
        printf("Error: Linked list is already empty!\n");
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
    Inserts a node at the specific index in the linked list
    Parameters: (Linked list, Index, Value to be inserted)
*/
struct node * insert(struct node *head, int index, int val) {   // index starts at 0
    int len = count(head);
    if(index > len) {
        printf("Error: Index out of bound!\n");
        return head;
    }
    if(index == 0)
        return insertFront(head, val);
    if(index == len)
        return insertEnd(head, val);
    struct node *tmp = (struct node *)malloc(sizeof(*tmp));
    if(tmp == NULL) {
        printf("Error: Heap memory overflow!\n");
        return head;
    }
    struct node *ptr = head;
    while(index-1 != 0) {
        ptr = ptr->next;
        --index;
    }
    tmp->data = val;
    tmp->next = ptr->next;
    ptr->next = tmp;
    return head;
}


/* 
    Deletes a node at that specific index in the linked list
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
        printf("%d", head->data);
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