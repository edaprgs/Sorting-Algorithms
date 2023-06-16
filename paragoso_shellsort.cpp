/* Eda Grace J. Paragoso
2021-1574 */

#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

// Shell sort
void shellSort(int arr[], int arrlength) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for(int interval = arrlength / 2; interval > 0; interval /= 2) {
    for(int i = interval; i < arrlength; i += 1) {
      int temp = arr[i];
      int j;
      for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
        arr[j] = arr[j - interval];
      }
      arr[j] = temp;
    }
  }
}

// Print an array
void printArray(int arr[], int arrlength) {
  for(int i = 0; i < arrlength; i++)
    cout << arr[i] << " ";
    cout << endl;
}

int main() {
    const int arrlength = 10000;
    int arr[arrlength];

    for(int i = 0; i < arrlength; i++) {
        arr[i] = rand() % arrlength;
        cout << arr[i] << " ";
    } cout << endl;

    // to get the running time of shell sort algorithm
    auto start_algo = chrono::high_resolution_clock::now();
    shellSort(arr,arrlength);
    auto end_algo = chrono::high_resolution_clock::now();

    printArray(arr, arrlength);

    // Calculating total time taken by the algorithm
    double time_taken = chrono::duration_cast<chrono::milliseconds>(end_algo - start_algo).count();

    time_taken *= 1e-3;

    cout << "Time taken by program is: " << fixed << time_taken << setprecision(9);
    cout << " milliseconds" << endl;

    return 0;
}
