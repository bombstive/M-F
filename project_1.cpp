#include <iostream> 
#include <fstream>
#include <sstream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int BARRIER = -1;
const int EMPTY = 0;
const int FULL = 1;
const int COL = 8;
const int ROW = 8;

const string UNCORRECT_ERROR = "uncorrect input";



bool lineCheker(string line)
{
    if(!(line.length() == 8))
        return false;

    for(int i = 0 ; i < 8 ; i++)
    {
        if(!(line[i] == '.' || line[i] == '*'))
            return false;
    }    

    return true;
}
void boardMaker(vector<vector<int>> &board , string line , int idx)
{
    for(int i = 0 ; i < ROW ; i++)
    {
        if(line[i] == '.')
        {
            board[idx][i] = EMPTY;
        }
        else if(line[i] == '*')
        {
            board[idx][i] =BARRIER;
        }
    }
}
void inputHandler(vector<vector<int>> &board)
{
    string line;
    for(int i = 0 ; i < 8 ; i++)
    {
        getline(cin , line);
        if(lineCheker(line) == false)
        {    
            cout << UNCORRECT_ERROR << endl;
            break;
        }

        boardMaker(board , line , i);
    }
}



bool isSafe(const std::vector<std::vector<int>> &board, int row, int col) {
    if(board[row][col] == BARRIER)
    {
        return false;
    }
    
    for (int i = 0; i < col; ++i)
    {
        if (board[row][i] == FULL)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
    {
        if (board[i][j] == FULL)
            return false;
    }

    for (int i = row, j = col; j >= 0 && i < ROW; ++i, --j)
    {
        if (board[i][j] == FULL)
            return false;
    }
    return true;
}
void solveEightQueen(vector<vector<int>> &board , int col , int &counter)
{
    if (col == COL) {
        ++counter;
        return;
    }
    for (int i = 0; i < ROW; ++i) {
        if (isSafe(board, i, col)) {
            board[i][col] = FULL;
            solveEightQueen(board, col + 1, counter);
            board[i][col] = EMPTY;
        }
    }
}



int main()
{
    vector<vector<int>> board(COL , vector<int>(ROW , 0));
    int counter = 0;

    inputHandler(board);
    solveEightQueen(board , 0 , counter);

    cout << counter << endl;
}