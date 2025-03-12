//#ifndef LIBRARY_H
//#define LIBRARY_H
//
//#include <graphics.h>
//
//// Binary Search Tree (BST) Node
//struct BSTNode {
//    int data;
//    BSTNode* left;
//    BSTNode* right;
//};
//
//// AVL Tree Node
//struct AVLNode {
//    int data;
//    AVLNode* left;
//    AVLNode* right;
//    int height;
//};
//
//// Function Prototypes
//
//// BST Functions
//BSTNode* insertBSTNode(BSTNode* root, int data);
//void displayBST(BSTNode* root, int x, int y, int offset);
//
//// AVL Tree Functions
//AVLNode* insertAVLNode(AVLNode* root, int data);
//int getHeight(AVLNode* node);
//int getBalanceFactor(AVLNode* node);
//AVLNode* rotateRight(AVLNode* y);
//AVLNode* rotateLeft(AVLNode* x);
//void displayAVL(AVLNode* root, int x, int y, int offset);
//
//// Heap Functions
//void heapSort(int heap[], int size);
//void displayHeap(int heap[], int size, int x, int y, int offset);
//
//// Utility Functions
//void initializeGraphics();
//void clearScreen();
//void autoDisplay(BSTNode* bstRoot, AVLNode* avlRoot, int heap[], int heapSize);
//
//#endif
#ifndef LIBRARY_H
#define LIBRARY_H

#include <graphics.h>
#include <iostream>

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};


struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};


BSTNode* insertBSTNode(BSTNode* root, int data);
void displayBST(BSTNode* root, int x, int y, int offset);


int getHeight(AVLNode* node);
int getBalanceFactor(AVLNode* node);
AVLNode* rotateRight(AVLNode* y);
AVLNode* rotateLeft(AVLNode* x);
AVLNode* insertAVLNode(AVLNode* root, int data);
void displayAVL(AVLNode* root, int x, int y, int offset);


void heapify(int heap[], int size, int i);
void heapSort(int heap[], int size);
void displayHeap(int heap[], int size, int x, int y, int offset);


void initializeGraphics();
void clearScreen();
void autoDisplay(BSTNode* bstRoot, AVLNode* avlRoot, int heap[], int heapSize);

#endif

