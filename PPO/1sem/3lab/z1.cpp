/*Измененный  массив  C1,C2,...,Cm:  каждый  элемент,  предшествующий 
минимальному,  помножен  на  него,  а  все  следующие  за  минимальным уменьшены на 1*/

#include <iostream>
#include <cstdlib>
using namespace std;

int min_element(int *arr, int n)
{
    int i, min, i_min;
    min = arr[0];
    for (i = 0; i < n; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            i_min = i;
        }
    }
    for (i = 0; i < n; ++i)
    {
        if (i < n - 1 && arr[i + 1] == min && arr[i] != min) 
        {
            arr[i] *= min; 
        }
        if (i > 0 && arr[i - 1] == min && arr[i] != min)
        {
            arr[i]--; 
        }
    }
    return min;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int i, m;
    cout << "Введите размер массива С: ";
    cin >> m;
    int *arr1 = new int [m];

    cout << "Массив С: "
         << endl;

    for (i = 0; i < m; ++i)
    {
        cin >> arr1[i];
    }

    cout << "Минимальный элемент: "
         << min_element(arr1, m) << endl;

    cout << "Измененный масив: ";
    for (i = 0; i < m; ++i)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    delete[] arr1;

    return 0;
}