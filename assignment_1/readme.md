# Assignment 01 - GEMM and CSR Representation

## Course

**CS509 - Software Lab**

## Assignment Type

**Single Assignment**

## Student Details

- **Name:** Rakshit Gautam
- **Entry Number:** 2026CSM1032

---

# Objective

This assignment consists of two independent tasks:

## Task 1: General Matrix Multiplication (GEMM)

Implement and compare two matrix multiplication algorithms:

- Simple GEMM (Naive Triple Loop Method)
- Blocking GEMM (Cache-Friendly Tiled Multiplication)

Execution time of both implementations is measured and compared.

## Task 2: Compressed Sparse Row (CSR) Representation

Given a graph in adjacency-list format, convert the graph into CSR (Compressed Sparse Row) representation.

CSR is a compact representation of sparse graphs and is commonly used in graph-processing systems and high-performance computing.

---

# Algorithm Description

## 1. Simple GEMM

The Simple GEMM implementation uses three nested loops.

For matrices:

- A of size M × K
- B of size K × N

The result matrix C is computed as:

C[i][j] = Σ A[i][k] × B[k][j]

### Time Complexity

O(M × K × N)

### Space Complexity

O(M × N)

---

## 2. Blocking GEMM

Blocking GEMM divides matrices into smaller blocks (tiles) and performs multiplication block by block.

This improves cache locality and reduces memory-access overhead for larger matrices.

### Block Size Used

32

### Time Complexity

O(M × K × N)

### Space Complexity

O(M × N)

---

## 3. CSR Representation

The graph is first stored as an adjacency list.

The adjacency list is then converted into CSR format using two arrays:

### row_ptr

Stores the starting index of each vertex's adjacency list in the col_idx array.

### col_idx

Stores all neighbours of all vertices sequentially.

### Example

Adjacency List:

0 → 1 2

1 → 0 3

2 → 0 3 4

CSR Representation:

row_ptr = {0, 2, 4, 7, 9, 10}

col_idx = {1, 2, 0, 3, 0, 3, 4, 1, 2, 2}

### Time Complexity

O(V + E)

### Space Complexity

O(V + E)

---

# Input Formats

## GEMM Input Format

Each test file contains one test case.

```text
M K N

Matrix A

Matrix B
```

Example:

```text
2 3 2

1 2 3
4 5 6

7 8
9 10
11 12
```

Where:

- Matrix A is M × K
- Matrix B is K × N

---

## CSR Input Format

```text
V E

u0 degree neighbour1 neighbour2 ...
u1 degree neighbour1 neighbour2 ...
...
u(V-1) degree neighbour1 neighbour2 ...
```

Example:

```text
5 5

0 2 1 2
1 2 0 3
2 3 0 3 4
3 2 1 2
4 1 2
```

Where:

- V = Number of vertices
- E = Number of edges
- degree = Number of neighbours of the vertex

---

# Output Format

## GEMM

For every test case:

- Result Matrix (Simple GEMM)
- Execution Time (Simple GEMM)
- Result Matrix (Blocking GEMM)
- Execution Time (Blocking GEMM)

The results are written to:

```text
outputs/gemm_output_<test_file_name>
```

---

## CSR

For every test case:

- row_ptr array
- col_idx array
- Execution Time

The results are written to:

```text
outputs/csr_output_<test_file_name>
```

---

# Folder Structure

```text
CS509_2026CSM1032/

├── common_wrapper/
│   └── wrapper.cpp

├── assignment_1/
│
│   ├── driver/
│   │   ├── main_driver.cpp
│   │   ├── gemm_driver.cpp
│   │   └── csr_driver.cpp
│
│   ├── src/
│   │   ├── gemm_simple.cpp
│   │   ├── gemm_simple.h
│   │   ├── gemm_blocking.cpp
│   │   ├── gemm_blocking.h
│   │   ├── csr.cpp
│   │   └── csr.h
│
│   ├── tests/
│   │   ├── gemm/
│   │   └── csr/
│
│   ├── outputs/
│   │
│   └── README.md
```

