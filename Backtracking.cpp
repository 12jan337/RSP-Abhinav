#include <iostream>
#include <string>

using namespace std;

void printSubsets(string s, string subsets)
{

    if (s.size() == 0)
    {
        cout << subsets << "\n";
        return;
    }

    char ch = s[0];

    printSubsets(s.substr(1, s.size() - 1), subsets + ch); // case where character is included
    printSubsets(s.substr(1, s.size() - 1), subsets);      // case where character is not included
}

void permutations(string str, string ans)
{

    int n = str.size();
    if (n = 0)
    {
        cout << ans << "\n";
        return;
    };

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        string nextStr = str.substr(0, i) + str.substr(i + 1, n - i - 1);
        permutations(nextStr, ans + ch); // ith char choice to add in permutation
    }
};

void printBoard(vector<vector<char>> board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
    }
}

bool isSafe(vector<vector<char>> board, int row, int col)
{

    int n = board.size();
    // horizontal
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] = 'Q')
        {
            return false;
        }
    }
    // vertical
    for (int i = 0; i < row; i++)
    {

        if (board[i][col] = '0')
        {
            return false;
        }
    }
    // diagonal left
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    // diagonal right
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {

        if (board[i][j] = 'Q')
        {
            return false;
        }
    }

    return true;
}

void nQueens(vector<vector<char>> board, int row)
{
    int n = board.size();

    if (row == n)
    {
        printBoard(board);
        return;
    }

    for (int j = 0; j < n; j++)
    { // cols
        if (isSafe(board, row, j))
        {
            board[row][j] = 'Q';
            nQueens(board, row + 1);
            board[row][j] = '.';
        }
    }
}

bool isSafeSoduku(int sudoku[9][9], int row, int col, int digit)
{
    // vertical
    for (int i = 0; 1 <= 8; i++)
    {
        if (sudoku[i][col] == digit)
        {
            return false;
        }
    }
    // horizontal
    for (int j = 0; j <= 8; j++)
    {
        if (sudoku[row][j] == digit)
        {
            return false;
        }
    }

    // 3x3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i <= startRow + 2; i++)
    {
        for (int j = startCol; j < startCol + 2; j++)
        {
            if (sudoku[i][j] == digit)
            {
                return false;
            }
        }
    }
};

bool sudokuSolver(int sudoku[9][9], int row, int col)
{
    if (row == 9)
    {
        // sudoku •solve
        // printSudoku (sudoku) ;
        return true;
    }

    int nextRow = row;
    int nextCol = col + 1;
    if (col + 1 == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (sudoku[row][col] != 0)
    {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    for (int digit = 1; digit <= 9; digit++)
    {
        if (isSafeSoduku(sudoku, row, col, digit)){
            sudoku[row][col] = digit;
            if (sudokuSolver(sudoku, nextRow, nextCol)){
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    string s = "abc";
    string subsets = "";

    printSubsets(s, subsets);
    return 0;
}
