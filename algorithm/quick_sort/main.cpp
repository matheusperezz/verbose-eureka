//
// Created by Matheus on 19/01/2025.
//
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int left_wall = low - 1;

    for (int i = low; i < high; i++) {
        if (arr[i] <= pivot) {
            left_wall += 1;
            swap(arr[left_wall], arr[i]);
        }
    }
    swap(arr[left_wall+1], arr[high]);
    return left_wall + 1;
}

void quick_sort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot_location = partition(arr, low, high);
        quick_sort(arr, low, pivot_location - 1);
        quick_sort(arr, pivot_location + 1, high);
    }
}

int main() {
    cout << "testing" << endl;
    vector<int> arr;
    arr.push_back(9);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(12);
    arr.push_back(2);
    int high = arr.size() - 1;
    quick_sort(arr, 0, high);

    for (auto a: arr) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}