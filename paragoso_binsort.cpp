/* Eda Grace J. Paragoso
2021-1574 */

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void binSort(int arr[], int n)
{
    int max_val = *max_element(arr, arr + n);
    vector<int> bins(max_val + 1, 0);

    for (int i = 0; i < n; i++)
        bins[arr[i]]++;

    int i = 0;
    for (int j = 0; j <= max_val; j++) {
        while (bins[j] > 0) {
            arr[i++] = j;
            bins[j]--;
        }
    }
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
    binSort(arr, arrlength);
    auto end_algo = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < arrlength; i++)
        cout << arr[i] << " ";
    cout << endl;

    auto time_duration = chrono::duration_cast<chrono::duration<double>>(end_algo - start_algo);
    double time_taken = time_duration.count();

    cout << "Time taken by program is: " << time_taken;
    cout << " seconds" << endl;

    return 0;
}
