#include <bits/stdc++.h>
using namespace std;

// Custom comparator function example
bool cmpPairSecondThenFirst(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

// Struct comparator example
struct Item {
    int id;
    string name;
    double price;
};
bool cmpItemPrice(const Item &a, const Item &b) {
    return a.price < b.price; // ascending
}

int main() {
    // 1. Sorting a vector<int>
    vector<int> v = {5, 2, 8, 1};
    sort(v.begin(), v.end());                     // Ascending
    sort(v.begin(), v.end(), greater<int>());     // Descending

    // 2. Sorting an array
    int arr[] = {5, 3, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);                           // Ascending
    sort(arr, arr + n, greater<int>());           // Descending

    // 3. Sorting a vector<pair<int,int>>
    vector<pair<int,int>> vp = {{1, 3}, {2, 2}, {1, 2}};
    sort(vp.begin(), vp.end()); // Default: first, then second ascending
    sort(vp.begin(), vp.end(), cmpPairSecondThenFirst); // Custom

    // 4. Sorting a vector<vector<int>>
    vector<vector<int>> vv = {{1, 5}, {1, 2}, {0, 8}};
    sort(vv.begin(), vv.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });

    // 5. Sorting a vector of structs
    vector<Item> items = {{1, "Pen", 5.5}, {2, "Book", 12.0}, {3, "Eraser", 2.0}};
    sort(items.begin(), items.end(), cmpItemPrice);

    // 6. Lambda custom sort for structs
    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.name < b.name; // sort by name ascending
    });

    // 7. Stable sort (preserves order of equal elements)
    stable_sort(v.begin(), v.end());

    // 8. Partial sort (first k elements sorted)
    int k = 2;
    partial_sort(v.begin(), v.begin() + k, v.end());

    // 9. Using priority_queue (heap sort style)
    priority_queue<int> maxHeap; // max heap
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap

    priority_queue<
        pair<int,int>, 
        vector<pair<int,int>>, 
        function<bool(const pair<int,int>&, const pair<int,int>&)>
    > pq(
        [](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first)
                return a.second > b.second;   // ascending by second
            return a.first < b.first;         // descending by first
        }
    );

    // 10. Using set / multiset (always sorted)
    set<int> s = {3, 1, 4}; // unique & sorted
    multiset<int> ms = {3, 1, 4, 1}; // allows duplicates & sorted

    return 0;
}
