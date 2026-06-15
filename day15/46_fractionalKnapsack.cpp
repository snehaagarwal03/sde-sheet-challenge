#include <iostream>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:

    static bool comp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, comp);
        double totalValue = 0.0;

        for(int i = 0; i < n; i++) {
            // Take whole item
            if(arr[i].weight <= W) {
                totalValue += arr[i].value;
                W -= arr[i].weight;
            }
            // Take fraction of item
            else {
                totalValue += ((double)arr[i].value / arr[i].weight) * W;
                break;
            }
        }
        return totalValue;
    }
};

int main() {

    Item arr[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int W = 50;
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    cout << "Maximum value = " << obj.fractionalKnapsack(W, arr, n) << endl;
    return 0;
}