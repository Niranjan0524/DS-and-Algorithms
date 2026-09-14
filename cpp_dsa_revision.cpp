#include <bits/stdc++.h>
using namespace std;

// ============================================================
// C++ DSA / STL — LAST-MINUTE OA + SDE REVISION
// C++17 | syntax refresher, not a tutorial
// ============================================================

// ============================================================
// VECTOR                                          MOST IMPORTANT
// ============================================================
//
// Declaration
//   vector<int> v;
//   vector<int> v(n);              // n zeros
//   vector<int> v(n, val);         // n copies of val
//   vector<int> v = {1, 2, 3};
//   vector<vector<int>> g(n);      // adj list / 2D
//   vector<vector<int>> mat(r, vector<int>(c, 0));
//
// Add                                          MOST IMPORTANT
//   v.push_back(x);                // O(1) amortized
//   v.emplace_back(x);             // constructs in place
//   v.insert(v.begin() + i, x);    // O(n)
//
// Access                                       MOST IMPORTANT
//   v[i];  v.front();  v.back();
//   v.at(i);                       // bounds-checked (rarely used)
//
// Remove
//   v.pop_back();                  // O(1)
//   v.erase(v.begin() + i);        // O(n)
//   v.erase(v.begin() + l, v.begin() + r); // [l, r)
//   v.clear();
//
// Size / empty
//   v.size();  v.empty();  v.resize(n);
//
// Iterate
//   for (int x : v) {}
//   for (int i = 0; i < (int)v.size(); i++) {}
//   for (auto it = v.begin(); it != v.end(); ++it) {}
//
// Sort / reverse                               MOST IMPORTANT
//   sort(v.begin(), v.end());                  // asc
//   sort(v.rbegin(), v.rend());                // desc
//   sort(v.begin(), v.end(), greater<int>());  // desc
//   reverse(v.begin(), v.end());
//
// Custom sort
//   sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
//
// Find (unsorted)
//   find(v.begin(), v.end(), x);   // iterator, or v.end()
//   count(v.begin(), v.end(), x);  // O(n)
//
// Complexity
//   access / front / back     O(1)
//   push_back / pop_back      O(1) amortized / O(1)
//   insert / erase middle     O(n)
//   search (unsorted)         O(n)
//
// OA use: arrays, DP, adj list, prefix, sliding window

// ============================================================
// STRING                                          MOST IMPORTANT
// ============================================================
//
// Declaration
//   string s, t = "abc";
//   string s(n, 'a');              // n copies of 'a'
//
// Access / size
//   s[i];  s.size();  s.empty();  s.front();  s.back();
//
// Modify
//   s += 'a';  s += t;  s.push_back('a');  s.pop_back();
//   s.append(t);
//   s.insert(i, t);                // insert t at index i
//   s.erase(i, len);               // erase len chars from i
//   s.clear();
//
// Substring / find                             MOST IMPORTANT
//   s.substr(i, len);              // from i, length len  O(len)
//   s.substr(i);                   // from i to end
//   s.find(t);                     // first index, or string::npos
//   s.rfind(t);                    // last occurrence
//   if (s.find(t) != string::npos) {}
//
// Compare / convert                            MOST IMPORTANT
//   s == t;  s < t;                // lexicographic
//   stoi(s);  stoll(s);            // string -> int / long long
//   to_string(x);                  // int -> string
//
// Sort unique chars
//   sort(s.begin(), s.end());
//   reverse(s.begin(), s.end());
//
// Split by space (OA)
//   stringstream ss(s);
//   string word;
//   while (ss >> word) {}
//
// Complexity
//   access                    O(1)
//   += / push_back            O(1) amortized
//   substr / insert / erase   O(n)
//   find                      O(n * m)
//
// OA use: palindrome, anagram (sort / freq[26]), substr, parse nums

// ============================================================
// ARRAY  (std::array — fixed size, stack)
// ============================================================
//
//   array<int, 5> a = {1, 2, 3, 4, 5};
//   a[i];  a.size();  a.front();  a.back();
//   sort(a.begin(), a.end());
//
// Prefer C-array / vector in OAs:
//   int a[n];                      // VLA: GCC only
//   int a[100005];
//
// Complexity: same as vector for access O(1). No push_back.

// ============================================================
// PAIR                                            MOST IMPORTANT
// ============================================================
//
//   pair<int, int> p = {1, 2};
//   pair<int, int> p = make_pair(1, 2);
//   p.first;  p.second;
//
//   vector<pair<int, int>> vp;
//   vp.push_back({u, v});
//
// Compare: first, then second (lexicographic)
//   sort(vp.begin(), vp.end());    // by first, then second
//
// Structured binding (C++17)
//   auto [x, y] = p;
//   for (auto [u, v] : vp) {}
//
// Swap
//   swap(p.first, p.second);
//
// OA use: (node, dist), (value, index), intervals {l, r}

