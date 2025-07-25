# Sparse-Matrix
A Sparse Matrix is a Matris or a 2 dimensional array that contains more 0's than 1's.

# Sparse Matrix

A **Sparse Matrix** is a matrix in which most of the elements are zero. These matrices are used in scenarios where memory and computational efficiency are important, especially in large-scale scientific and engineering applications.

## Why Use Sparse Matrices?

- **Memory Efficient**: Saves memory by storing only non-zero elements.
- **Faster Computations**: Operations like matrix multiplication and solving linear systems are faster when optimized for sparsity.
- **Scalability**: Useful for working with high-dimensional data in machine learning, computer graphics, and optimization problems.

## Common Storage Formats

- **COO (Coordinate List)**: Stores row, column, and value tuples for each non-zero element.
- **CSR (Compressed Sparse Row)**: Stores non-zero values row-wise for efficient row slicing.
- **CSC (Compressed Sparse Column)**: Similar to CSR but stores column-wise for efficient column slicing.

## Applications

- Graph algorithms (adjacency matrices)
- Natural language processing (term-document matrices)
- Recommender systems
- Finite element analysis

---
