#ifndef SOLVER_H
#define SOLVER_H
#include <QVector>
#include <QThread>

class MyThread : public QThread {
    Q_OBJECT
public:
    MyThread()
    {
    }
    void run()
    {
        exec();
    }
};

class Solver
{
public:
    Solver();

    int solve_matrix(int size, QVector<int> nums);
    void try_cell(int number);

    QVector<int> this_nums;
    int solutions;
    int n;
};

#endif // SOLVER_H
