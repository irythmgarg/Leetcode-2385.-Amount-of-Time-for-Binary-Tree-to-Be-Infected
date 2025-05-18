# Leetcode-2385.-Amount-of-Time-for-Binary-Tree-to-Be-Infected

# 🌳 Amount of Time for Binary Tree to Be Infected

This project solves the **LeetCode problem: Amount of Time for Binary Tree to Be Infected** using C++. The problem involves calculating the time it takes to infect the entire binary tree starting from a given node, where infection spreads to adjacent nodes (children and parent) every minute.

---

## 🚀 Problem Statement

You are given the `root` of a binary tree and an integer `start`, representing the starting infected node. Each minute, the infection spreads from the infected node to all its uninfected **directly connected nodes** (i.e., its parent or children).

**Goal**: Return the **number of minutes** it takes to infect the whole tree.

---

## 🧠 Approach

1. **Convert the binary tree into an undirected graph** using adjacency lists.
2. **Perform a BFS traversal** from the start node to simulate the spread of infection.
3. Track the number of levels traversed (which represents time in minutes).

---

## 🔧 Code Structure

- `TreeNode`: Standard structure to represent nodes in a binary tree.
- `relations()`: Recursive function to convert the binary tree into a graph.
- `amountOfTime()`: Function that performs BFS to determine time required to infect the entire tree.

---

📈 Time & Space Complexity

Time Complexity: O(n), where n is the number of nodes in the tree.

Space Complexity: O(n) for the graph, visited set, and queue.


