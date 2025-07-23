#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    long long res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

void pascalTriangle(int n)
{
    int ans[10][10] = {0}; 
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= row; col++)
        {
            ans[row - 1][col - 1] = nCr(row - 1, col - 1);
        }
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= row; col++)
        {
            cout << ans[row][col] << " ";
        }
        cout << "\n";
    }
}

void main()
{
    int n = 5;
    pascalTriangle(n);
}
