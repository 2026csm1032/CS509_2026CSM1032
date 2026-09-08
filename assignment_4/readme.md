# Assignment 04 - Graph Analytics using CSR

## Course

**CS509 - Programming Lab**

## Assignment Type

**Individual Assignment**

---

## Student Details

- Name - Rakshit Gautam
- Entry Number - 2026CSM1032

---

# Objective

In this assignment, graph analytics algorithms are implemented using the Compressed Sparse Row (CSR) representation developed in Assignment 01.

The following algorithms are implemented:

- Greedy Vertex Coloring
- PageRank

The CSR conversion function from Assignment 01 is reused as required in the assignment specification.

---

# Algorithm Description

## 1. Vertex Coloring

Vertex Coloring assigns colors to graph vertices such that no two adjacent vertices share the same color.

### Features

- Uses CSR graph representation
- Greedy coloring approach
- Vertices processed in descending order of degree
- Produces a valid graph coloring
- Reports total number of colors used

### Steps

1. Compute degree of every vertex.
2. Sort vertices in descending order of degree.
3. For each vertex:
   - Mark colors already used by adjacent vertices.
   - Assign the smallest available color.
4. Continue until all vertices are colored.

---

## 2. PageRank

PageRank computes the importance score of each vertex in a directed graph.

### Features

- Uses CSR graph representation
- Supports dangling vertices
- Configurable damping factor
- Iterative convergence-based computation
- Reports convergence status and iteration count

### Steps

1. Initialize all ranks to 1/V.
2. Compute incoming rank contributions.
3. Distribute dangling-node rank mass.
4. Apply damping factor.
5. Repeat until:
   - Convergence tolerance is reached, or
   - Maximum iterations are reached.

---

# Input Format

## Vertex Coloring

```text
V E

u0 degree neighbor1 neighbor2 ...
u1 degree neighbor1 neighbor2 ...
...
u(V-1) degree neighbor1 neighbor2 ...
```

### Example

```text
5 6

0 2 1 2
1 3 0 2 3
2 3 0 1 4
3 2 1 4
4 2 2 3
```

---

## PageRank

```text
V E

u0 outdegree neighbor1 neighbor2 ...
u1 outdegree neighbor1 neighbor2 ...
...
u(V-1) outdegree neighbor1 neighbor2 ...

DAMPING d
TOLERANCE epsilon
MAX_ITERATIONS n
```

### Example

```text
4 4

0 1 1
1 1 2
2 2 0 1
3 1 2

DAMPING 0.85
TOLERANCE 0.0001
MAX_ITERATIONS 100
```

---

# Output Format

## Vertex Coloring

```text
Algorithm: Greedy Vertex Coloring

Vertex colors:
0 0
1 1
2 2
3 0
4 1

Colors used: 3

Execution time: <value> ms
```

---

## PageRank

```text
Algorithm: PageRank

Damping: 0.85

Vertex ranks:
0 0.226283
1 0.267536
2 0.297557
3 0.208624

Sum of ranks: 1.000000

Iterations: <value>
Converged: true

Execution time: <value> ms
```

---

# Folder Structure

```text
CS509_2026CSM1032/
|
├── common_wrapper/
│   └── wrapper.cpp
|
├── assignment_1/
│
├── assignment_2/
│
├── assignment_3/
│
└── assignment_4/
    |
    ├── driver/
    │   ├── main_driver.cpp
    │   ├── vertex_coloring_driver.cpp
    │   └── pagerank_driver.cpp
    |
    ├── src/
    │   ├── vertex_coloring.cpp
    │   ├── vertex_coloring.h
    │   ├── pagerank.cpp
    │   └── pagerank.h
    |
    ├── tests/
    │   ├── vertex_coloring/
    │   └── pagerank/
    |
    └── outputs/
```

---

# File Description

| File | Description |
|--------|--------|
| vertex_coloring.cpp | Greedy Vertex Coloring implementation |
| vertex_coloring.h | Vertex Coloring declarations |
| pagerank.cpp | PageRank implementation |
| pagerank.h | PageRank declarations |
| vertex_coloring_driver.cpp | Reads graph input and executes Vertex Coloring |
| pagerank_driver.cpp | Reads graph input and executes PageRank |
| main_driver.cpp | Menu-driven execution of Assignment 04 |
| README.md | Assignment documentation |

