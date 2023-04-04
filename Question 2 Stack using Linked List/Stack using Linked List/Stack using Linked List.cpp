#include <iostream>
#include <chrono>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = nullptr; // Initially stack is empty

void Push(int value) 
{
    Node* temp = new Node();
    temp->data = value;
    temp->next = top;
    top = temp;
}

void Pop() {
    if (top == nullptr) 
    {
        cout << "Error: Stack underflow\n";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}




int main() {
    // Start measuring execution time
    auto start = chrono::high_resolution_clock::now();

    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Push(4);
    Push(30);
    Push(3);
    Push(1);

    // End measuring execution time and print the duration in microseconds
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Execution time: " << duration.count() << " microseconds\n";

    return 0;
}
