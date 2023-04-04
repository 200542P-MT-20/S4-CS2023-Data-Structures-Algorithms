#include <iostream>
#include <chrono>
#define MAX_SIZE 100

using namespace std;
using namespace std::chrono;


int arr[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if (top == MAX_SIZE)
    {
        cout << "Overflowed Stack";
    }
    else
    {
        top = top + 1;
        arr[top] = x;

    }
}
void Pop()
{
    if (top == -1)
    {
        cout << "Empty Stack";
        return;
    }
    else
    {
        top = top - 1;
    }
}

int main()
{
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
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration <double> duration = end - start;
    cout << "Execution time: " << duration.count() << " seconds\n";




}

