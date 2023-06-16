/* Eda Grace J. Paragoso
2021-1574 */

#include <iostream>
#include <chrono>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

int findMax(int arr[], int n)
{
    int i, maxNum = INT_MIN, cnt = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] > maxNum)
            maxNum = arr[i];
    }
    while(maxNum > 0)
    {
        cnt++;
        maxNum = maxNum / 10;
    }

    return cnt;
}

void bucketSort(int arr[],int *bucket[],int n)
{
    static int j[10],k,l,d=1;
    int c;
    c=findMax(arr,n);

    for(int m=0;m<c;m++)
    {
        for(int i=0;i<10;i++)
            j[i]=0;
        for(int i=0;i<n;i++)
        {
            k=(arr[i]/d)%10;
            bucket[k][j[k]]=arr[i];
            j[k]++;
        }

        l=0;
        for(int i=0;i<10;i++)
        {
            for(k=0;k<j[i];k++)
            {
                arr[l]=bucket[i][k];
                l++;
            }
        }
        d*=10;
    }
}

int main()
{
    const int arrlength = 10;
    int *arr = new int[arrlength];
    int *bucket[10] = {nullptr};
    int i;

    // sets the seed for the random number generator using the current time
    srand(time(NULL));

    for(int i = 0; i < arrlength; i++) {
        arr[i] = rand() % arrlength;
        cout << arr[i] << " ";
    } cout << endl;

    for(i = 0; i < 10; i++) {
        bucket[i] = new int[arrlength];
    }

    auto start_algo = chrono::high_resolution_clock::now();
    bucketSort(arr,bucket,arrlength);
    auto end_algo = chrono::high_resolution_clock::now();

    cout << "Sorted array is \n";
    for (int i = 0; i < arrlength; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto time_duration = chrono::duration_cast<chrono::duration<double>>(end_algo - start_algo);
    double time_taken = time_duration.count();

    cout << "Time taken by program is: " << time_taken;
    cout << " seconds" << endl;

    // Freeing the memory
    delete[] arr;
    for(i = 0; i < 10; i++) {
        delete[] bucket[i];
    }

    return 0;
}

