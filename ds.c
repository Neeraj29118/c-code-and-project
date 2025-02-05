#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definitions
// 1. Array Operations
#define MAX_SIZE 100

struct Array {
    int arr[MAX_SIZE];
    int size;
};

// 2. Linked List
struct Node {
    int data;
    struct Node* next;
};

// 3. Stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// 4. Queue
struct Queue {
    int arr[MAX_SIZE];
    int front, rear;
};

// 5. Binary Search Tree Node
struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

// Function Declarations
// Array Operations
void initArray(struct Array* array);
void insertArray(struct Array* array, int position, int value);
void deleteArray(struct Array* array, int position);
void displayArray(struct Array* array);

// Linked List Operations
struct Node* createNode(int data);
struct Node* insertLinkedList(struct Node* head, int data, int position);
struct Node* deleteLinkedList(struct Node* head, int position);
void displayLinkedList(struct Node* head);

// Stack Operations
void initStack(struct Stack* stack);
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
void displayStack(struct Stack* stack);

// Queue Operations
void initQueue(struct Queue* queue);
void enqueue(struct Queue* queue, int value);
int dequeue(struct Queue* queue);
void displayQueue(struct Queue* queue);

// BST Operations
struct TreeNode* createTreeNode(int data);
struct TreeNode* insertBST(struct TreeNode* root, int data);
struct TreeNode* deleteBST(struct TreeNode* root, int data);
void inorderTraversal(struct TreeNode* root);

// Implementation of Array Operations
void initArray(struct Array* array) {
    array->size = 0;
}

void insertArray(struct Array* array, int position, int value) {
    if (array->size >= MAX_SIZE) {
        printf("Array is full!\n");
        return;
    }
    if (position < 0 || position > array->size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = array->size; i > position; i--) {
        array->arr[i] = array->arr[i-1];
    }
    array->arr[position] = value;
    array->size++;
}

void deleteArray(struct Array* array, int position) {
    if (position < 0 || position >= array->size) {
        printf("Invalid position!\n");
        return;
    }
    for (int i = position; i < array->size - 1; i++) {
        array->arr[i] = array->arr[i+1];
    }
    array->size--;
}

void displayArray(struct Array* array) {
    if (array->size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->arr[i]);
    }
    printf("\n");
}

// Implementation of Linked List Operations
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertLinkedList(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

struct Node* deleteLinkedList(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    if (position == 0) {
        struct Node* temp = head->next;
        free(head);
        return temp;
    }
    struct Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    if (current == NULL || current->next == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

void displayLinkedList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List elements: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Implementation of Stack Operations
void initStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(struct Stack* stack) {
    if (stack->top < 0) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

void displayStack(struct Stack* stack) {
    if (stack->top < 0) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Implementation of Queue Operations
void initQueue(struct Queue* queue) {
    queue->front = queue->rear = -1;
}

void enqueue(struct Queue* queue, int value) {
    if (queue->rear >= MAX_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = value;
}

int dequeue(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty!\n");
        return -1;
    }
    return queue->arr[queue->front++];
}

void displayQueue(struct Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

// Implementation of BST Operations
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertBST(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createTreeNode(data);
    }
    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }
    return root;
}

struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct TreeNode* deleteBST(struct TreeNode* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteBST(root->left, data);
    } else if (data > root->data) {
        root->right = deleteBST(root->right, data);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        struct TreeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function with menu-driven program
int main() {
    struct Array array;
    struct Node* linkedList = NULL;
    struct Stack stack;
    struct Queue queue;
    struct TreeNode* bst = NULL;
    
    int choice, subChoice, value, position;
    
    initArray(&array);
    initStack(&stack);
    initQueue(&queue);

    while (1) {
        printf("\n=== DSA Operations Menu ===\n");
        printf("1. Array Operations\n");
        printf("2. Linked List Operations\n");
        printf("3. Stack Operations\n");
        printf("4. Queue Operations\n");
        printf("5. Binary Search Tree Operations\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Array Operations
                printf("\n=== Array Operations ===\n");
                printf("1. Insert\n2. Delete\n3. Display\n4. Back to main menu\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        printf("Enter value and position: ");
                        scanf("%d %d", &value, &position);
                        insertArray(&array, position, value);
                        break;
                    case 2:
                        printf("Enter position to delete: ");
                        scanf("%d", &position);
                        deleteArray(&array, position);
                        break;
                    case 3:
                        displayArray(&array);
                        break;
                }
                break;

            case 2: // Linked List Operations
                printf("\n=== Linked List Operations ===\n");
                printf("1. Insert\n2. Delete\n3. Display\n4. Back to main menu\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        printf("Enter value and position: ");
                        scanf("%d %d", &value, &position);
                        linkedList = insertLinkedList(linkedList, value, position);
                        break;
                    case 2:
                        printf("Enter position to delete: ");
                        scanf("%d", &position);
                        linkedList = deleteLinkedList(linkedList, position);
                        break;
                    case 3:
                        displayLinkedList(linkedList);
                        break;
                }
                break;

            case 3: // Stack Operations
                printf("\n=== Stack Operations ===\n");
                printf("1. Push\n2. Pop\n3. Display\n4. Back to main menu\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        printf("Enter value to push: ");
                        scanf("%d", &value);
                        push(&stack, value);
                        break;
                    case 2:
                        value = pop(&stack);
                        if (value != -1)
                            printf("Popped value: %d\n", value);
                        break;
                    case 3:
                        displayStack(&stack);
                        break;
                }
                break;

            case 4: // Queue Operations
                printf("\n=== Queue Operations ===\n");
                printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Back to main menu\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        printf("Enter value to enqueue: ");
                        scanf("%d", &value);
                        enqueue(&queue, value);
                        break;
                    case 2:
                        value = dequeue(&queue);
                        if (value != -1)
                            printf("Dequeued value: %d\n", value);
                        break;
                    case 3:
                        displayQueue(&queue);
                        break;
                }
                break;

            case 5: // BST Operations
                printf("\n=== Binary Search Tree Operations ===\n");
                printf("1. Insert\n2. Delete\n3. Display (Inorder)\n4. Back to main menu\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1:
                        printf("Enter value to insert: ");
                        scanf("%d", &value);
                        bst = insertBST(bst, value);
                        break;
                    case 2:
                        printf("Enter value to delete: ");
                        scanf("%d", &value);
                        bst = deleteBST(bst, value);
                        break;
                    case 3:
                        printf("BST elements (Inorder): ");
                        inorderTraversal(bst);
                        printf("\n");
                        break;
                }
                break;

            case 6: // Exit
                printf("Thank you for using the program!\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}