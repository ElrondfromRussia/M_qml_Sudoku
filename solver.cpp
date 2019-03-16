#include "solver.h"
#include <QException>
#include <QDebug>


Solver::Solver()
{
    solutions = 0;
    n = 0;
}

int Solver::solve_matrix(int size, QVector<int> nums)
{
    this_nums.clear();
    this_nums.append(nums);
    solutions = 0;
    n = size;
    try_cell(0);
    return solutions;
}

void Solver::try_cell(int number)
{
    if(number == n*n)
    {
        solutions = 1;
        return;
    }
    if(this_nums.at(number) == 0)
    {
        int has = 0;
        for(int k = 0; k < n; k++)
        {
            bool ok = true;
            for(int u = 0; u < n; u++)
            {
                if(this_nums.at(number%n + u) == k)
                {
                    ok = false;
                    break;

                }
            }
            for(int u = 0; u < n; u++)
            {
                if(this_nums.at(number/n + u) == k)
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
               this_nums[number] = k;
               has = 1;
               try_cell(number + 1);
            }
            else
                has = 0;
        }
        return;
    }
    else
    {
        try_cell(number + 1);
    }
}

