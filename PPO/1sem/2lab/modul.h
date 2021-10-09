#pragma once
#include <iostream>

int** matrix_init(int n, int m)
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) 
	{
		arr[i] = new int[m];
	}

	return arr;
}

void zero_matrix(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
		{
			a[i][j] = 0;
		}
}

bool group_average_score(int** arr, int n, int m)
{
    int i, j;
    double score = 0, count = 0;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            score += arr[i][j];
            count++;
        }
    }
    if (score / count >= 4) return true;
    else false;
}

bool check_for_2(int** arr, int n, int m)
{
    int i, j;
    bool flag;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if (arr[i][j] == 2)
            {
                flag = false;
                break;
            }
            else
                flag = true;
        }
    }
    return flag;
}

bool check_for_3(int** arr, int n, int m)
{
    int i, j;
    double cout_trinity = 0, count_students = m;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if (arr[i][j] == 3)
            {
                cout_trinity++;
                break;
            }
        }
    }
    if (count_students - cout_trinity >= count_students / 2) return true;
    else return false;
}

