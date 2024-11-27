#include <iostream>
#include <vector>

using namespace std;

void insertionSort(int *arr, int n) {
    // Początkowo zakładamy, że pierwszy element jest posortowany
    for (int i = 1; i < n; i++) {
        // Wybieramy następny element do wstawienia
        int key = arr[i];
        
        // Wstawiamy element w odpowiednie miejsce w posortowanej części tablicy
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            // Przesuwamy elementy większe od klucza o jeden indeks w prawo
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Wstawiamy klucz w odpowiednie miejsce
        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {5, 2, 8, 3, 1, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}