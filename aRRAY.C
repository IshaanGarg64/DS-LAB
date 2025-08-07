#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int arr[MAX_SIZE];
int size = 0;

void create() {
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size. Please enter a size between 1 and %d.\n", MAX_SIZE);
        size = 0;
        return;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully.\n");
}

void display() {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert() {
    int element, position;

    if (size == MAX_SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert (0 to %d): ", size);
    scanf("%d", &position);

    if (position < 0 || position > size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    printf("Element inserted successfully.\n");
}

void delete_element() {
    int position;

    if (size == 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }

    printf("Enter the position to delete (0 to %d): ", size - 1);
    scanf("%d", &position);

    if (position < 0 || position >= size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted successfully.\n");
}

int linear_search() {
    int element, i;

    if (size == 0) {
        printf("Array is empty. Cannot search.\n");
        return -1;
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// Bubble Sort implementation (added)
void bubble_sort() {
    if (size == 0) {
        printf("Array is empty. Cannot sort.\n");
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted using Bubble Sort.\n");
}

// Binary Search implementation (added)
int binary_search() {
    if (size == 0) {
        printf("Array is empty. Cannot search.\n");
        return -1;
    }

    int element;
    printf("Enter the element to search (array must be sorted): ");
    scanf("%d", &element);

    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == element)
            return mid;
        else if (arr[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int choice;

    do {
        printf("\n——MENU——\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. BUBBLE SORT\n");              // added menu option
        printf("7. BINARY SEARCH (Iterative)\n"); // added menu option
        printf("8. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                delete_element();
                break;
            case 5: {
                int result = linear_search();
                if (result != -1) {
                    printf("Element found at position: %d\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;
            }
            case 6:
                bubble_sort();
                break;
            case 7: {
                int result = binary_search();
                if (result != -1) {
                    printf("Element found at position: %d\n", result);
                } else {
                    printf("Element not found.\n");
                }
                break;
            }
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
