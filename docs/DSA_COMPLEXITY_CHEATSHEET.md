# DSA Complexity Cheat Sheet

Interview-focused revision of time and space complexity. Assumptions are stated when they matter.

**Notation:** `n` = elements, `V` = vertices, `E` = edges, `h` = tree height, `L` = string length, `W` = knapsack capacity, `k` = range/extra parameter.

---

## 1. Big-O Quick Reference

| Complexity | Name | Typical example | Intuition |
|---|---|---|---|
| `O(1)` | Constant | Array index access, hash average lookup | Work does not grow with `n` |
| `O(log n)` | Logarithmic | Binary search, balanced BST height | Halve the search space each step |
| `O(n)` | Linear | Linear scan, tree traversal | Touch each element a constant number of times |
| `O(n log n)` | Linearithmic | Merge sort, heap sort, efficient sorting lower bound | `n` items, each paying `log n` (divide/conquer or heap) |
| `O(n²)` | Quadratic | Nested loops, naive LIS DP | Pair every element with every other |
| `O(2^n)` | Exponential | Subsets, naive recursion `T(n)=2T(n-1)` | Each item: take or skip |
| `O(n!)` | Factorial | Permutations, naive TSP | All orderings of `n` items |

### Growth order

`O(1)` < `O(log n)` < `O(n)` < `O(n log n)` < `O(n²)` < `O(2^n)` < `O(n!)`

---

## 2. Array / Vector

C++ `std::vector` / contiguous array. Random access is `O(1)`. Insert/erase in the middle shifts elements.

| Operation | Time | Notes |
|---|---|---|
| Access by index | **`O(1)`** | Random access |
| Search (unsorted) | `O(n)` | Linear scan |
| Insert at beginning | `O(n)` | Shift all elements |
| Insert at middle | `O(n)` | Shift the suffix |
| Insert at end | **Amortized `O(1)`** | Same as `push_back` if capacity allows |
| Delete from beginning | `O(n)` | Shift all elements |
| Delete from middle | `O(n)` | Shift the suffix |
| Delete from end | **`O(1)`** | Same as `pop_back` |
| `push_back` | **Amortized `O(1)`** | Worst **`O(n)`** on reallocation |
| `pop_back` | **`O(1)`** | No reallocation required |
| `resize` | `O(n)` typical | Grows/shrinks; new elements constructed |
| `sort` (`std::sort`) | Average `O(n log n)` | Introsort; worst `O(n log n)` in practice |

> **Interview Note:** `push_back` is **amortized `O(1)`** because capacity doubles. A single call can be **`O(n)`** when the buffer is copied. Do not say “always `O(1)`”.

---

## 3. Linked List

Finding a node is usually `O(n)`. Once you **already hold the relevant pointer(s)**, insert/delete can be `O(1)`.

### Singly Linked List

Assume a head pointer. Tail pointer only if stated.

| Operation | Time |
|---|---|
| Access by index | `O(n)` |
| Search by value | `O(n)` |
| Insert at head | **`O(1)`** |
| Insert at tail | `O(n)` without tail; **`O(1)`** with tail |
| Insert after a known node | **`O(1)`** |
| Delete head | **`O(1)`** |
| Delete after a known node | **`O(1)`** |
| Delete by value | `O(n)` (must search; need previous pointer) |

### Doubly Linked List

Assume head (and typically tail).

| Operation | Time |
|---|---|
| Access by index | `O(n)` |
| Search by value | `O(n)` |
| Insert at head | **`O(1)`** |
| Insert at tail | **`O(1)`** with tail |
| Insert after/before a known node | **`O(1)`** |
| Delete head | **`O(1)`** |
| Delete a known node | **`O(1)`** (have `prev` and `next`) |
| Delete by value | `O(n)` |

> **Interview Note:** Insert/delete is `O(1)` **only if the node/position is already known**. Locating that node is still `O(n)`. In a singly list you often need the **previous** node to delete.

---

## 4. Stack and Queue

Assume linked-list or `deque`-backed implementations (C++ `stack` / `queue` adapters).

### Stack

| Operation | Time |
|---|---|
| `push` | **`O(1)`** |
| `pop` | **`O(1)`** |
| `top` | **`O(1)`** |
| Search | `O(n)` |

### Queue

| Operation | Time |
|---|---|
| `push` / enqueue | **`O(1)`** |
| `pop` / dequeue | **`O(1)`** |
| `front` | **`O(1)`** |
| Search | `O(n)` |

> **Interview Note:** An array-based circular queue is also `O(1)` for enqueue/dequeue. A naive array queue that shifts on dequeue is `O(n)` — mention the implementation if asked.