---

# File Description

| File | Description |
|--------|-------------|
| main_driver.cpp | Assignment-level menu for selecting GEMM or CSR and running test files |
| gemm_driver.cpp | Reads matrix input, executes GEMM algorithms and stores results |
| csr_driver.cpp | Reads graph input, converts adjacency list to CSR and stores results |
| gemm_simple.cpp | Naive matrix multiplication implementation |
| gemm_blocking.cpp | Blocking matrix multiplication implementation |
| csr.cpp | CSR conversion implementation |
| wrapper.cpp | Repository-level common wrapper |
| tests/ | Contains all input test files |
| outputs/ | Contains generated output files |

---

# Compilation

## Compile Assignment Driver

```bash
g++ driver/main_driver.cpp -o assignment_1.exe
```

## Run

```bash
assignment_1.exe
```

---

# Driver Functionality

The assignment driver provides the following features:

1. Select GEMM or CSR task.
2. Automatically compile the required executable if it is not already present.
3. Display available test files.
4. Execute a selected test case.
5. Execute all test cases.
6. Store outputs in the outputs directory.

---

# Runtime Measurement

Execution time is measured according to the lab guidelines:

- File reading is excluded.
- Input parsing is excluded.
- Output writing is excluded.
- Timer starts immediately before the algorithm call.
- Timer stops immediately after algorithm completion.
- Execution time is reported in milliseconds (ms).

---

## GEMM Results Table

| Test File | Input Type / Size | Expected Output | Actual Output | Simple Time (ms) | Blocking Time (ms) | Block Size | Status |
|-----------|------------------|----------------|--------------|------------------|-------------------|------------|--------|
| test_02.txt | 100 × 150 and 150 × 100 | Result Matrix | Result Matrix | 19.9 ms | 20.855 ms | 32 | Pass |
| test_03.txt | 50 × 50 and 50 × 50 | Result Matrix | Result Matrix | 0.903 ms | 0.001 ms | 32 | Pass |
| test_04.txt | 500 × 500 and 500 × 500 | Result Matrix | Result Matrix | 2319.15 ms | 2132.58 ms | 32 | Pass |
| test_05.txt | 400 × 500 and 500 × 600 | Result Matrix | Result Matrix | 2091.19 ms | 2145.3 ms | 32 | Pass |
| test_06.txt | 1000 × 800 and 800 × 1000 | Result Matrix | Result Matrix | 16951.8 ms | 13243.1 ms | 32 | Pass |

---

## CSR Results Table

| Test File | Vertices (V) | Edges (E) | Input Type | Expected Output | Actual Output | Time (ms) | Status |
|------------|-------------|------------|------------|----------------|--------------|-----------|--------|
| csr_test_01.txt | 10 | 30 | Adjacency List | CSR Arrays | CSR Arrays | 0.001 ms | Pass |
| csr_test_02.txt | 10 | 30 | Adjacency List | CSR Arrays | CSR Arrays | 0.001 ms | Pass |
| csr_test_03.txt | 100 | 300 | Adjacency List | CSR Arrays | CSR Arrays | 0.001 ms | Pass |
| csr_test_04.txt | 100 | 300 | Adjacency List | CSR Arrays | CSR Arrays | 0.001 ms | Pass |
| csr_test_05.txt | 10000 | 30000 | Adjacency List | CSR Arrays | CSR Arrays | 1.003 ms | Pass |
| csr_test_07.txt | 50000 | 150000 | Adjacency List | CSR Arrays | CSR Arrays | 4.601 ms | Pass |
| csr_test_09.txt | 100000 | 300000 | Adjacency List | CSR Arrays | CSR Arrays | 7.521 ms | Pass |

# Compiler Information

- Language: C++
- Compiler: g++
- Standard Library: STL

---

# References

1. GeeksforGeeks
2. C++ STL Documentation
