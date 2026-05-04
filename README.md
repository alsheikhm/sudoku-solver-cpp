# sudoku-solver-cpp
Sudoku Solver

## Overview
This project implements a recursive 9x9 Sudoku solver in C++. The program solves both a standard Sudoku puzzle and a diagonal Sudoku puzzle, where the two main diagonals must also contain the digits 1 through 9 without repetition.

The goal of the project is to create a full-solving algorithm for 9x9 sudoku boards while preserving fixed puzzle values and applying the correct rules for each puzzle type. The program uses recursive backtracking, legality checks, and grid validation to find and display completed solutions.

## Features

- Standard 9x9 Sudoku solving
  - Solves a traditional Sudoku puzzle using row, column, and 3x3 box constraints
  - Preserves original puzzle values so they cannot be modified

- Diagonal Sudoku support
  - Adds diagonal validation for puzzles with extra rules
  - Checks both main diagonals as additional Sudoku groups

- Recursive backtracking
  - Attempts values from 1 through 9 in empty spaces
  - Backtracks when a value leads to an invalid board state

- Grid validation system
  - Validates rows, columns, 3x3 boxes, and optional diagonals
  - Allows zeroes to represent empty spaces during solving

- Fixed-space tracking
  - Uses a `vector<bool>` to identify original puzzle values
  - Skips fixed cells during recursive solving

## How It Works

1. The program stores each Sudoku puzzle in a one-dimensional `vector<int>` of 81 values.
2. Empty spaces are represented using `0`.
3. A separate `fixedSpaces` vector records which values came from the original puzzle.
4. The solver moves through the grid one index at a time.
5. If a space is fixed, the solver skips it and moves to the next position.
6. If a space is empty, the solver tries values from 1 to 9.
7. After each attempted value, the program checks whether the board is still legal.
8. If the board is legal, recursion continues to the next space.
9. If no value works, the function resets the space to `0` and backtracks.
10. Once all 81 spaces are filled legally, the completed grid is printed.

## Example Output

```text
Puzzle 1: Normal 9x9 Sudoku
8 7 6 9 ... 
...

Puzzle 2: Diagonal 9x9 Sudoku
4 1 6 3 ...
...
```

## Key Concepts Demonstrated

- **Recursive Backtracking**  
  Uses recursion to explore possible values and backtrack when a choice leads to an invalid solution.

- **Constraint Checking**  
  Validates rows, columns, boxes, and diagonals to ensure each puzzle follows the correct rules.

- **Grid Representation**  
  Stores a 9x9 Sudoku board in a one-dimensional vector and accesses cells using index calculations.

- **Fixed Value Protection**  
  Tracks original puzzle values so they remain unchanged during solving.

- **Algorithmic Problem Solving**  
  Breaks a complex puzzle into smaller decisions that can be tested recursively.

- **Use of STL Containers**  
  Uses `vector<int>` and `vector<bool>` to store puzzle data and fixed cell information.

## Design Highlights

- **Reusable Validation Logic**  
  The same legality-checking function supports both standard and diagonal Sudoku by using a boolean flag.

- **Clear Solver Structure**  
  The recursive solver separates fixed-cell handling, value testing, validation, and backtracking.

- **Flexible Puzzle Support**  
  The program can solve different Sudoku rule sets by adjusting whether diagonal constraints are enabled.

- **Readable Output Formatting**  
  A dedicated print function displays the completed Sudoku grid in a clean 9x9 layout.

## File Structure

- **Source Files**
  - `main.cpp` — Contains the Sudoku grids, validation logic, recursive solver, and output formatting

## Summary

This project implements a full 9x9 Sudoku solver using recursive backtracking and rule-based validation. By supporting both standard and diagonal Sudoku puzzles, the program demonstrates how a solver can be extended to handle additional constraints while maintaining a clean and organized structure.

# How to Run

1. **Place all files in the same directory**
   - Source file (`.cpp`)

2. **Compile the program**
   ```bash
   g++ -std=c++17 main.cpp -o sudoku_solver

3. **Run the Executable**
   ```bash
   ./sudoku_solver
