#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

struct Node* addAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

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

struct Node* addAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    
    if (position == 1) {
        return addAtBeginning(head, data);
    }
    
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    int currentPos = 1;
    
    while (current != NULL && currentPos < position - 1) {
        current = current->next;
        currentPos++;
    }
    
    if (current == NULL) {
        printf("Position out of bounds!\n");
        free(newNode);
        return head;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* removeFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node* removeFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
    return head;
}

struct Node* removeByValue(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (head->data == value) {
        struct Node* temp = head->next;
        free(head);
        return temp;
    }
    
    struct Node* current = head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next == NULL) {
        printf("Value %d not found!\n", value);
        return head;
    }
    
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("List: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}

void displayMenu() {
    printf("\nLinked List Operations:\n");
    printf("1. Add at beginning\n");
    printf("2. Add at end\n");
    printf("3. Add at position\n");
    printf("4. Remove from beginning\n");
    printf("5. Remove from end\n");
    printf("6. Remove by value\n");
    printf("7. Display list\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to add at beginning: ");
                scanf("%d", &data);
                head = addAtBeginning(head, data);
                printf("Added %d at beginning\n", data);
                break;
                
            case 2:
                printf("Enter data to add at end: ");
                scanf("%d", &data);
                head = addAtEnd(head, data);
                printf("Added %d at end\n", data);
                break;
                
            case 3:
                printf("Enter data to add: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = addAtPosition(head, data, position);
                break;
                
            case 4:
                head = removeFromBeginning(head);
                printf("Removed from beginning\n");
                break;
                
            case 5:
                head = removeFromEnd(head);
                printf("Removed from end\n");
                break;
                
            case 6:
                printf("Enter value to remove: ");
                scanf("%d", &data);
                head = removeByValue(head, data);
                break;
                
            case 7:
                printList(head);
                break;
                
            case 8:
                printf("Exiting program\n");
                freeList(head);
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}