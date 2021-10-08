#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void filling_matrix(double **matrix, int rowscount, int columnscount)
{
    for (int i = 0; i < rowscount; i++)
    {
        for (int j = 0; j < columnscount; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }
}

void print_matrix(double **matrix, int rowscount, int columnscount)
{
    int i, j;
    for (i = 0; i < rowscount; i++)
    {
        for (j = 0; j < columnscount; j++)
        {
            printf("%.1f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_cleaning(double **a, int rowscount)
{
    for (int i = 0; i < rowscount; i++)
        free(a[i]);
    free(a);
}

double determinant(double **a, int n)
{
    int i = 0, j = 0, k = 0, l = 0;
    double det;
    while (k < n - 1)
    {
        while (i < n)
        {
            det = a[i][j] / a[k][l];
            while (j < n)
            {
                a[i][j] += (-det) * a[k][j];
                j++;
            }
            j = l;
            i++;
        }
        k++;
        l++;
        i = k + 1;
        j = l;
    }
    det = 1;
    i = 0;
    while (i < n)
    {
        det = a[i][i] * det;
        i++;
    }
    return det;
}

int main()
{
    int i, j, n, k;
    srand(time(NULL));
    double **matrix1, **matrix2, **matrix3;
    int rowscount1 = rand() % 4 + 5;
    int columnscount1 = rand() % 4 + 5;
    int rowscount2 = rand() % 4 + 5;
    int columnscount2 = rand() % 4 + 5;
    matrix1 = (double **)malloc(rowscount1 * sizeof(double *));
    for (i = 0; i < rowscount1; i++)
        matrix1[i] = (double *)malloc(columnscount1 * sizeof(double));

    filling_matrix(matrix1, rowscount1, columnscount1);
    printf("Matrix 1:\n");
    print_matrix(matrix1, rowscount1, columnscount1);

    matrix2 = (double **)malloc(rowscount2 * sizeof(double *));
    for (i = 0; i < rowscount2; i++)
        matrix2[i] = (double *)malloc(columnscount2 * sizeof(double));
    filling_matrix(matrix2, rowscount2, columnscount2);
    printf("Matrix 2:\n");
    print_matrix(matrix2, rowscount2, columnscount2);

    double cell_result = 0;
    matrix3 = (double **)malloc(sizeof(sizeof(double *) * rowscount1));
    if (columnscount1 == rowscount2)
    {
        k = columnscount1 = rowscount2;
        for (i = 0; i < rowscount1; i++)
        {
            matrix3[i] = (double *)malloc(sizeof(double) * columnscount2);
            for (int j = 0; j < columnscount2; j++)
            {
                for (int k = 0; k < rowscount2; k++)
                {
                    cell_result += matrix1[i][k] * matrix2[k][j];
                }
                matrix3[i][j] = cell_result;
                cell_result = 0;
            }
        }
        printf("Matrix 1*2:\n");
        for (int i = 0; i < rowscount1; i++)
        {
            for (int j = 0; j < columnscount2; j++)
            {
                printf("%1.1f ", matrix3[i][j]);
            }
            printf("\n");
        }
    }
    else
        printf("Матрицы не перемножаются!!!!!!!\n");

    if (rowscount1 == columnscount1)
    {
        n = rowscount1 = columnscount1;
        printf("Определитель матрицы 1 = %1.1f\n", determinant(matrix1, n));
    }
    else
        printf("Невозможно найти определитель!!!\n");

    if (rowscount2 == columnscount2)
    {
        n = rowscount2 = columnscount2;
        printf("Определитель матрицы 2 = %1.1f\n", determinant(matrix2, n));
    }
    else
        printf("Невозможно найти определитель!!!\n");

    matrix_cleaning(matrix1, rowscount1);
    matrix_cleaning(matrix2, rowscount2);
    return 0;
}