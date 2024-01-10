#include <stdio.h>
#include <stdlib.h>

// Node structure for Red-Black Tree
struct Node {
    int data;
    char color;  // 'R' for red, 'B' for black
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->color = 'R';  // New nodes are always red
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform left rotation
void leftRotate(struct Node** root, struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    
    if (y->left != NULL)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

// Function to perform right rotation
void rightRotate(struct Node** root, struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

// Function to fix the Red-Black Tree after insertion
void fixInsert(struct Node** root, struct Node* z) {
    while (z->parent != NULL && z->parent->color == 'R') {
        if (z->parent == z->parent->parent->left) {
            struct Node* y = z->parent->parent->right;
            if (y != NULL && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                rightRotate(root, z->parent->parent);
            }
        } else {
            // Symmetric case for left and right swapped
            // (change 'left' to 'right' and vice versa)
            struct Node* y = z->parent->parent->left;
            if (y != NULL && y->color == 'R') {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(root, z);
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                leftRotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = 'B';  // Root should always be black
}

// Function to insert a node into the Red-Black Tree
void insert(struct Node** root, int data) {
    struct Node* z = createNode(data);
    struct Node* y = NULL;
    struct Node* x = *root;

    while (x != NULL) {
        y = x;
        if (z->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == NULL)
        *root = z;
    else if (z->data < y->data)
        y->left = z;
    else
        y->right = z;

    fixInsert(root, z);
}

// Helper function to find the node with minimum value in a subtree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Function to fix the Red-Black Tree after deletion
void fixDelete(struct Node** root, struct Node* x) {
    while (x != *root && (x == NULL || x->color == 'B')) {
        if (x == x->parent->left) {
            struct Node* w = x->parent->right;
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            if ((w->left == NULL || w->left->color == 'B') && (w->right == NULL || w->right->color == 'B')) {
                w->color = 'R';
                x = x->parent;
            } else {
                if (w->right == NULL || w->right->color == 'B') {
                    if (w->left != NULL)
                        w->left->color = 'B';
                    w->color = 'R';
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 'B';
                if (w->right != NULL)
                    w->right->color = 'B';
                leftRotate(root, x->parent);
                x = *root;  // Exit the loop
            }
        } else {
            // Symmetric case for left and right swapped
            struct Node* w = x->parent->left;
            if (w->color == 'R') {
                w->color = 'B';
                x->parent->color = 'R';
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if ((w->right == NULL || w->right->color == 'B') && (w->left == NULL || w->left->color == 'B')) {
                w->color = 'R';
                x = x->parent;
            } else {
                if (w->left == NULL || w->left->color == 'B') {
                    if (w->right != NULL)
                        w->right->color = 'B';
                    w->color = 'R';
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 'B';
                if (w->left != NULL)
                    w->left->color = 'B';
                rightRotate(root, x->parent);
                x = *root;  // Exit the loop
            }
        }
    }
    if (x != NULL)
        x->color = 'B';
}

// Function to delete a node from the Red-Black Tree
void deleteNode(struct Node** root, int data) {
    struct Node* z = *root;
    struct Node* x, *y;
    while (z != NULL) {
        if (z->data == data)
            break;
        if (z->data < data)
            z = z->right;
        else
            z = z->left;
    }

    if (z == NULL) {
        printf("Node with data %d not found in the tree.\n", data);
        return;
    }

    y = z;
    char y_original_color = y->color;
    if (z->left == NULL) {
        x = z->right;
        transplant(root, z, z->right);
    } else if (z->right == NULL) {
        x = z->left;
        transplant(root, z, z->left);
    } else {
        y = minValueNode(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            if (x != NULL)
                x->parent = y;
        } else {
            transplant(root, y, y->right);
            y->right = z->right;
            if (y->right != NULL)
                y->right->parent = y;
        }
        transplant(root, z, y);
        y->left = z->left;
        if (y->left != NULL)
            y->left->parent = y;
        y->color = z->color;
    }

    if (y_original_color == 'B')
        fixDelete(root, x);

    free(z);
}

// Function to replace one subtree with another in the Red-Black Tree
void transplant(struct Node** root, struct Node* u, struct Node* v) {
    if (u->parent == NULL)
        *root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != NULL)
        v->parent = u->parent;
}

// Function to perform in-order traversal of the Red-Black Tree
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d (%c) ", root->data, root->color);
        inOrderTraversal(root->right);
    }
}

// Function to free the memory allocated for the Red-Black Tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert nodes into the Red-Black Tree
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);
    insert(&root, 15);

    // Print the Red-Black Tree (in-order)
    printf("Red-Black Tree (in-order): ");
    inOrderTraversal(root);
    printf("\n");

    // Delete a node from the Red-Black Tree
    deleteNode(&root, 12);

    // Print the Red-Black Tree again after deletion
    printf("Red-Black Tree (in-order) after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    // Free the memory allocated for the Red-Black Tree
    freeTree(root);

    return 0;
}
