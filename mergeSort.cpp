#include <iostream>
#include <vector>

using namespace std;

// Funkcja merge łącząca dwie posortowane tablice w jedną posortowaną tablicę
void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Tworzymy dwie tymczasowe tablice
    int leftArr[n1];
    int rightArr[n2];
    
    // Kopiujemy dane do tymczasowych tablic
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // Łączymy dwie posortowane tablice w jedną posortowaną tablicę
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Kopiujemy pozostałe elementy z lewej tablicy
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Kopiujemy pozostałe elementy z prawej tablicy
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Funkcja mergeSort rekurencyjnie dzieląca tablicę na mniejsze części i łącząca je w posortowaną tablicę
void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Dzielimy tablicę na dwie mniejsze części
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Łączymy dwie posortowane części w jedną posortowaną tablicę
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {5, 2, 8, 3, 1, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}