// 1123542_Levinson
#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int>& st, int element) {
    if (st.empty()) {
        st.push(element);
    } else {
        int topElement = st.top();
        st.pop();
        insertAtBottom(st, element);
        st.push(topElement);
    }
}

// Function to reverse the stack
void reverseStack(stack<int>& st) {
    if (!st.empty()) {
        int topElement = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, topElement);
    }
}

// Function to print the stack (for testing)
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;

    // Pushing elements onto the stack
    st.push(28);
    st.push(29);
    st.push(30);
    st.push(31);

    cout << "Original Stack (Top to Bottom): ";
    printStack(st);

    // Reversing the stack
    reverseStack(st);

    cout << "Reversed Stack (Top to Bottom): ";
    printStack(st);

    return 0;
}