// ============================================================
// STACK                                           MOST IMPORTANT
// ============================================================
//
//   stack<int> st;
//   st.push(x);                    // O(1)
//   st.top();                      // O(1)  peek — MUST not empty
//   st.pop();                      // O(1)  no return value
//   st.size();  st.empty();
//
// Pattern
//   while (!st.empty()) { int x = st.top(); st.pop(); }
//
// Complexity: all O(1)
// OA use: NGE / NSE, valid parentheses, monotonic stack, DFS iterative

// ============================================================
// QUEUE
// ============================================================
//
//   queue<int> q;
//   q.push(x);                     // O(1)
//   q.front();  q.back();          // O(1)
//   q.pop();                       // O(1)  no return value
//   q.size();  q.empty();
//
// Complexity: all O(1)
// OA use: BFS, sliding window (rarely; deque better), level order

// ============================================================
// DEQUE
// ============================================================
//
//   deque<int> dq;
//   dq.push_back(x);  dq.push_front(x);
//   dq.pop_back();    dq.pop_front();
//   dq.front();  dq.back();  dq[i];  // random access O(1)
//   dq.size();  dq.empty();
//
// Complexity
//   push/pop front or back    O(1)
//   access dq[i]              O(1)
//   insert / erase middle     O(n)
//
// OA use: 0-1 BFS, sliding window maximum (monotonic deque)

// ============================================================
// PRIORITY_QUEUE / HEAP                           MOST IMPORTANT
// ============================================================
//
// Max heap (default)
//   priority_queue<int> mx;
//
// Min heap                                        MOST IMPORTANT
//   priority_queue<int, vector<int>, greater<int>> mn;
//
// Pair: compares first, then second
//   priority_queue<pair<int, int>> mxp;            // max by first
//   priority_queue<pair<int, int>,
//                  vector<pair<int, int>>,
//                  greater<pair<int, int>>> mnp;   // min by first
//
// Ops
//   pq.push(x);                    // O(log n)
//   pq.top();                      // O(1)
//   pq.pop();                      // O(log n)
//   pq.size();  pq.empty();
//   // NO decrease-key / erase-arbitrary  → lazy delete: skip stale top
//
// Custom comparator (min by second)
//   auto cmp = [](auto& a, auto& b) { return a.second > b.second; };
//   priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
//
// Complexity
//   top                       O(1)
//   push / pop                O(log n)
//
// OA use: Dijkstra, Kth largest, merge K lists, Huffman, greedy

// ============================================================
// SET  (ordered unique, RB-tree)                  MOST IMPORTANT
// ============================================================
//
//   set<int> s;
//   s.insert(x);                   // O(log n)  ignore if duplicate
//   s.erase(x);                    // O(log n)  by value
//   s.erase(it);                   // O(1) amortized by iterator
//   s.find(x);                     // iterator or s.end()   O(log n)
//   s.count(x);                    // 0 or 1
//   s.lower_bound(x);  s.upper_bound(x);
//   s.begin();  s.rbegin();        // min / max
//   *s.begin();  *s.rbegin();
//   s.size();  s.empty();  s.clear();
//
// Iterate (sorted asc)
//   for (int x : s) {}
//
// Complexity
//   insert / erase / find     O(log n)
//   min / max                 O(1) via begin / rbegin
//
// OA use: ordered unique, closest value, online sorted set

// ============================================================
// MULTISET  (ordered, duplicates allowed)
// ============================================================
//
//   multiset<int> ms;
//   ms.insert(x);                  // always inserts
//   ms.find(x);                    // one occurrence
//   ms.erase(x);                   // ERASES ALL x          !!
//   ms.erase(ms.find(x));          // erase ONE x           MOST IMPORTANT
//   ms.count(x);                   // O(log n + k)
//   ms.lower_bound(x);
//
// Complexity: insert / erase one O(log n)
// OA use: median of window, keep sorted bag, greedy with duplicates

// ============================================================
// UNORDERED_SET  (hash, unique)
// ============================================================
//
//   unordered_set<int> us;
//   us.insert(x);  us.erase(x);  us.find(x);  us.count(x);
//   // no lower_bound, no order
//
// Complexity: avg O(1), worst O(n)
// OA use: seen set, two-sum hash, duplicate check
// Prefer set if you need order / closest / kth by order

