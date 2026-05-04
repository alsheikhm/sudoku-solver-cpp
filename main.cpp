// Mohammed Al-Sheikh
// main.cpp

#include <iostream>
#include <vector>

// Prints a 9x9 Sudoku grid
void PrintNineByNineGrid(const std::vector<int>& grid)
{
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            std::cout << grid[(i * 9) + j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

// Checks if a row, column, box, or diagonal is legal
bool IsLegalGroup(const std::vector<int>& group)
{
    std::vector<int> occurrences(9 + 1, 0);

    for(const int& value : group)
    {
        if(value < 0 || value > 9)
        {
            return false;
        }

        ++occurrences[value];
    }

    // Start at 1 because 0 represents an empty space and duplicates of 0 are allowed
    for(int i = 1; i <= 9; ++i)
    {
        if(occurrences[i] > 1)
        {
            return false;
        }
    }

    return true;
}

// Checks all normal Sudoku rules: rows, columns, and 3x3 boxes
bool IsNineByNineSudokuLegal(const std::vector<int>& grid, bool useDiagonals)
{
    // Check all rows
    for(int row = 0; row < 9; ++row)
    {
        std::vector<int> group;

        for(int col = 0; col < 9; ++col)
        {
            group.push_back(grid[(row * 9) + col]);
        }

        if(IsLegalGroup(group) == false)
        {
            return false;
        }
    }

    // Check all columns
    for(int col = 0; col < 9; ++col)
    {
        std::vector<int> group;

        for(int row = 0; row < 9; ++row)
        {
            group.push_back(grid[(row * 9) + col]);
        }

        if(IsLegalGroup(group) == false)
        {
            return false;
        }
    }

    // Check all 3x3 boxes
    for(int boxRow = 0; boxRow < 9; boxRow += 3)
    {
        for(int boxCol = 0; boxCol < 9; boxCol += 3)
        {
            std::vector<int> group;

            for(int row = boxRow; row < boxRow + 3; ++row)
            {
                for(int col = boxCol; col < boxCol + 3; ++col)
                {
                    group.push_back(grid[(row * 9) + col]);
                }
            }

            if(IsLegalGroup(group) == false)
            {
                return false;
            }
        }
    }

    // Check diagonals only for the second puzzle
    if(useDiagonals == true)
    {
        std::vector<int> leftDiagonal;
        std::vector<int> rightDiagonal;

        for(int i = 0; i < 9; ++i)
        {
            leftDiagonal.push_back(grid[(i * 9) + i]);
            rightDiagonal.push_back(grid[(i * 9) + (9 - 1 - i)]);
        }

        if(IsLegalGroup(leftDiagonal) == false || IsLegalGroup(rightDiagonal) == false)
        {
            return false;
        }
    }

    return true;
}

// Recursive function that solves the Sudoku puzzle
bool SolveSudoku(std::vector<int>& grid, const std::vector<bool>& fixedSpaces, int index, bool useDiagonals)
{
    if(index == 81)
    {
        PrintNineByNineGrid(grid);
        return true;
    }

    // If this space was given in the original puzzle, skip it
    if(fixedSpaces[index] == true)
    {
        return SolveSudoku(grid, fixedSpaces, index + 1, useDiagonals);
    }

    for(int value = 1; value <= 9; ++value)
    {
        grid[index] = value;

        if(IsNineByNineSudokuLegal(grid, useDiagonals) == true)
        {
            if(SolveSudoku(grid, fixedSpaces, index + 1, useDiagonals) == true)
            {
                return true;
            }
        }
    }

    grid[index] = 0;
    return false;
}

// Creates the fixedSpaces vector so original puzzle values cannot be changed
std::vector<bool> FindFixedSpaces(const std::vector<int>& grid)
{
    std::vector<bool> fixedSpaces(81, false);

    for(int i = 0; i < 81; ++i)
    {
        if(grid[i] != 0)
        {
            fixedSpaces[i] = true;
        }
    }

    return fixedSpaces;
}

int main()
{
    std::cout << "Puzzle 1: Normal 9x9 Sudoku" << std::endl;

    std::vector<int> puzzle1
    {
        8, 7, 6, 9, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 6, 0, 0, 0,
        0, 4, 0, 3, 0, 5, 8, 0, 0,
        4, 0, 0, 0, 0, 0, 2, 1, 0,
        0, 9, 0, 5, 0, 0, 0, 0, 0,
        0, 5, 0, 0, 4, 0, 3, 0, 6,
        0, 2, 9, 0, 0, 0, 0, 0, 8,
        0, 0, 4, 6, 9, 0, 1, 7, 3,
        0, 0, 0, 0, 0, 1, 0, 0, 4
    };

    std::vector<bool> fixedSpaces1 = FindFixedSpaces(puzzle1);
    SolveSudoku(puzzle1, fixedSpaces1, 0, false);

    std::cout << "Puzzle 2: Diagonal 9x9 Sudoku" << std::endl;

    std::vector<int> puzzle2
    {
        4, 1, 6, 3, 0, 0, 9, 0, 5,
        0, 7, 3, 4, 9, 0, 0, 0, 8,
        0, 8, 0, 7, 0, 0, 0, 0, 0,
        0, 0, 1, 0, 0, 0, 0, 5, 9,
        0, 0, 0, 0, 1, 0, 8, 3, 7,
        0, 0, 0, 0, 3, 0, 4, 0, 0,
        0, 0, 4, 8, 0, 0, 0, 9, 0,
        0, 0, 0, 0, 4, 3, 0, 8, 0,
        7, 0, 0, 0, 0, 0, 0, 4, 0
    };

    std::vector<bool> fixedSpaces2 = FindFixedSpaces(puzzle2);
    SolveSudoku(puzzle2, fixedSpaces2, 0, true);

    return 0;
}
