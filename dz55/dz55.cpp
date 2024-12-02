#include <iostream>
using namespace std;
//Завдання 2 
//int* createArray(int size) {
//    return new int[size];
//}
//
//void initializeArray(int* arr, int size) {
//    for (int i = 0; i < size; i++) {
//        cout << "Enter value for element " << i << ": ";
//        cin >> arr[i];
//    }
//}
//
//void printArray(int* arr, int size) {
//    for (int i = 0; i < size; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//void deleteArray(int* arr) {
//    delete[] arr;
//}
//
//int main() {
//    int size = 5;
//    int* arr = createArray(size);
//
//    initializeArray(arr, size);
//
//    cout << "Array: ";
//    printArray(arr, size);
//
//    deleteArray(arr);
//}
//Завдання 4 
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int& size) {
    int newSize = 0;

    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newSize++;
        }
    }

    int* newArr = new int[newSize];
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[j++] = arr[i];
        }
    }

    size = newSize;
    delete[] arr;

    return newArr;
}

int main() {
    int size = 6;
    int* arr = new int[size] {2, 3, 4, 5, 6, 7};

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = removePrimes(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
}
