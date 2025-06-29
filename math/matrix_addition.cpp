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

    // get the testcase from txt file
    FILE *fp = parseFileByFstream(argv[0]);

    if (fp == NULL) {
        cout << "Error opening the file!!" << endl;
        return 1;
    }
    // based on the txt file, get the row and column
    char buffer[256];
    vector <string> matrixRows;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // printf("%s", buffer);

        int c = 0;
        string str;
        while(buffer[c] != '\0')
        {
            str.push_back(buffer[c]);
            c++;
        }

        if (str.size() > 0)
        {
            matrixRows.push_back(str);
            cout << str << endl;
        }   
    }

    fclose(fp);

    int rows = 0;
    string str = matrixRows[0];
    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == ']')
            break;

        if(str[i] >= '0' && str[i] <= '9')
        {
            rows++;
        }
    }
    int cols = matrixRows.size();

    cout << "Rows : " << rows << endl;
    cout << "Columns : " << cols << endl;



    int **arr1;
    int **arr2;

    arr1 = (int**)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++)
    {
        cout << &arr1[i] << endl;
    }
    arr2 = (int**)malloc(rows * sizeof(int));

    for(int i = 0; i < rows; i++)
    {
        arr1[i] = (int*)malloc(cols * sizeof(int));
        arr2[i] = (int*)malloc(cols * sizeof(int));
    }

    int **ptr = arr1;

    for(int row = 0; row < 3; row++)
    {
        int col = 0;
        ptr = arr1;

        for(int i = 0; i < matrixRows[row].size(); i++)
        {          
            string str = matrixRows[row];
            
            if(str[i] >= '0' && str[i] <= '9')
            {          
                ptr[row][col] = str[i] - '0';
                col++;
            }
            else {
                
                if(str[i] == '[')
                {
                    col = 0;
                }
                else if(str[i] == ']')
                {
                    col = 0;
                    ptr = arr2;
                }
            }
        }
    }

    class Solution* sol = new Solution();
    sol->printMatrix(arr1, rows, cols);
    sol->printMatrix(arr2, rows, cols);

    sol->matrixAddition(arr1, arr2, rows, cols);

    for(int i = 0; i < rows; i++)
    {
        free(arr1[i]);
        free(arr2[i]);
    }
    free(arr1);
    free(arr2);

    return 0;
}