// ============================================================
// MAP  (ordered unique keys, RB-tree)             MOST IMPORTANT
// ============================================================
//
//   map<int, int> mp;
//   mp[key] = val;                 // insert or update; [] inserts 0 if missing
//   mp.insert({k, v});             // no overwrite if exists
//   mp[k]++;                       // freq map — creates 0 then ++
//   mp.count(k);                   // 0 or 1   use before [] if you must not insert
//   mp.find(k);                    // iterator or mp.end()
//   mp.erase(k);
//   mp.lower_bound(k);  mp.upper_bound(k);
//
// Access
//   mp[k];                         // inserts default if absent  !!
//   mp.at(k);                      // throws if absent
//
// Iterate (keys sorted)
//   for (auto [k, v] : mp) {}
//   for (auto& p : mp) { p.first; p.second; }
//
// Complexity
//   insert / [] / find / erase    O(log n)
//
// OA use: ordered freq, coordinate compress helper, range of keys

// ============================================================
// UNORDERED_MAP  (hash)                           MOST IMPORTANT
// ============================================================
//
//   unordered_map<int, int> um;
//   unordered_map<string, int> ums;
//   um[key] = val;  um[k]++;  um.count(k);  um.find(k);  um.erase(k);
//   // same [] gotcha: um[k] inserts 0 if missing
//
// Complexity: avg O(1), worst O(n)
// OA use: frequency, prefix-sum hashmap, graph hashmap, two-sum
// Default: use this for freq; use map only if you need sorted keys

// ============================================================
// ITERATOR
// ============================================================
//
//   auto it = v.begin();           // first
//   auto it = v.end();             // one past last
//   *it;  ++it;  --it;
//   it - v.begin();                // index (random-access only: vector/array/deque)
//   next(it);  prev(it);           // C++11, works on bidir (set/map)
//   advance(it, k);
//
// Erase while iterating set/map
//   for (auto it = s.begin(); it != s.end(); ) {
//       if (*it == x) it = s.erase(it);
//       else ++it;
//   }
//
// reverse iterators: v.rbegin(), v.rend()

// ============================================================
// SORT                                            MOST IMPORTANT
// ============================================================
//
//   sort(v.begin(), v.end());                      // O(n log n)  introsort
//   sort(v.begin(), v.end(), greater<int>());
//   sort(a, a + n);                                // C-array
//
// Vector of pairs
//   sort(vp.begin(), vp.end());                    // by first, then second
//
// Custom (intervals by end)
//   sort(v.begin(), v.end(), [](auto& a, auto& b) {
//       return a[1] < b[1];
//   });
//
// stable_sort(...)  // when equal keys must keep order
//
// Partial: nth_element(v.begin(), v.begin()+k, v.end()); // avg O(n), kth

// ============================================================
// LOWER_BOUND / UPPER_BOUND                       MOST IMPORTANT
// ============================================================
// Prerequisite: SORTED range (asc)
//
//   auto it = lower_bound(v.begin(), v.end(), x);  // first >= x
//   auto it = upper_bound(v.begin(), v.end(), x);  // first > x
//   int i = it - v.begin();                        // index
//   binary_search(v.begin(), v.end(), x);          // bool
//
// Count of x in sorted v:
//   int cnt = upper_bound(v.begin(), v.end(), x)
//           - lower_bound(v.begin(), v.end(), x);
//
// Count in [L, R]:
//   upper_bound(..., R) - lower_bound(..., L);
//
// On set/map: s.lower_bound(x);  // member, O(log n)  do NOT use std::lower_bound on set (slower)
//
// Complexity: O(log n)
// OA use: binary search answers, first true, insert position, freq in sorted

// ============================================================
// REVERSE / MIN / MAX / ACCUMULATE / FIND
// ============================================================
//
// reverse
//   reverse(v.begin(), v.end());
//   reverse(s.begin(), s.end());
//
// min / max
//   min(a, b);  max(a, b);
//   min({a, b, c});                // initializer_list
//   *min_element(v.begin(), v.end());
//   *max_element(v.begin(), v.end());
//   int i = min_element(v.begin(), v.end()) - v.begin();  // index
//
// accumulate                                MOST IMPORTANT
//   long long sum = accumulate(v.begin(), v.end(), 0LL);  // 0LL not 0  !! overflow
//
// find
//   auto it = find(v.begin(), v.end(), x); // O(n)  unsorted
//   if (it != v.end()) int i = it - v.begin();

// ============================================================
// NEXT_PERMUTATION
// ============================================================
//
//   sort(v.begin(), v.end());      // start from smallest
//   do {
//       // use v
//   } while (next_permutation(v.begin(), v.end()));
//
//   prev_permutation(v.begin(), v.end());
//
// Also works on string.
// Complexity: O(n) per call. Total n! permutations.
// OA use: permute small n (<= 8–10), next permutation of digits

// ============================================================
// GCD / LCM  (C++17)
// ============================================================
//
//   int g = gcd(a, b);             // <numeric> via bits
//   long long l = lcm(a, b);       // a / gcd * b  — watch overflow
//   // gcd(0, n) == n
//
// OA use: fraction reduce, cycle, number theory, coprime checks

