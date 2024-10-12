#include <bits/stdc++.h>
using namespace std;

bool is_safe(int mat[][9], int i, int j, int no, int n)
{   for(int k=0;k<n;k++){
    if(mat[k][j]==no or mat[i][k]==no){
        return false;
    }
    int sx=(i/3)*3;
    int sy=(j/3)*3;

    for(int x=sx;x<sx+3;x++){
        for(int y=sy;y<sy+3;y++){
            if(mat[x][y]==no){
                return false;
            }
        }
    }
}
    return true;
}

bool solve_sudoku(int mat[][9], int i, int j, int n)
{
    if (i == n)
    {   for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
        return true;
    }
    if (j == n)
    {
        return solve_sudoku(mat, i + 1, 0, n);
    }
    if (mat[i][j] != 0)
    {
        return solve_sudoku(mat, i, j + 1, n);
    }
    for (int no = 1; no <= n; no++)
    {
        if (is_safe(mat, i, j, no, n))
        {
            mat[i][j] = no;
            bool success = solve_sudoku(mat, i, j + 1, n);
            if (success)
            {
                return true;
            }
        }
    }

    mat[i][j] = 0;
    return false;
}

int main(int argc, char const *argv[])
{
    int n = 9;
    int mat[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (!solve_sudoku(mat, 0, 0, n))
    {
        cout <<"No solution exists!" << endl;
    }
    else {
        cout<<"le re lund ke, ye tera solution, maa ka bhosda aise question ki"<<endl;
    }
    return 0;
}
