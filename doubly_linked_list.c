#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
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
    new_node->prev = NULL;

    return new_node;

}

// double pointer to head is passed so the value at the head node can actually be edited, otherwise just a copy of head would be edited
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

// removes a node if it exists, returns 1 if successful, 0 if not
int remove_node(struct Node** head, int value){

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL){
        if (temp->val == value){
            // if you do not do a null pointer check on prev, you could get a seg fault if the head value is the value to be deleted
            if (prev){
                prev->next = temp->next;
            }
            else{
                *head = temp->next;
            }
            free(temp);
            return 1;
        }
        prev = temp;
        temp = temp->next;
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

    int removal = remove_node(&head, 5);

    if (!removal)
        puts("node was unable to be deleted in linked list");

    print_nodes(head);

    return 0;
}
