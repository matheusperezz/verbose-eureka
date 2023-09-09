#include <iostream>
#include <vector>

using namespace std;

/*
    ::::: HEAP -> TREE BASED DATA STRUCTURE :::::

    -> Complete binary tree (all the levels are completely filled, except the possibly the deepest level)\
    -> One of two types (min heap, max heap)

    ::::: Min Heap :::::
    value(parent) <= value(child)

    ::::: Max Heap :::::
    value(parent) >= value(child)

*/

class MaxHeap
{
private:
    vector<int> heap;

    // Function to move a element to the top of heap, and readjust
    void heapifyUp(int index)
    {
        int parentIndex = (index - 1) / 2;
        while (index > 0 and heap[index] > heap[parentIndex])
        {
            swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    // Function to move a element to the bottom of heap, and readjust
    void heapifyDown(int index)
    {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() and heap[leftChild] > heap[largest])
        {
            largest = leftChild;
        }

        if (rightChild < heap.size() and heap[rightChild] > heap[largest])
        {
            largest = rightChild;
        }

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Function to insert a element in heap
    void insert(int value)
    {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifyUp(index);
    }

    // Function to remove and return the max element of heap
    int extractMax()
    {
        if (heap.empty())
        {
            throw runtime_error("Heap vazio");
        }

        int max = heap[0];
        heap[0] = heap.back(); // reference to the last item in vector
        heap.pop_back();
        heapifyDown(0);

        return max;
    }

    // Function to verify if heap is empty
    bool isEmpty() const
    {
        return heap.empty();
    }
};

int main()
{
    MaxHeap maxHeap;

    maxHeap.insert(12);
    maxHeap.insert(8);
    maxHeap.insert(15);
    maxHeap.insert(21);

    while (!maxHeap.isEmpty())
    {
        cout << maxHeap.extractMax() << " ";
    }

    cout << endl;

    return 0;
}