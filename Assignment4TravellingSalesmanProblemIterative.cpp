#include <iostream>
using namespace std;

void printmatrix(int arr[][50], int v) // PRINTS THE MATRIX
{
    cout << endl;
    for (int m = 0; m < v; m++)
    {
        for (int n = 0; n < v; n++)
        {
            cout << "|" << arr[m][n] << " ";
            if (arr[m][n] != 9999)
                cout << "  ";
            if (arr[m][n] / 10 == 0)
                cout << " ";
            cout << "|";
        }
        cout << endl;
    }
}

int colmin(int mat[][50], int v)
{ // MINIMIZES THE COLUMNS AND RETURNS SUM OF MINIMUM VALUES
    int sum = 0;
    for (int i = 0; i < v; i++)
    {
        int min = 9999;
        for (int j = 0; j < v; j++)
        {
            if (min > mat[j][i])
            {
                min = mat[j][i];
            }
        }
        if (min != 9999)
            sum = min + sum;
        for (int j = 0; j < v; j++)
        {
            if (mat[j][i] != 9999)
                mat[j][i] = mat[j][i] - min;
        }
    }
    return sum;
}

int rowmin(int mat[][50], int v)
{ // MINIMIZES THE COLUMNS AND RETURNS SUM OF MINIMUM VALUES
    int sum = 0;
    for (int i = 0; i < v; i++)
    {
        int min = 9999;
        for (int j = 0; j < v; j++)
        {
            if (min > mat[i][j])
            {
                min = mat[i][j];
            }
        }
        if (min != 9999)
            sum = min + sum;
        for (int j = 0; j < v; j++)
        {
            if (mat[i][j] != 9999)
                mat[i][j] = mat[i][j] - min;
        }
    }
    return sum;
}

int main()
{
    int v, e, initial = 0;
    int sum = 0;
    cout << "enter the no. of vertices::";
    cin >> v;
    int mat[50][50];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            mat[i][j] = 9999;
        }
    }

    cout<<"enter the matrix values::\n";
    for (int m = 0; m < v; m++)
    {
        for (int n = 0; n < v; n++)
        {
            cout<<"row"<<m<<"column"<<n<<"::";
            cin >> mat[m][n];
        }
    }

    cout << "enter the starting point::";
    cin >> initial;

    int arr[50][50];
    int arr2[50][50];

    cout << "enter the matrix :\n";
    for (int m = 0; m < v; m++)
    {
        cout << "enter " << m + 1 << "th row:\n";
        for (int n = 0; n < v; n++)
        {
            arr[m][n] = 9999;
            arr2[m][n] = 9999;
        }
    }

    int visited[v]; // KEEPS TRACK OF VISITED VERTICES
    int route[v];   // KEEPS TRACK OF ROUTE

    for (int i = 0; i < v; i++)
    { // INITIALIZING ALL VERTEX NOT VISITED EXCEPT INITIAL
        visited[i] = 0;
    }
    visited[initial] = 1;

    cout << "row minimization:\n";
    sum += rowmin(mat, v);
    printmatrix(mat, v);

    cout << "column minimization:\n";
    sum += colmin(mat, v);
    printmatrix(mat, v);

    cout << "\n cost is:" << sum << endl
         << endl;

    int start = initial;
    int sum1 = 0;
    int b = 0;

    for (int e = 0; e < v; e++)
    { // looping v times to visit all vertices and return to initial vertex
        if (e == v - 1)
            visited[initial] = 0; // we can visit initial vertex only at end

        int min = 999999;
        int minpoint;
        for (int i = 0; i < v; i++)
        {
            if (i != start && visited[i] == 0)
            {
                for (int l = 0; l < v; l++)
                { // initialising another matrix arr as original matrix
                    for (int m = 0; m < v; m++)
                    {
                        arr[l][m] = mat[l][m];
                    }
                }
                for (int l = 0; l < v; l++)
                { // making the row and column infinite
                    arr[start][l] = 9999;
                    arr[l][i] = 9999;
                }
                arr[i][start] = 9999;

                printmatrix(arr, v);

                sum1 = rowmin(arr, v);
                sum1 = sum1 + sum + colmin(arr, v) + mat[start][i]; // storing cost into sum1
                cout << "cost of " << start << " to " << i << ":: " << sum1 << endl;

                if (min > sum1)
                { // finding the vertex with minimum cost
                    min = sum1;
                    minpoint = i;
                    for (int l = 0; l < v; l++)
                    {
                        for (int m = 0; m < v; m++)
                        {
                            arr2[l][m] = arr[l][m]; // storing the matrix of minimum cost into another matrix
                        }
                    }
                }
            }
        }
        cout << "\nfinal minimum cost b/w " << start << " to " << minpoint << " is::" << min << endl;
        start = minpoint;
        visited[start] = 1;
        route[b++] = start;
        sum = min;
        for (int i = 0; i < v; i++)
        { // making the matrix with minimum cost as original matrix
            for (int j = 0; j < v; j++)
            {
                mat[i][j] = arr2[i][j];
            }
        }
    }
    cout << endl
         << "path is::\n"
         << initial;
    for (int i = 0; i < v; i++)
    {
        cout << " -> " << route[i];
    }
}