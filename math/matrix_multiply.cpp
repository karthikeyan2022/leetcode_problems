#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include "parse.h" // parse.h is in .\util directory (see build.bat)

class Solution
{
public:
    // input : matrix A and matrix B
    // 2D array , pointer to 2D array, with M and N
    void matrixAddition(int **matrixA, int **matrixB, int m, int n)
    {
        for (int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                cout << matrixA[r][c]+matrixB[r][c] << endl;
            }
        //cout << endl;
        }
    }

    void matrixMultiply(int **matrixA, int rowA, int colA, 
                        int **matrixB, int rowB, int colB,
                        int **matrixC)
    {
        for(int i = 0; i < rowA; i++)
        {
            for(int j = 0; j < colB; j++)
            {
                // initialize C[i][j]
                matrixC[i][j] = 0;

                // loop and calculate 
                for(int k = 0; k < colA; k++) // k can be rowB also
                {
                    matrixC[i][j] += (matrixA[i][k] + matrixB[k][j]);
                }
            }
        }
    }

    void printMatrix(int **matrix, int m, int n)
    {
        for (int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                cout << matrix[r][c] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char *argv[]) {

    // Matrix A and Matrix B
    int **matrixA;
    int **matrixB;
    int **matrixC;

    int RowA, RowB, ColA, ColB;

    matrixA = (int**)malloc(RowA * sizeof(int));

    for (int i = 0; i < RowA; i++)
    {
        matrixA[i] = (int*)malloc(ColA * sizeof(int));
    }

    matrixB = (int**)malloc(RowB * sizeof(int));

    for(int i = 0; i < RowB; i++)
    {
        matrixB[i] = (int*)malloc(ColB * sizeof(int));
    }

    matrixC = (int**)malloc(RowA * sizeof(int));

    for(int i = 0; i < RowA; i++)
    {
        matrixC[i] = (int*)malloc(ColB * sizeof(int));
    }

    class Solution* sol = new Solution();

    sol->matrixMultiply(matrixA, rowA, colA, matrixB, rowB, colB, matrixC);
    sol->printMatrix(matrixC, rowA, colB);


    for(int i = 0; i < rowA; i++)
    {
        free(matrixA[i]);
        free(matrixB[i]);
        free(matrixC[i]);
    }
    free(matrixA);
    free(matrixB);
    free(matrixC);

    return 0;
}
