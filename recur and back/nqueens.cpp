#include <bits/stdc++.h>
using namespace std;

void print_board(int n, int board[][20])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool can_place(int board[][20], int n, int x, int y)
{
    for (int k = 0; k < x; k++)
    {
        if (board[k][y] == 1)
        {
            return false;
            ;
        }
    }
    int i = x;
    int j = y;
    while (i >= 0 and j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }

    while (i >= 0 and j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }

        i--;
        j++;
    }

    return true;
}

bool n_queens(int n, int board[][20], int i)
{
    if (i == n)
    {
        print_board(n, board);
        return true;
    }

    for (int j = 0; j < n; j++)
    {
        if (can_place(board, n, i, j))
        {
            board[i][j] = 1;
            bool success = n_queens(n, board, i + 1);

            if (success)
            {
                return true;
            }
            board[i][j] = 0;
        }
    }

    return false;
}

int n_queens_ways(int n, int board[][20], int i)
{
    if (i == n)
    {
        return 1;
    }


    int ways = 0;

    for (int j = 0; j < n; j++)
    {
        if (can_place(board, n, i, j))
        {
            board[i][j] = 1;

            ways += n_queens_ways(n, board, i + 1);

            board[i][j] = 0;
        }
    }

    return ways;
}

int main(int argc, char const *argv[])
{
    int board[][20] = {0};

    int n;
    cin >> n;

    // n_queens(n,board,0);

    cout << n_queens_ways(n, board, 0);

    return 0;
}
