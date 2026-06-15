#include <iostream>
using namespace std;

int countPlatforms(int n, int arr[], int dep[]) {
    // Sort arrival and departure times
    sort(arr, arr + n);
    sort(dep, dep + n);
    int platforms = 1;      // Current platforms occupied
    int maxPlatforms = 1;   // Answer
    int i = 1; // Next arrival
    int j = 0; // Next departure

    while (i < n && j < n) {
        // New train arrives before or at the same time
        // as the earliest departing train
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            // A train departs, freeing a platform
            platforms--;
            j++;
        }
        maxPlatforms = max(maxPlatforms, platforms);
    }
    return maxPlatforms;
}

int main() {

    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Platforms Required = " << countPlatforms(n, arr, dep) << endl;

    return 0;
}