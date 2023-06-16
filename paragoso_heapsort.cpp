/* Eda Grace J. Paragoso
2021-1574 */

#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);

    // Heapify root element to get highest element at root again
    heapify(arr, i, 0);
    }
}

// Print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    const int arrlength = 10000;
    int arr[arrlength];

    for(int i = 0; i < arrlength; i++) {
        arr[i] = rand() % arrlength;
        //cout << arr[i] << " ";
    } cout << endl;

    // to get the running time of heap sort algorithm
    auto start_algo = chrono::high_resolution_clock::now();
    heapSort(arr, arrlength);
    auto end_algo = chrono::high_resolution_clock::now();

    //printArray(arr, arrlength);

    // Calculating total time taken by the algorithm
    double time_taken = chrono::duration_cast<chrono::milliseconds>(end_algo - start_algo).count();

    time_taken *= 1e-3;
    //cout << "Time taken by program is : " << fixed  << time_taken << setprecision(9);

    cout << "Time taken by program is: " << fixed << time_taken << setprecision(9);
    cout << " milliseconds" << endl;

    return 0;
}
