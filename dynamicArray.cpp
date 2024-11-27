#include <iostream>

using namespace std;

int *extendArray(int *arr, int *rozmiar){
    cout << "Rozszerzam tablice; nowy rozmiar: " << (*rozmiar)*2 << endl;

    int *new_arr = new int[*rozmiar*2];

    for(int i = 0; i < *rozmiar; i++){
        new_arr[i] = arr[i];
    }

    *rozmiar *= 2;

    delete[] arr;

    return new_arr;
}

int main() {
    int rozmiar = 10;
    int *arr = new int[rozmiar];

    for(int i=0; i<100; i++){
        if(i >= rozmiar){
            arr = extendArray(arr, &rozmiar);
        }

        arr[i] = i;
    }

    for(int i=0; i<100; i++){
        cout << arr[i] << " ";
    }
}