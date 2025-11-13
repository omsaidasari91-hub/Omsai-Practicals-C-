#include <stdio.h>

void bubbleSort(float arr[], int n);
void selectionSort(float arr[], int n);
void insertionSort(float arr[], int n);
void display(float arr[], int n);

int main() {
    float prices[100];
    int n, choice, i;

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter prices of products:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &prices[i]);
    }

    printf("\nChoose Sorting Method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            bubbleSort(prices, n);
            printf("\nPrices sorted using Bubble Sort:\n");
            break;
        case 2:
            selectionSort(prices, n);
            printf("\nPrices sorted using Selection Sort:\n");
            break;
        case 3:
            insertionSort(prices, n);
            printf("\nPrices sorted using Insertion Sort:\n");
            break;
        default:
            printf("Invalid choice!\n");
            return 0;
    }

    display(prices, n);
    return 0;
}

// Bubble Sort
void bubbleSort(float arr[], int n) {
    int i, j;
    float temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(float arr[], int n) {
    int i, j, minIndex;
    float temp;
    for(i = 0; i < n - 1; i++) {
        minIndex = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Insertion Sort
void insertionSort(float arr[], int n) {
    int i, j;
    float key;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Display function
void display(float arr[], int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%.2f  ", arr[i]);
    printf("\n");
}

//algo
1️⃣ Bubble Sort – Short Algorithm

Start

Read n and array elements

For i = 0 to n-1
  For j = 0 to n-i-2
   If arr[j] > arr[j+1], swap them

Print sorted array

End

2️⃣ Selection Sort – Short Algorithm

Start

Read n and array elements

For i = 0 to n-2
  Find smallest element in unsorted part
  Swap it with element at position i

Print sorted array

End

3️⃣ Insertion Sort – Short Algorithm

Start

Read n and array elements

For i = 1 to n-1
  Set key = arr[i]
  Shift elements greater than key right
  Insert key in correct position

Print sorted array

End
