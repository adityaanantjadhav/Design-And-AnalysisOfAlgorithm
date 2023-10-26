#include <iostream>
using namespace std;

const int N = 10;

void display(int n, int arr[][N]) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void displayReflection(int n, int arr[][N])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

bool isSafe(int row, int col, int n, int arr[][N]) 
{
    for (int i = 0; i < row; i++) 
    {
        if (arr[i][col] == 1) 
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
    {
        if (arr[i][j] == 1) 
        {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++) 
    {
        if (arr[i][j] == 1) 
        {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int n, int arr[][N], int row) 
{
    if (row == n) 
    {
        return true;
    }

    for (int col = 0; col < n; col++) 
    {
        if (isSafe(row, col, n, arr)) 
        {
            arr[row][col] = 1;

            if (solveNQueens(n, arr, row + 1)) 
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    int arr[N][N] = {0};

    if (solveNQueens(n, arr, 0)) 
    {
        cout<<"Solution found:"<<endl;
        display(n, arr);
        cout<<"\nReflection >> "<<endl;
        displayReflection(n, arr);
    } 
    else 
    {
        cout<<"No solution exists."<<endl;
    }

    return 0;
}