#include <stdio.h>

// Funkcja zamieniająca dwa elementy w tablicy
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funkcja partition dzieląca tablicę na dwie części wokół pivotu
int partition(int arr[], int left, int right) {
    int pivot = arr[right]; // Wybieramy pivot jako ostatni element tablicy
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

// Funkcja quickSort rekurencyjnie sortująca tablicę
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        
        // Rekurencyjnie sortujemy lewą i prawą część tablicy
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main() {
    int arr[] = {5, 2, 8, 3, 1, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}