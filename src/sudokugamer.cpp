#include "sudokugamer.h"
#include <QDebug>

SudokuGamer::SudokuGamer(QObject *parent ):
    viewer(parent)
{
    difficulty = 20;
    smatrix.newMatrix();
    connect(this, SIGNAL(makeit(QVariant)), viewer, SLOT(fill_field(QVariant)));
    connect(viewer, SIGNAL(check_matr(int, int)), this, SLOT(on_checking(int, int)));
    connect(viewer, SIGNAL(set_diff(int)), this, SLOT(on_set_diff(int)));
    connect(viewer, SIGNAL(new_game()), this, SLOT(on_new_game()));
    connect(this, SIGNAL(answer(QVariant)), viewer, SLOT(get_send_cheker(QVariant)));

    smatrix.mix_matrix();
    print_matrix();
    smatrix.delete_cells(difficulty);
    for(int j = 0; j < smatrix.n * smatrix.n; j++)
    {
        if(smatrix.numbers.at(j) != 0)
            makeit(QVariant(QString("%1").arg(smatrix.numbers.at(j))));
        else
            makeit(QVariant(" "));
    }
}

void SudokuGamer::print_matrix()
{
    QString res = "";
    for(int j = 0; j < smatrix.n * smatrix.n; j++)
    {
        res.append(QString("%1").arg(smatrix.numbers.at(j))).append(" ");
        if( (j+1) % 9 == 0)
        {
            qDebug() << res;
            res = "";
        }
    }
}

void SudokuGamer::on_checking(int n, int ind)
{
    if(smatrix.saved_numbers.at(ind) == n)
        answer(QVariant("true"));
    else
        answer(QVariant("false"));
}

void SudokuGamer::on_set_diff(int n)
{
    difficulty = n;
    on_new_game();
}

void SudokuGamer::on_new_game()
{
    smatrix.newMatrix();

    smatrix.mix_matrix();
    print_matrix();
    smatrix.delete_cells(difficulty);
    for(int j = 0; j < smatrix.n * smatrix.n; j++)
    {
        if(smatrix.numbers.at(j) != 0)
            makeit(QVariant(QString("%1").arg(smatrix.numbers.at(j))));
        else
            makeit(QVariant(" "));
    }
}

