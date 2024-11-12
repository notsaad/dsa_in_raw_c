#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node* next;
};

void print_nodes(struct Node* head){
    printf("Node Values:");
    while (head != NULL){
        printf(" %d", head->val);
        head = head->next;
    }
    printf("\n");
    return;
}

struct Node* make_node(int value){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node*));

    if (new_node == NULL){
        puts("malloc returned null");
        return NULL;
    }

    new_node->val = value;
    new_node->next = NULL;

    return new_node;

}

void insert_node(struct Node** head, int value){
    struct Node* new_node = make_node(value);

    if (new_node == NULL) {
        puts("new node creation failed");
        return;
    }

    struct Node* last_node = *head;

    if (*head == NULL){
        *head = new_node;
        return;
    }

    while (last_node->next != NULL){
        last_node = last_node->next;
    }

    last_node->next = new_node;
    

    return;
}

// returns true (1) if a node with the desired value exists anywhere in the linked list
int node_exists(struct Node* head, int value){
    while (head != NULL){
        if (head->val == value){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main(){
    struct Node* head = NULL;

    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    print_nodes(head);

    return 0;
}
