// 1123542_Levinson
#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[], int n) {
    stack<int> s;

    int nge[n];  // Array to store the NGE for each element

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from stack while stack is not empty and top of stack is smaller than the current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // If stack becomes empty, there is no greater element to the right
        if (s.empty()) {
            nge[i] = -1;
        } else {
            // The top of the stack is the NGE for the current element
            nge[i] = s.top();
        }

        // Push this element into the stack for future elements
        s.push(arr[i]);
    }

    // Print the Next Greater Element for each element in the array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printNGE(arr, n);

    return 0;
}