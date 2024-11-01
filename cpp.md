# cpp notes

## priority queue

- use when you only care about max or min at any step in the algorithm (the rest of the list doesn't need to be sorted), and repeating the operation on the same set

- example
```cpp
#include <queue>
#include <vector>

int main() {
    // Create a min-heap priority queue
     std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Insert elements into the priority queue
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Retrieve and remove the min element
    while (!pq.empty()) {
        std::cout << "Popped min element: " << pq.top() << std::endl;
        pq.pop();
    }

    return 0;
}
```

## CPP TILs
- you can swap two items in vector with std::swap from algorithm
```cpp
void swapItems(vector<int>& nums, int index1, int index2) {
    // Swap the elements at index1 and index2
    std::swap(nums[index1], nums[index2]);
}
```