// ============================================================
// OA PATTERNS (high hit-rate)
// ============================================================
//
// Frequency
//   unordered_map<int, int> freq;
//   for (int x : v) freq[x]++;
//
// Prefix
//   vector<long long> pre(n + 1);
//   for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + v[i];
//   // sum[l..r] inclusive: pre[r+1] - pre[l]
//
// Adj list
//   vector<vector<int>> g(n);
//   g[u].push_back(v);
//
// Unique after sort
//   sort(v.begin(), v.end());
//   v.erase(unique(v.begin(), v.end()), v.end());
//
// Direction arrays
//   int dx[4] = {-1, 0, 1, 0};
//   int dy[4] = {0, 1, 0, -1};

// ============================================================
// 10-MINUTE REVISION CHECKLIST
// ============================================================
//
// [ ] vector: push_back, [], size, 2D init, sort, custom lambda
// [ ] string: substr, find vs npos, stoi / to_string, +=
// [ ] pair: {a,b}, .first/.second, auto [x,y], sort by first
// [ ] stack: push / top / pop (pop returns void)
// [ ] queue: push / front / pop — BFS
// [ ] deque: push/pop both ends — sliding window max, 0-1 BFS
// [ ] pq: max default; min = priority_queue<T, vector<T>, greater<T>>
// [ ] set: ordered unique, *begin min, *rbegin max, lower_bound
// [ ] multiset: erase(ms.find(x)) ONE; erase(x) ALL
// [ ] map vs unordered_map: [] inserts default; count/find to test
// [ ] lower_bound = first >= x; upper_bound = first > x  (sorted!)
// [ ] accumulate(..., 0LL)  — use long long zero
// [ ] next_permutation after sort; n small
// [ ] gcd / lcm C++17
// [ ] BFS queue, DFS recursion/stack, Dijkstra min-heap of pair<dist,node>
// [ ] freq unordered_map, prefix sum, two pointers on sorted array

// ============================================================
// STL CHEAT SHEET TABLE
// ============================================================
//
// Container        Ordered?  Duplicates?  Main ops              Typical complexity     Common DSA use
// ---------------  --------  -----------  --------------------  ---------------------  --------------------------
// vector           no*       yes          [] push pop erase     access O(1), mid O(n)  arrays, DP, adj, prefix
// string           no*       yes          [] substr find +=     access O(1), mod O(n)  parsing, palindrome
// array            no*       yes          []                    O(1)                   fixed buf (rare in OA)
// pair             n/a       n/a          first second          O(1)                   edges, (val, idx)
// stack            LIFO      yes          push top pop          O(1)                   NGE, parens, DFS
// queue            FIFO      yes          push front pop        O(1)                   BFS
// deque            no*       yes          push/pop both, []     ends O(1)              window max, 0-1 BFS
// priority_queue   heap      yes          push top pop          O(log n) / top O(1)    Dijkstra, Kth, greedy
// set              yes       no           insert find lb        O(log n)               ordered unique, closest
// multiset         yes       yes          insert erase(find)    O(log n)               sorted bag, median
// unordered_set    no        no           insert find           avg O(1)               seen / duplicates
// map              yes       keys unique  [] find lb            O(log n)               ordered freq / keys
// unordered_map    no        keys unique  [] find               avg O(1)               freq, two-sum, prefix hash
//
// * not key-ordered; vector/string/deque are index-ordered
// Algorithms: sort O(n log n) | lower/upper_bound O(log n) | reverse O(n)
//             min/max_element O(n) | accumulate O(n) | find O(n)
//             next_permutation O(n) | gcd/lcm ~O(log min(a,b))

int main() {
    // compile check only — examples live in comments above
    vector<int> v = {3, 1, 2};
    sort(v.begin(), v.end());
    auto lb = lower_bound(v.begin(), v.end(), 2);
    (void)(lb - v.begin());
    string s = "10";
    (void)stoi(s);
    (void)to_string(10);
    pair<int, int> p = {1, 2};
    auto [a, b] = p;
    (void)a; (void)b;
    stack<int> st; st.push(1); st.pop();
    queue<int> q; q.push(1); q.pop();
    deque<int> dq; dq.push_front(1); dq.pop_back();
    priority_queue<int> mx; mx.push(1);
    priority_queue<int, vector<int>, greater<int>> mn; mn.push(1);
    set<int> se; se.insert(1);
    multiset<int> ms; ms.insert(1); ms.erase(ms.find(1));
    unordered_set<int> us; us.insert(1);
    map<int, int> mp; mp[1]++;
    unordered_map<int, int> um; um[1]++;
    (void)gcd(12, 8);
    (void)lcm(4, 6);
    (void)accumulate(v.begin(), v.end(), 0LL);
    next_permutation(v.begin(), v.end());
    return 0;
}
