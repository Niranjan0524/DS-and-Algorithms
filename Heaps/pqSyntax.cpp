#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. int max heap (default)
    priority_queue<int> pq1;

    // 2. int min heap
    priority_queue<int, vector<int>, greater<int>> pq2;

    // 3. pair max heap (default: compares by first, then second)
    priority_queue<pair<int,int>> pq3;

    // 4. pair min heap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq4;

    // 5. pair custom comparator: sort by second ascending, tie-break by first descending
   priority_queue<
          pair<int,int>,
          vector<pair<int,int>>,
          function<bool(const pair<int,int>&, const pair<int,int>&)>
      > pq5([](const pair<int,int>& a, const pair<int,int>& b) {
          if (a.second == b.second) return a.first < b.first;
          return a.second > b.second;
      });


    // 6. vector<int> max heap (lexicographical)
    priority_queue<vector<int>> pq6;

    // 7. vector<int> min heap (lexicographical)
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq7;

    // 8. vector<int> custom comparator: sort by sum ascending
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        function<bool(const vector<int>&, const vector<int>&)>
    > pq8([](const vector<int>& a, const vector<int>& b) {
        int suma = accumulate(a.begin(), a.end(), 0);
        int sumb = accumulate(b.begin(), b.end(), 0);
        return suma > sumb; 
    });



    // Example pushes
    pq1.push(5); pq1.push(1); pq1.push(10);
    pq2.push(5); pq2.push(1); pq2.push(10);
    pq3.push({1, 5}); pq3.push({2, 2});
    pq4.push({1, 5}); pq4.push({2, 2});
    pq5.push({1, 5}); pq5.push({2, 2}); pq5.push({3, 5});
    pq6.push({1, 2, 3}); pq6.push({2, 3});
    pq7.push({1, 2, 3}); pq7.push({2, 3});
    pq8.push({1, 2, 3}); pq8.push({4, 0});

    // Example pops (showing top element)
    cout << "pq1 top: " << pq1.top() << "\n";
    cout << "pq2 top: " << pq2.top() << "\n";
    cout << "pq3 top: (" << pq3.top().first << "," << pq3.top().second << ")\n";
    cout << "pq4 top: (" << pq4.top().first << "," << pq4.top().second << ")\n";
    cout << "pq5 top: (" << pq5.top().first << "," << pq5.top().second << ")\n";
    cout << "pq6 top size: " << pq6.top().size() << "\n";
    cout << "pq7 top size: " << pq7.top().size() << "\n";
    cout << "pq8 top sum: " << accumulate(pq8.top().begin(), pq8.top().end(), 0) << "\n";

    return 0;
}

// | Operation | Complexity   |
// | --------- | ------------ |
// | `push()`  | **O(log n)** |
// | `pop()`   | **O(log n)** |
// | `top()`   | **O(1)**     |
// | `size()`  | **O(1)**     |
// | `empty()` | **O(1)**     |

