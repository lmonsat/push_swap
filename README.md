# push_swap

A highly optimized stack-sorting algorithm project developed as part of the 42 curriculum. The goal is to sort integer data using two stacks and a limited set of operations, minimizing the total number of actions performed.

---

## Table of Contents

- [Description](#description)
- [Game Rules & Operations](#game-rules--operations)
- [Algorithmic Approach](#algorithmic-approach)
- [Instructions](#instructions)
  - [Compilation](#compilation)
  - [Execution](#execution)
  - [Testing & Benchmarks](#testing--benchmarks)
- [Resources & AI Usage](#resources)

---

## Description

The **push_swap** project is a competitive sorting puzzle. Given a random set of signed integers formatted as command-line arguments, the program calculates and outputs the shortest sequence of instructions to sort them into ascending order.

### Problem Constraints
- You start with two stacks:
  - **Stack A**: Contains a random list of unique integers.
  - **Stack B**: Starts empty.
- The only permitted actions are operations on these two stacks.
- The program must display the smallest list of instructions possible, separated by a newline (`\n`).
- In case of invalid inputs (non-integers, integers overflowing `INT_MIN` / `INT_MAX`, duplicates, or formatting issues), the program outputs `Error\n` to standard error (`stderr`).

---

## Game Rules & Operations

| Instruction | Description |
|---|---|
| `sa` | **Swap A**: Swap the first 2 elements at the top of stack `a`. Does nothing if $\le 1$ element. |
| `sb` | **Swap B**: Swap the first 2 elements at the top of stack `b`. Does nothing if $\le 1$ element. |
| `ss` | `sa` and `sb` simultaneously. |
| `pa` | **Push A**: Take the top element from `b` and put it at the top of `a`. Does nothing if `b` is empty. |
| `pb` | **Push B**: Take the top element from `a` and put it at the top of `b`. Does nothing if `a` is empty. |
| `ra` | **Rotate A**: Shift up all elements of stack `a` by 1. The first element becomes the last. |
| `rb` | **Rotate B**: Shift up all elements of stack `b` by 1. The first element becomes the last. |
| `rr` | `ra` and `rb` simultaneously. |
| `rra` | **Reverse Rotate A**: Shift down all elements of stack `a` by 1. The last element becomes the first. |
| `rrb` | **Reverse Rotate B**: Shift down all elements of stack `b` by 1. The last element becomes the first. |
| `rrr` | `rra` and `rrb` simultaneously. |

---

## Algorithmic Approach

The implementation uses specific sorting strategies depending on the number of elements:

### 1. Small Data Sets (Size $\le 5$)
- **2 elements (`algo_2`)**: A single `sa` if elements are out of order.
- **3 elements (`algo_3`)**: Hardcoded optimal state machine resolving all $3! = 6$ permutations in a maximum of 2 moves.
- **4 & 5 elements (`algo_4` / `algo_5`)**: Finds the smallest value(s), moves them to the top using the shortest rotation path (`ra` or `rra`), pushes them to stack `b`, sorts the remaining 3 elements in stack `a`, and pushes them back.

### 2. Large Data Sets (The Turk Algorithm / Greedy Cost Sort)
For $N > 5$, a cost-based mechanical sorting algorithm ("The Turk Algorithm") is implemented:
1. **Push to B (`rush_b`)**: Pushes elements from stack `a` into stack `b` until only 3 elements remain in `a`.
2. **Sort remaining 3 in A**: Applies `algo_3` to sort the 3 remaining elements.
3. **Target Node Matching**: For each element in stack `b`, determines its exact target destination in stack `a` (the smallest number in `a` that is greater than the element, or the minimum of `a` if none exists).
4. **Push Cost Calculation**: Computes the exact operational cost to bring both the element in `b` and its target node in `a` to the top of their respective stacks, leveraging combined rotations (`rr` / `rrr`) when both nodes are above or below the median.
5. **Cheapest Push Execution**: Selects and executes the move for the cheapest node until stack `b` is completely emptied back into stack `a`.
6. **Final Re-alignment**: Locates the minimum element of stack `a` and rotates it to the top (`move_min_to_top`).

---

## Instructions

### Prerequisites
- GCC / Clang compiler
- GNU Make

### Compilation
Build the project using the included Makefile:

```bash
# Compile the push_swap binary
make

# Remove intermediate object files
make clean

# Remove object files and executables
make fclean

# Recompile the entire project
make re
```

### Execution
The binary accepts numbers passed either as multiple parameters or as a single space-separated string:

```bash
# Multi-argument syntax
./push_swap 2 1 3 6 5 8

# Quoted single string syntax
./push_swap "2 1 3 6 5 8"

# Already sorted input (outputs nothing)
./push_swap 1 2 3 4 5

# Invalid input (displays Error on stderr)
./push_swap 4 2 2 5
# Error
```

### Testing & Benchmarks

Count the number of operations generated using `wc -l`:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

#### Official 42 Benchmark Targets
- **3 numbers**: $\le 3$ operations
- **5 numbers**: $\le 12$ operations
- **100 numbers**:
  - 5 points: $< 700$ operations
  - 4 points: $< 900$ operations
  - 3 points: $< 1100$ operations
  - 2 points: $< 1300$ operations
  - 1 point: $< 1500$ operations
- **500 numbers**:
  - 5 points: $< 5500$ operations
  - 4 points: $< 7000$ operations
  - 3 points: $< 8500$ operations
  - 2 points: $< 10000$ operations
  - 1 point: $< 11500$ operations

#### Automated Random Testing (Bash)
```bash
# Test with 100 random numbers
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with 500 random numbers
ARG=$(shuf -i 0-10000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

---

## Resources

### References & Documentation
- [42 Subject PDF](en.subject.pdf): Push_swap subject specification (Version 10.2).
- [Push_Swap: The Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d12e97): Detailed explanation of the greedy mechanical algorithm by A. Yigit Ogun.
- [Algorithm Complexity & Big O Notation](https://en.wikipedia.org/wiki/Big_O_notation): Complexity analysis for stack and linked list operations.

## Author

[lmonsat](https://profile.intra.42.fr/users/lmonsat)

## 42 School

This project was developed as part of the school's curriculum (https://42luxembourg.lu/).