### `deque` (C++ `std::deque`)

| Operation | Time |
|---|---|
| `push_front` / `push_back` | Amortized **`O(1)`** |
| `pop_front` / `pop_back` | **`O(1)`** |
| Random access `[]` | **`O(1)`** |
| Insert/erase in the middle | `O(n)` |

### `priority_queue` (binary heap)

See [§6](#6-heap--priority-queue). Default C++ `priority_queue` is a **max heap**.

| Operation | Time |
|---|---|
| `top` | **`O(1)`** |
| `push` | **`O(log n)`** |
| `pop` | **`O(log n)`** |

---

## 5. Hashing

C++ associative containers. Iteration is `O(n)` for all of them (visit every stored element).

| Container | insert | find / search | erase | access by key | iteration |
|---|---|---|---|---|---|
| `unordered_map` | Avg **`O(1)`**, worst `O(n)` | Avg **`O(1)`**, worst `O(n)` | Avg **`O(1)`**, worst `O(n)` | Avg **`O(1)`**, worst `O(n)` (`[]` / `at`) | `O(n)` |
| `unordered_set` | Avg **`O(1)`**, worst `O(n)` | Avg **`O(1)`**, worst `O(n)` | Avg **`O(1)`**, worst `O(n)` | N/A (no mapped value) | `O(n)` |
| `map` | **`O(log n)`** | **`O(log n)`** | **`O(log n)`** | **`O(log n)`** | `O(n)` |
| `set` | **`O(log n)`** | **`O(log n)`** | **`O(log n)`** | N/A | `O(n)` |

`map` / `set` are typically **red-black trees**. Worst case is still `O(log n)`, not `O(n)`.

> **Interview Note:** `unordered_map` is **average `O(1)`** because a good hash spreads keys into buckets and you expect a constant-size chain (or equivalent). **Worst case is `O(n)`** on collisions / adversarial hashes. Never say “hash maps are always `O(1)`”. Prefer `map` when you need order or a guaranteed `O(log n)` bound.

---

## 6. Heap / Priority Queue

Binary heap (array-based). Min heap and max heap have the **same complexities**; only the comparison differs.

### Binary Heap

| Operation | Time |
|---|---|
| Get min / max (`top`) | **`O(1)`** |
| Insert (`push`) | **`O(log n)`** |
| Extract min / max (`pop`) | **`O(log n)`** |
| Heapify / sift-down one node | `O(log n)` |
| Build heap (`make_heap` / Floyd) | **`O(n)`** |
| Search for an arbitrary value | `O(n)` |

C++ `priority_queue`: `top` **`O(1)`**, `push` **`O(log n)`**, `pop` **`O(log n)`**. No decrease-key; “update priority” is usually push a new pair or rebuild.

> **Interview Note:** Building a heap from `n` items is **`O(n)`**, not `O(n log n)`. Heap sort is still **`O(n log n)`** because of `n` extracts.

---

## 7. Binary Tree

General binary tree (not necessarily BST). `n` = nodes, `h` = height, `w` = max width (nodes on the widest level).

| Operation | Time | Extra space |
|---|---|---|
| Preorder / inorder / postorder (DFS) | **`O(n)`** | `O(h)` recursion / explicit stack |
| BFS / level order | **`O(n)`** | **`O(w)`** queue |
| Search | `O(n)` | `O(h)` or `O(w)` |
| Insert / delete (no BST structure) | `O(n)` typical | Need to find the node |
| Height | `O(n)` | `O(h)` |
| Count nodes | `O(n)` | `O(h)` |

- Balanced tree: `h = Θ(log n)`, `w` can still be `Θ(n)` in the last level.
- Skewed tree: `h = Θ(n)`, DFS stack is `O(n)`.
- BFS worst extra space is `O(n)` when `w = Θ(n)`.

---

## 8. Binary Search Tree

All point operations run in **`O(h)`**. Balanced ≈ `h = O(log n)`. Skewed `h = Θ(n)`.

| Operation | Average / balanced | Worst / skewed |
|---|---|---|
| Search | **`O(log n)`** | `O(n)` |
| Insert | **`O(log n)`** | `O(n)` |
| Delete | **`O(log n)`** | `O(n)` |
| Find min / max | **`O(log n)`** | `O(n)` |
| Predecessor / successor | **`O(log n)`** | `O(n)` |
| Inorder traversal | `O(n)` | `O(n)` |

> **Interview Note:** Quote **`O(h)`**, then map to `O(log n)` vs `O(n)`. Inorder of a BST is sorted in `O(n)`.

---

## 9. Balanced BST (AVL / Red-Black)

Self-balancing BSTs keep `h = O(log n)`.

| Structure | Search / insert / delete | Extra notes |
|---|---|---|
| AVL | **`O(log n)`** | Stricter balance; slightly slower updates |
| Red-Black (`std::map` / `set`) | **`O(log n)`** guaranteed | Interview default for “ordered set/map” |
| Treap / splay (average) | Expected `O(log n)` | Splay worst can be worse; rarely required |

Use when you need **order statistics / sorted keys** with logarithmic updates (unlike hash tables).

---

## 10. Graph Representation

`V` = vertices, `E` = edges. Directed vs undirected only changes how you store each edge (1 vs 2 list entries).

| Operation | Adjacency matrix | Adjacency list |
|---|---|---|
| Space | **`O(V²)`** | **`O(V + E)`** |
| Check edge `u → v` | **`O(1)`** | `O(degree(u))` |
| Add edge | **`O(1)`** | **`O(1)`** (append) |
| Iterate neighbors of `u` | `O(V)` | **`O(degree(u))`** |

> **Interview Note:** Prefer **lists** for sparse graphs (`E ≪ V²`) — almost all coding-interview graphs. Prefer a **matrix** for dense graphs, `O(1)` edge queries, or Floyd-Warshall.

---

# GRAPH ALGORITHMS

Assume **adjacency list** unless noted.

## 11. BFS

| | Complexity |
|---|---|
| Time | **`O(V + E)`** |
| Space | **`O(V)`** (queue + visited) |

Each vertex is enqueued at most once; each edge is scanned a constant number of times.

**Grid BFS** (`N × M` cells, 4/8-neighbors): time and space **`O(N × M)`**.

---

## 12. DFS

| | Complexity |
|---|---|
| Time | **`O(V + E)`** |
| Space | **`O(V)`** (recursion / explicit stack + visited) |

**Grid DFS:** **`O(N × M)`** time; recursion depth can be `O(N × M)` in a snake path.

> **Interview Note:** Same asymptotic time as BFS on lists. Space differs: DFS `O(V)` stack in the worst path; BFS `O(w)` queue.

---

## 13. Topological Sort

Valid **only on DAGs**.

| Algorithm | Time | Space |
|---|---|---|
| Kahn’s (BFS + indegree) | **`O(V + E)`** | `O(V)` |
| DFS (finish-time reverse) | **`O(V + E)`** | `O(V)` |

If the result has fewer than `V` nodes (Kahn) or you hit a back edge (DFS), a cycle exists.

---

## 14. Shortest Path Algorithms

| Algorithm | Use case | Time (adj. list unless noted) | Important limitation |
|---|---|---|---|
| BFS | Unweighted / **unit** weights | **`O(V + E)`** | Wrong if weights vary |
| Dijkstra (binary heap) | **Non-negative** weights, single source | **`O((V + E) log V)`**; often **`O(E log V)`** on sparse graphs | Fails with negative edges |
| Bellman-Ford | Single source, **negative edges** OK | **`O(VE)`** | Negative **cycle** → no shortest path |
| Floyd-Warshall | **All-pairs**, dense OK | **`O(V³)`** | `O(V²)` space; slow for large `V` |
| DAG shortest path | DAG, any real weights | **`O(V + E)`** | Graph must be acyclic |

Dijkstra with a **binary heap** (interview standard): each decrease/push is `O(log V)`; up to `O(E)` heap operations → **`O((V + E) log V)`**. For sparse graphs people say **`O(E log V)`**. Fibonacci heap `O(E + V log V)` is theory-only in interviews.

> **Interview Note:** BFS ≠ Dijkstra. BFS is a special case when every edge weight is `1`. Dijkstra needs a min-heap (or equivalent), not a FIFO queue.

---

## 15. Minimum Spanning Tree

Undirected, weighted, connected graph.

### Kruskal

1. Sort edges: **`O(E log E)`** (same as `O(E log V)`).
2. DSU `find` / `union` per edge: **`O(E · α(V))`**.
3. **Overall: `O(E log E)`**.

### Prim (binary min-heap)

Same shape as Dijkstra: **`O((V + E) log V)`**, often **`O(E log V)`** sparse.

### DSU inside Kruskal

Path compression + union by rank/size: **amortized `O(α(n))` per op** — inverse Ackermann, **effectively constant** in practice.

---

# SORTING AND SEARCHING

## 16. Searching Algorithms

| Algorithm | Best | Average | Worst | Space |
|---|---|---|---|---|
| Linear search | `O(1)` | `O(n)` | `O(n)` | `O(1)` |
| Binary search | `O(1)` | **`O(log n)`** | **`O(log n)`** | `O(1)` iterative; `O(log n)` recursive |

**Prerequisite for binary search:** the array (or search space) must be **monotonic / sorted**.

**Binary search on answers** (min feasible `x`): `O(T(n) log R)` where `R` is the numeric range and `T(n)` is the feasibility check.

---

## 17. Sorting Algorithms

`n` = items, `k` = distinct keys / max value range for counting sort.

| Algorithm | Best | Average | Worst | Extra space | Stable? |
|---|---|---|---|---|---|
| Bubble sort | **`O(n)`** (swapped-flag, already sorted) | `O(n²)` | `O(n²)` | `O(1)` | Yes |
| Selection sort | `O(n²)` | `O(n²)` | `O(n²)` | `O(1)` | No (typical) |
| Insertion sort | **`O(n)`** (already sorted) | `O(n²)` | `O(n²)` | `O(1)` | Yes |
| Merge sort | **`O(n log n)`** | **`O(n log n)`** | **`O(n log n)`** | `O(n)` | Yes |
| Quick sort | `O(n log n)` | **`O(n log n)`** | **`O(n²)`** (bad pivots) | `O(log n)` avg stack | No (typical) |
| Heap sort | `O(n log n)` | **`O(n log n)`** | **`O(n log n)`** | `O(1)` | No |
| Counting sort | `O(n + k)` | **`O(n + k)`** | `O(n + k)` | `O(k)` | Yes |

> **Interview Note:** Comparison sorts cannot beat `O(n log n)` in the worst case. Quick sort’s **average** is `O(n log n)`; **worst** is `O(n²)` unless you randomize / use introselect-style fallbacks (`std::sort`). Counting sort is **not** a comparison sort; it needs a small integer range `k`.

---

# COMMON DSA ALGORITHMS / PATTERNS

## 18. Two Pointers & Sliding Window

Assume an array/string of length `n`.

| Pattern | Typical time | Typical extra space | When |
|---|---|---|---|
| Opposite two pointers (sorted pair/sum) | **`O(n)`** after sort `O(n log n)` | `O(1)` | Sorted array |
| Fast / slow pointers | **`O(n)`** | `O(1)` | Cycle, middle of list |
| Fixed-size window | **`O(n)`** | `O(1)` or `O(k)` | Subarray of length `k` |
| Variable window (2 pointers + map) | **`O(n)`** amortized | `O(k)` alphabet/map | Longest/shortest valid window |

Each index moves at most once in the standard window → **`O(n)`**, not `O(n²)`, if inner work is `O(1)` amortized.

> **Interview Note:** Nested `l`/`r` loops without monotonic movement are `O(n²)`. The `O(n)` claim needs the “each pointer only moves forward” argument.

---

## 19. String Algorithms

`n` = text length, `m` = pattern length, `L` = query/prefix length, `σ` = alphabet size.

| Algorithm | Time | Space | Solves |
|---|---|---|---|
| KMP | **`O(n + m)`** | `O(m)` LPS | Exact pattern matching, no backtracking on text |
| Rabin-Karp | Avg **`O(n + m)`**, worst `O(nm)` | `O(1)` hashes (plus output) | Pattern matching via rolling hash; multi-pattern variants exist |
| Z-algorithm | **`O(n)`** on the string you build | `O(n)` Z-array | Prefix matches at every position; pattern match via `pattern + $ + text` in `O(n + m)` |
| Trie prefix search | **`O(L)`** per insert/search | `O(σ · nodes)` | Prefix queries, word dictionary |

KMP: build LPS in `O(m)`, match in `O(n)` → **pattern matching `O(n + m)`**.

---

## 20. Backtracking

Complexity ≈ **(number of states) × (work per state)**. It is **not** one formula for every problem.

| Pattern | Typical time (output-sensitive / bound) | Notes |
|---|---|---|
| Subsets | **`O(2^n)`** subsets; often `O(n · 2^n)` to copy | Include/exclude each element |
| Permutations | **`O(n!)`**; often `O(n · n!)` to copy | Swap/used-array |
| Combination Sum | Depends on target and candidates | Can be exponential in target / branching |
| N-Queens | Roughly **`O(n!)`** (pruned) | Not a tight closed form |
| Sudoku | Exponential; pruning-heavy | Bound by filling empty cells |

Space: recursion depth (often `O(n)`) plus the current partial answer.

> **Interview Note:** State the **search tree size**, then multiply by work to build each answer. Pruning changes the practical time, not a smaller Big-O unless you prove it.

---

# DYNAMIC PROGRAMMING

## 21. DP Complexity Mental Model

**Time ≈ number of states × transitions per state.**  
**Space ≈ number of states**, or fewer after rolling arrays.

| Problem | States × transitions | Time | Typical space |
|---|---|---|---|
| 1D DP (e.g. climb stairs) | `n` × `O(1)` | **`O(n)`** | `O(n)` or `O(1)` |
| Grid paths / 2D grid DP | `n·m` × `O(1)` | **`O(nm)`** | `O(nm)` or `O(min(n,m))` |
| 0/1 Knapsack | `n·W` × `O(1)` | **`O(nW)`** | `O(nW)` or `O(W)` |
| LIS (classic DP) | `n` × `O(n)` | **`O(n²)`** | `O(n)` |
| LIS (patience / tails + BS) | `n` × `O(log n)` | **`O(n log n)`** | `O(n)` |
| LCS | `n·m` × `O(1)` | **`O(nm)`** | `O(nm)` or `O(min(n,m))` |
| Matrix Chain Multiplication | `O(n²)` lengths × `O(n)` splits | **`O(n³)`** | `O(n²)` |

Space optimization: if `dp[i]` only needs `dp[i-1]` (or previous row), drop to `O(W)`, `O(m)`, or `O(1)`.

> **Interview Note:** Always define **what a state is** first. Wrong state count is the usual complexity mistake.

---

# SPECIAL DATA STRUCTURES

## 22. DSU / Disjoint Set Union

With **path compression + union by rank/size**:

| Operation | Complexity |
|---|---|
| `makeSet` | **`O(1)`** |
| `find` | Amortized **`O(α(n))`** |
| `union` | Amortized **`O(α(n))`** |

`α(n)` is inverse Ackermann — **treat as constant** in interviews. Naive DSU (no heuristics) can be `O(n)` per `find`.

---

## 23. Trie

| Operation | Time | Space |
|---|---|---|
| Insert word of length `L` | **`O(L)`** | New nodes along the word |
| Search / prefix of length `L` | **`O(L)`** | — |
| Full dictionary | — | **`O(σ · total characters)`** worst; often closer to unique prefixes |

Not `O(1)` — cost follows **string length**, independent of how many *other* words exist (unless you count node allocation).

---

# RECURSION COMPLEXITY

## 24. Common Recursion Patterns

Always quote **time** and **stack space** separately.

### Single recursive call

`T(n) = T(n-1) + O(1)` → time **`O(n)`**, stack **`O(n)`**.  
Example: linear scan / factorial (value, not permutations).

### Divide and conquer

`T(n) = 2T(n/2) + O(n)` → time **`O(n log n)`**, stack **`O(log n)`**.  
Example: merge sort.

### Binary branching (no overlap)

`T(n) = 2T(n-1) + O(1)` → time **`O(2^n)`**, stack **`O(n)`**.  
Example: subset recursion without memo.

### Factorial recursion

Generating permutations → time **`O(n!)`** (often `O(n · n!)`), stack **`O(n)`**.

Memoized recursion becomes DP: time bounded by **distinct states × work**.

---

## 25. 5-Minute Interview Revision

| Topic | Remember |
|---|---|
| Vector `push_back` | Amortized `O(1)`, worst `O(n)` realloc |
| Hash (`unordered_*`) | Avg `O(1)`, worst `O(n)` |
| `map` / `set` | Always `O(log n)` |
| Heap `top` / `push` / `pop` | `O(1)` / `O(log n)` / `O(log n)`; build **`O(n)`** |
| BST | `O(h)` → `O(log n)` balanced, `O(n)` skewed |
| BFS / DFS | `O(V + E)`; grid `O(NM)` |
| Dijkstra (bin-heap) | `O((V+E) log V)`, non-negative weights |
| Bellman-Ford | `O(VE)`, negative edges OK |
| Floyd-Warshall | `O(V³)` all-pairs |
| Kruskal | `O(E log E)` |
| Binary search | `O(log n)`, sorted/monotonic |
| Merge / heap sort | `O(n log n)` |
| Quick sort | Avg `O(n log n)`, worst `O(n²)` |
| KMP | `O(n + m)` |
| Subsets / perms | `O(2^n)` / `O(n!)` |
| Knapsack / LCS / LIS | `O(nW)` / `O(nm)` / `O(n²)` or `O(n log n)` |
| DSU | `≈ O(1)` amortized with PC + union by rank |
| Recurrence `2T(n/2)+O(n)` | `O(n log n)` |
| Recurrence `2T(n-1)+O(1)` | `O(2^n)` |
