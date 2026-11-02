# File-System-Representation-and-Search-Using-BFS-and-DFS

# File System Representation and Search Using BFS and DFS

## Activity Details

- College: UKF College of Engineering & Technology
- Semester: Third Semester
- Subject: Data Structures and Algorithms
- Activity ID: SY-S3-B-09
- Challenge: 17-B 09

## Aim

To represent a file system as a graph using an adjacency matrix and implement Breadth-First Search (BFS) and Depth-First Search (DFS) to search for a specified file.

## Description

This project represents files and directories as graph nodes.

Connections between files and directories are represented using an adjacency matrix.

BFS searches the graph level by level using a queue.

DFS searches the graph deeply using recursion.

Both algorithms display the traversal order and indicate whether the specified file is found.

## Technologies Used

- Programming Language: C
- Graph Representation: Adjacency Matrix
- Algorithms: BFS and DFS
- Data Structures: Queue and Recursion

## Files

- filesystem.c - Main C program
- sample_input.txt - Sample input
- sample_output.txt - Sample output

## How to Execute

1. Download or clone this repository.
2. Open the project in a C compiler.
3. Compile the program.

```bash
gcc filesystem.c -o filesystem
```

4. Run the program.

```bash
./filesystem
```

5. Enter the sample input provided in sample_input.txt.

## Sample Result

The program searches for the file Report starting from Root.

BFS Traversal:
Root Documents Downloads Notes Report

DFS Traversal:
Root Documents Notes Report

The file Report is successfully found using both BFS and DFS.

## Conclusion

The project demonstrates graph representation using an adjacency matrix and file searching using BFS and DFS.

Both algorithms successfully identify whether a specified file exists in the represented file system.
