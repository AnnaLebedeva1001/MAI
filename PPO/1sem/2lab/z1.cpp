#include <iostream>
#include <cstdlib>
using namespace std;

int maximum_element(int **arr, int n)
{
    int i, j, max, i_max;
    max = arr[0][0];
    for (i = 0; i < n; ++i)
    {
        if (arr[i][i] > max)
        {
            max = arr[i][i];
            i_max = i;
        }
    }
    return max;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int i, j, max, i_max;
    int n;
    cout << "Введите размер квадратной матрицы Т: ";
    cin >> n;
    int **arr1 = new int *[n];
    for (int i = 0; i < n; ++i)
        arr1[i] = new int[n];

    cout << "Матрица Т: "
         << endl;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cin >> arr1[i][j];
        }
    }

    cout << "Максимальный элемент в главной диагонали: "
         << maximum_element(arr1, n) << endl;

    for (int i = 0; i < n; ++i)
        delete[] arr1[i];
    delete[] arr1;

    int m;
    cout << "Введите размер квадратной матрицы P: ";
    cin >> m;
    int **arr2 = new int *[m];
    for (int i = 0; i < m; ++i)
        arr2[i] = new int[m];

    cout << "Матрица P: "
         << endl;

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            cin >> arr2[i][j];
        }
    }

    cout << "Максимальный элемент в главной диагонали: "
         << maximum_element(arr2, m) << endl;

    for (int i = 0; i < m; ++i)
        delete[] arr2[i];
    delete[] arr2;

    return 0;
}