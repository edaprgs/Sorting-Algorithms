/* Eda Grace J. Paragoso
2021-1574 */

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void countingSort(int A[], int B[], int n, int k) {
    int C[k+1];
    for(int i=0; i<=k; i++) {
        C[i] = 0;
    }
    for(int j=0; j<n; j++) {
        C[A[j]]++;
    }
    for(int i=1; i<=k; i++) {
        C[i] += C[i-1];
    }
    for(int j=n-1; j>=0; j--) {
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    const int arrlength = 10;
    const int maxValueofElem = 10;
    int arrA[arrlength], arrB[arrlength];

    // sets the seed for the random number generator using the current time
    srand(time(NULL));

    for(int i = 0; i < arrlength; i++) {
        arrA[i] = rand() % (maxValueofElem + 1);
        cout << arrA[i] << " ";
    } cout << endl;

    // to get the running time of counting sort algorithm
    auto start_algo = chrono::high_resolution_clock::now();
    countingSort(arrA, arrB, arrlength, maxValueofElem);
    auto end_algo = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    for(int i = 0; i < arrlength; i++) {
        cout << arrB[i] << " ";
    }
    cout << endl;

    auto time_duration = chrono::duration_cast<chrono::duration<double>>(end_algo - start_algo);
    double time_taken = time_duration.count();

    cout << "Time taken by program is: " << time_taken;
    cout << " seconds" << endl;

    return 0;
}

