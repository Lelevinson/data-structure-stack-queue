#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    int half = n / 2;
    
    queue<int> firstHalf;
    queue<int> secondHalf;

    // Step 1: Dequeue the first half into firstHalf queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();  // Remove the front element from the original queue
    }

    // Step 2: Dequeue the second half into secondHalf queue
    for (int i = 0; i < half; i++) {
        secondHalf.push(q.front());
        q.pop();
    }

    // Step 3: Interleave the two halves back into the original queue
    while (!firstHalf.empty() || !secondHalf.empty()) {
        if (!firstHalf.empty()) {
            q.push(firstHalf.front()); // Push from first half
            firstHalf.pop();           // Remove the front element from first half
        }
        if (!secondHalf.empty()) {
            q.push(secondHalf.front()); // Push from second half
            secondHalf.pop();           // Remove the front element from second half
        }
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";  // Print the front element
        q.pop();                   // Remove the front element
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Example input
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Original Queue: ";
    printQueue(q);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    printQueue(q);

    return 0;
}
