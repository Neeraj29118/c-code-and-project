#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Enhanced create node function with error handling
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add element at specific position
struct Node* addAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    
    // If adding at beginning
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    
    struct Node* current = head;
    int currentPos = 1;
    
    // Move to position - 1
    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }
    
    // If position is valid
    if (current != NULL) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        printf("Position %d is out of bounds\n", position);
        free(newNode);
        return head;
    }
    
    return head;
}

// Add element at beginning
struct Node* addAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Add element at end
struct Node* addAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Remove element from specific position
struct Node* removeFromPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    
    // If removing first node
    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node* current = head;
    int currentPos = 1;
    
    // Move to position - 1
    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }
    
    // If position is valid and not last node
    if (current != NULL && current->next != NULL) {
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    } else {
        printf("Position %d is out of bounds\n", position);
    }
    
    return head;
}

// Remove element by value
struct Node* removeByValue(struct Node* head, int value) {
    struct Node *temp = head, *prev = NULL;
    
    // If head node has the value
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return head;
    }
    
    // Search for the value
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    // If value not found
    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return head;
    }
    
    // Remove the node
    prev->next = temp->next;
    free(temp);
    return head;
}

// Print the list
void printList(struct Node* head) {
    struct Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free the list
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* head = NULL;
    
    // Create initial list
    printf("\n1. Creating initial list:\n");
    head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    printList(head);
    
    // Add elements at different positions
    printf("\n2. Adding elements:\n");
    head = addAtBeginning(head, 5);
    printf("After adding 5 at beginning: ");
    printList(head);
    
    head = addAtEnd(head, 40);
    printf("After adding 40 at end: ");
    printList(head);
    
    head = addAtPosition(head, 25, 4);
    printf("After adding 25 at position 4: ");
    printList(head);
    
    // Remove elements
    printf("\n3. Removing elements:\n");
    head = removeFromPosition(head, 1);
    printf("After removing from position 1: ");
    printList(head);
    
    head = removeByValue(head, 25);
    printf("After removing value 25: ");
    printList(head);
    
    // Try to remove non-existent element
    printf("\n4. Testing error handling:\n");
    head = removeByValue(head, 100);
    head = removeFromPosition(head, 10);
    
    // Clean up
    freeList(head);
    
    return 0;
}