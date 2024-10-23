// 1123542_Levinson
#include <iostream>
#include <queue>
using namespace std;

void printFirstNegativeInteger(int arr[], int n, int k) {
    // Create a queue to store indexes of negative numbers
    queue<int> negatives;

    // Process the first window of size k
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            negatives.push(i); // Store index of negative number
        }
    }

    // Process the rest of the windows
    for (int i = 0; i <= n - k; i++) {
        // If there's a negative number in the current window
        if (!negatives.empty()) {
            cout << arr[negatives.front()] << " ";
        } else {
            cout << "0 ";
        }

        // Remove elements that are out of this window
        if (!negatives.empty() && negatives.front() == i) {
            negatives.pop(); // Remove the index from queue
        }

        // Add the next element in the window to the queue if it's negative
        if (i + k < n && arr[i + k] < 0) {
            negatives.push(i + k); // Add index of new negative number
        }
    }
}

int main() {
    int arr[] = {-8, 2, 3, -6, 10};
    int k = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printFirstNegativeInteger(arr, n, k);
    
    return 0;
}
