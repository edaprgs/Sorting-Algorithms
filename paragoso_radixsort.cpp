/* Eda Grace J. Paragoso
2021-1574 */

#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to get the maximum element from an array
int getMax(int arr[], int n) {
    int maxElem = arr[0];
      for (int i = 1; i < n; i++)
        if (arr[i] > maxElem)
          maxElem = arr[i];
      return maxElem;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int arr[], int n, int place) {
    const int maxnum = 10;
    int output[n];
    int count[maxnum];

    for (int i = 0; i < maxnum; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < n; i++)
        count[(arr[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < maxnum; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int arr[], int n) {
    // Get maximum element
    int maxNum = getMax(arr, n);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; maxNum / place > 0; place *= 10)
        countingSort(arr, n, place);
}

void printArray(int arrA[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << arrA[i] << " ";
    cout << endl;
}

int main() {
    const int arrlength = 10;
    int arr[arrlength];

    // sets the seed for the random number generator using the current time
    srand(time(NULL));

    for(int i = 0; i < arrlength; i++) {
        arr[i] = rand() % arrlength;
        cout << arr[i] << " ";
    } cout << endl;

    auto start_algo = chrono::high_resolution_clock::now();
    radixsort(arr, arrlength);
    auto end_algo = chrono::high_resolution_clock::now();

    printArray(arr, arrlength);

    auto time_duration = chrono::duration_cast<chrono::duration<double>>(end_algo - start_algo);
    double time_taken = time_duration.count();

    cout << "Time taken by program is: " << time_taken;
    cout << " seconds" << endl;

    return 0;
}
