/* 1) Develop a Menudriven program to demonstrate the following operations of Arrays
——MENU——-
1.CREATE
2.DISPLAY
3.INSERT
4.DELETE
5.LINEAR SEARCH
6.EXIT */

#include <iostream>
using namespace std;
#define MAX 100   // Maximum size of the array
int arr[MAX];    // Array declaration
int n = 0;       // Current number of elements in the array
void createArray() {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX) {
        cout << "Size exceeds maximum limit (" << MAX << "). Try again.\n";
        n = 0;
        return;
    }
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    } 
    cout << "Array created successfully!\n";
}
// Function to display array
void displayArray() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Function to insert element
void insertElement() {
    if (n == MAX) {
        cout << "Array is full! Cannot insert.\n";
        return;
    }

    int pos, value;
    cout << "Enter position (1 to " << n+1 << "): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;

    if (pos < 1 || pos > n+1) {
        cout << "Invalid position!\n";
        return;
    }

    // Shift elements to right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    } 

    arr[pos - 1] = value;
    n++;

    cout << "Element inserted successfully!\n";
}

// Function to delete element
void deleteElement() {
    if (n == 0) {
        cout << "Array is empty! Cannot delete.\n";
        return;
    }

    int pos;
    cout << "Enter position (1 to " << n << ") to delete: ";
    cin >> pos;

    if (pos < 1 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }

    // Shift elements to left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    cout << "Element deleted successfully!\n";
}

// Function for Linear Search
void linearSearch() {
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }

    int key, found = -1;
    cout << "Enter value to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }

    if (found != -1)
        cout << "Element " << key << " found at position " << found + 1 << ".\n";
    else
        cout << "Element not found!\n";
}
int main() {
    int choice;
    do {
        cout << "\n——— MENU ———\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);
    return 0;
}


