/* Eda Grace J. Paragoso
2021-1574 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isSorted(int arr[], int arrlength) {
	for(int i = 0; i < arrlength - 1; i++)
	{
        if(arr[i] > arr[i+1]) {
            return false;
        }
	}
	// returns true if the elements of the array are in ascending order
	return true;
}

void slowSort(int arr[], int arrlength, int& swaps) {
    // represents the maximum number of swaps allowed before the algorithm terminates to prevent an infinite loop
    const int MAX_SWAPS = arrlength * arrlength;
    // to keep track of the number of swaps made during the sorting process
    int swapCount = 0;

    // a loop that continues until the array is sorted
    while(!isSorted(arr, arrlength)) {
        int i = rand() % arrlength;
        int j = rand() % arrlength;

        if(i < j && arr[i] > arr[j]) {
            swap(arr[i], arr[j]);
            swapCount++;
        }
    }
    swaps = swapCount;
}

int main() {
    const int arrlength = 10;
    int arr[arrlength];
    int swaps = 0;

    clock_t start_t, end_t;
    double total_t;
    srand(time(0));

    // to generate random unsorted numbers in an array
    for(int i = 0; i < arrlength; i++) {
        arr[i] = rand () % arrlength;
        cout << arr[i] << " ";
    }
    cout << endl;

    start_t = clock();

    // to sort array using Slow Sort
    slowSort(arr, arrlength,swaps);

    end_t = clock();

    // to display the sorted array
    for(int i = 0; i < arrlength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // the total time it takes to run the slow sort algorithm
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    cout << "\nTime Required: " << total_t << " seconds" << endl;
    cout << "Number of swaps: " << swaps << endl;

    return 0;
}
