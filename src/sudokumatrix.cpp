#include "sudokumatrix.h"
#include <math.h>
#include <ctime>
#include <QDebug>
#include <solver.h>

SudokuMatrix::SudokuMatrix()
{
    n = 9;
    difficulty = n*n;
}

void SudokuMatrix::newMatrix()
{
    numbers.clear();
    states.clear();
    saved_numbers.clear();
    for(int j = 0; j < n*n; j++)
    {
        int i = (j)/n;
        int res = (j % 9 + i*3 / 9 + i*3 % 9) % 9 + 1;
        numbers.append(res);
        states.append(0);
    }
}

void SudokuMatrix::transpose()
{
    int i = 1;
    int h = 1;
    int temp = 0;
    for(int j = 1; j < n*(n-1); j++)
    {
        if((j)%n == 0)
        {
            i = 1;
            h++;
            j+= h;
        }
        temp = numbers.at(j);
        numbers[j] = numbers.at(j + (n-1)*i);
        numbers[j + (n-1)*i] = temp;
        i++;
    }
}

void SudokuMatrix::swap_rows()
{
    int n1, n2;
    int temp = 0;
    int area = rand() % (3);
    int r1 = rand() % (3);
    int r2 = rand() % (3);
    while(r2 == r1)
        r2 = rand() % (3);

    n1 =  area*3 + r1;
    n2 =  area*3 + r2;

    for(int j = 0; j < n; j++)
    {
        temp = numbers.at(j + n1*n);
        numbers[j + n1*n] = numbers.at(j + n2*n);
        numbers[j + n2*n] = temp;
    }
}

void SudokuMatrix::swap_cols()
{
    transpose();
    swap_rows();
    transpose();
}

void SudokuMatrix::mix_matrix()
{
    srand(time(0));
    for(int i = 0; i < 20; i++)
    {
       int temp = rand() % (3);;
       switch (temp) {
       case 0:
           transpose();
           break;
       case 1:
           swap_rows();
           break;
       case 2:
           swap_cols();
           break;
       default:
           break;
       }
    }
    save_matrix();
}

void SudokuMatrix::save_matrix()
{
    for(int j = 0; j < n*n; j++)
    {
        saved_numbers.append(numbers.at(j));
    }
}

void SudokuMatrix::delete_cells(int dif)
{
    int iterator = 0;
    difficulty = dif;
    //Solver solver;

    while(iterator < difficulty)
    {
        int i = rand() % (n);
        int j = rand() % (n);
        if(states.at(i*n + j) == 0)
        {
            states[i*n + j] = 1;
            iterator++;
            //int temp = numbers.at(i*n + j);
            numbers[i*n + j] = 0;

            //QVector<int> solution;
            //for(int k = 0; k < numbers.length(); k++)
            //{
             //   solution.append(numbers.at(k));
            //}

            //int i_solution = 0;

            //i_solution = solver.solve_matrix(n, solution);

            //if(i_solution != 1)
            //{
              //  numbers[i*n + j] = temp;
              //  iterator--;
            //}
        }
    }
}

