//#include "library.h"
//#include <iostream>
//#include <graphics.h>
//
//using namespace std;
//
//int main() {
//    // Initialize graphics
//    initializeGraphics();
//
//    // Initialize the structures
//    BSTNode* bstRoot = nullptr;
//    AVLNode* avlRoot = nullptr;
//    int heap[100];
//    int heapSize = 0;
//
//    int choice;
//    do {
//        cout << "\nSelect the data structure to insert into:\n";
//        cout << "1. Binary Search Tree (BST)\n";
//        cout << "2. AVL Tree\n";
//        cout << "3. Heap\n";
//        cout << "4. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//            case 1: { // Insert into BST
//                int data;
//                cout << "Enter value to insert into BST: ";
//                cin >> data;
//                bstRoot = insertBSTNode(bstRoot, data);
//                break;
//            }
//            case 2: { // Insert into AVL Tree
//                int data;
//                cout << "Enter value to insert into AVL Tree: ";
//                cin >> data;
//                avlRoot = insertAVLNode(avlRoot, data);
//                break;
//            }
//            case 3: { // Insert into Heap
//                if (heapSize >= 100) {
//                    cout << "Heap is full. Cannot insert more elements.\n";
//                } else {
//                    int data;
//                    cout << "Enter value to insert into Heap: ";
//                    cin >> data;
//                    heap[heapSize++] = data;
//                    // Ensure the heap property is maintained
//                    heapSort(heap, heapSize);
//                }
//                break;
//            }
//            case 4:
//                cout << "Exiting program. Goodbye!\n";
//                break;
//            default:
//                cout << "Invalid choice. Please try again.\n";
//        }
//
//        // Auto-display after every operation
//        if (choice >= 1 && choice <= 3) {
//            clearScreen();
//            autoDisplay(bstRoot, avlRoot, heap, heapSize);
//        }
//    } while (choice != 4);
//
//    // Close the graphics window
//    closegraph();
//    return 0;
//}
#include "library.h"
#include <iostream>
#include <graphics.h>

using namespace std;

int main() {
    
    initializeGraphics();

    BSTNode* bstRoot = nullptr;
    AVLNode* avlRoot = nullptr;
    int heap[100];
    int heapSize = 0;

    int choice;
    do {
        cout << "\nSelect the data structure to insert into:\n";
        cout << "1. Binary Search Tree (BST)\n";
        cout << "2. AVL Tree\n";
        cout << "3. Heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter value to insert into BST: ";
                cin >> data;
                bstRoot = insertBSTNode(bstRoot, data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter value to insert into AVL Tree: ";
                cin >> data;
                avlRoot = insertAVLNode(avlRoot, data);
                break;
            }
            case 3: {
                if (heapSize >= 100) {
                    cout << "Heap is full. Cannot insert more elements.\n";
                } else {
                    int data;
                    cout << "Enter value to insert into Heap: ";
                    cin >> data;
                    heap[heapSize++] = data;
 
                    heapSort(heap, heapSize);
                }
                break;
            }
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }


        if (choice >= 1 && choice <= 3) {
            clearScreen();
          
            autoDisplay(bstRoot, avlRoot, heap, heapSize); 
        }
    } while (choice != 4);


    closegraph();
    return 0;
}