---

# Compilation

## Vertex Coloring

```bash
g++ driver/vertex_coloring_driver.cpp src/vertex_coloring.cpp ../assignment_1/src/csr.cpp -o vertex_coloring.exe
```

## PageRank

```bash
g++ driver/pagerank_driver.cpp src/pagerank.cpp ../assignment_1/src/csr.cpp -o pagerank.exe
```

---

# Execution

Run Assignment 04:

```bash
assignment_4.exe
```

The program displays:

```text
1. Vertex Coloring
2. PageRank
0. Exit
```

Select the desired algorithm and then choose the required test file.

Outputs are automatically generated inside the outputs directory.

---

# Time Complexity

## Vertex Coloring

```text
O(V log V + E)
```

- Degree computation: O(V)
- Sorting vertices: O(V log V)
- Coloring process: O(E)

---

## PageRank

```text
O(I × (V + E))
```

where:

- I = number of iterations until convergence

---

# Space Complexity

## Vertex Coloring

```text
O(V + E)
```

---

## PageRank

```text
O(V + E)
```

---

# Vertex Coloring Results Table

| File | V | E | Colors Used | Valid? | Time | Status |
|--------|----:|----:|----:|--------|--------:|--------|
| color_10.txt | 10 | 25 | 3 | Yes | 0.000000 ms | Pass |
| color_100.txt | 100 | 400 | 2 | Yes | 0.000000 ms | Pass |
| color_10000.txt | 10000 | 4000 | 2 | Yes | 9.002000 ms | Pass |
| color_50000.txt | 50000 | 200000 | 2 | Yes | 38.004000 ms | Pass |
| color_100000.txt | 100000 | 400000 | 2 | Yes | 55.342000 ms | Pass |

---

# PageRank Results Table

| File | V | E | Damping | Sum of Ranks | Iter. / Time | Status |
|--------|----:|----:|--------|--------:|--------|--------|
| pagerank_10.txt | 10 | 30 | 0.85  | ~1.000 | 18/0.000000 ms | Pass |
| pagerank_100.txt | 100 | 300 | 0.85  | ~1.000 | 19/0.000000 ms | Pass |
| pagerank_1000.txt | 1000 | 3000 | 0.85  | ~1.000 | 18/4.989000 ms | Pass |
| pagerank_10000.txt | 10000 | 30000 | 0.85  | ~1.000 | 19/40.610000 ms | Pass |
| pagerank_50000.txt | 50000 | 150000 | 0.85  | ~1.000 | 16/116.654000 ms | Pass |

---

# Findings / Observations

## Vertex Coloring

1. The greedy coloring algorithm successfully produced valid color assignments for all test graphs.
2. Ordering vertices by descending degree reduced the number of colors used compared to arbitrary ordering.
3. Sparse graphs required relatively few colors even for large values of V.
4. CSR representation enabled efficient adjacency traversal while keeping memory usage low.
5. Execution time increased gradually with graph size due to sparse graph structure.

## PageRank

1. PageRank converged successfully for all required test cases.
2. The sum of PageRank values remained approximately equal to 1.0 after convergence.
3. The damping factor of 0.85 produced stable ranking behavior.
4. Dangling-node handling prevented rank leakage and maintained rank conservation.
5. Runtime increased with both graph size and the number of iterations required for convergence.
6. CSR representation significantly reduced memory usage compared to adjacency matrix storage.

---

# Timing Methodology

- Timer starts immediately before calling the algorithm.
- Timer stops immediately after the algorithm finishes.
- CSR conversion time is not included.
- Input parsing time is not included.
- Output generation and file writing time are not included.
- Execution time is reported in milliseconds.

---

# Compiler

- Language : C++
- Compiler : g++

---

# References

1. Assignment 04 Specification
2. GeeksforGeeks
3. PageRank Original Paper (Brin & Page)
4. CLRS Algorithms
5. Striver DSA