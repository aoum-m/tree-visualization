
#include <graphics.h>
#include "library.h"
#include <iostream> 

using namespace std;


BSTNode* insertBSTNode(BSTNode* root, int data) {
    if (!root) {
        root = new BSTNode();
        root->data = data;
        root->left = root->right = nullptr;
    } else if (data < root->data) {
        root->left = insertBSTNode(root->left, data);
    } else {
        root->right = insertBSTNode(root->right, data);
    }
    return root;
}

void displayBST(BSTNode* root, int x, int y, int offset) {
    if (!root) return;
    char value[10];
    sprintf(value, "%d", root->data);

    circle(x, y, 20);
    outtextxy(x - 10, y - 10, value);

    if (root->left) {
        line(x, y, x - offset, y + 50);  
        displayBST(root->left, x - offset, y + 50, offset / 1.5);  
    }
    if (root->right) {
        line(x, y, x + offset, y + 50);  
        displayBST(root->right, x + offset, y + 50, offset / 1.5);  
    }
}


int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalanceFactor(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode* insertAVLNode(AVLNode* root, int data) {
    if (!root) {
        root = new AVLNode();
        root->data = data;
        root->left = root->right = nullptr;
        root->height = 1;
        return root;
    }

    if (data < root->data) {
        root->left = insertAVLNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertAVLNode(root->right, data);
    } else {
        return root; 
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1 && data < root->left->data)
        return rotateRight(root);

    if (balance < -1 && data > root->right->data)
        return rotateLeft(root);

    if (balance > 1 && data > root->left->data) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void displayAVL(AVLNode* root, int x, int y, int offset) {
    if (!root) return;
    char value[10];
    sprintf(value, "%d", root->data);

    circle(x, y, 20);
    outtextxy(x - 10, y - 10, value);

    if (root->left) {
        line(x, y, x - offset, y + 50);  
        displayAVL(root->left, x - offset, y + 50, offset / 1.5); 
    }
    if (root->right) {
        line(x, y, x + offset, y + 50);  
        displayAVL(root->right, x + offset, y + 50, offset / 1.5); 
    }
}


void heapify(int heap[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(heap, size, largest);
    }
}

void heapSort(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(heap, size, i);

    for (int i = size - 1; i > 0; i--) {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

void displayHeap(int heap[], int size, int x, int y, int offset) {
    int nodesOnLevel = 1; 
    int xOffset = offset;  
    int currentX = x;  

    for (int i = 0; i < size; i++) {
        char value[10];
        sprintf(value, "%d", heap[i]);
        setcolor(WHITE);
        circle(currentX, y, 20); 
        outtextxy(currentX - 10, y - 10, value); 
        
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < size) {
            line(currentX, y + 20, currentX - xOffset, y + 50);  
        }
        if (rightChild < size) {
            line(currentX, y + 20, currentX + xOffset, y + 50); 
        }

        if (i == nodesOnLevel - 1) {
            y += 60; 
            currentX -= xOffset;  
            nodesOnLevel *= 2; 
            xOffset /= 2;  
        } else {
            currentX += 40;  
        }
    }
}

void initializeGraphics() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
}

void clearScreen() {
    cleardevice();
}

void autoDisplay(BSTNode* bstRoot, AVLNode* avlRoot, int heap[], int heapSize) {
    clearScreen();

    displayBST(bstRoot, 100, 60, 70); 

    displayHeap(heap, heapSize, 500, 60, 70); 

    displayAVL(avlRoot, 300, 60, 70); 
    delay(2000); 
}


