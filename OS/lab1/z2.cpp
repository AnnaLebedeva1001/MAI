#include <iostream>
#include <string.h>
using namespace std;
 
int main()
{
 
    char A[80];
    char end_open_skobka; 
    char stack[80];
    int pos = -1;
 
    cout << "Введите текст: " << endl;
    cin.getline(A, 80);
 
    int round, figured, squared;
 
    round = figured = squared = 0;
 
    for (int i=0; i<strlen(A); i++)
    {
        if (A[i] == '(') round++;   
        else
        if (A[i] == ')') round--;     
        else
        if (A[i] == '{') figured++;
        else
        if (A[i] == '}') figured--;
        else
        if (A[i] == '[') squared++;  
        else
        if (A[i] == ']') squared--;     
 
        if ( (A[i] == '(') || (A[i] == '{') || (A[i] == '[') )
        {
            end_open_skobka = A[i];          
            pos++;                     
            stack[pos] = A[i];         
        }
 
        if (round<0 || figured<0 || squared<0)
        {
            cout << "Лишняя закрывающая скобка" << endl;
            break;
        }
 
        if ( ((A[i] == ')') && (end_open_skobka != '('))  ||
             ((A[i] == '}') && (end_open_skobka != '{'))  ||
             ((A[i] == ']') && (end_open_skobka != '[')) )
        {
            cout << "Закрывающая скобка другого типа" << endl;
            break;
        }
 
        if ( (A[i] == ')') || (A[i] == '}') || (A[i] == ']') )
        {
            pos--;                           
            if (pos>=0)
                end_open_skobka = stack[pos];
        }
 
 
    }
 
    if (round || figured || squared)
        cout << "Скобки расставлены неправильно" << endl;
    else
        cout << "Скобки расставлены правильно" << endl;
 
 
    return 0;
}