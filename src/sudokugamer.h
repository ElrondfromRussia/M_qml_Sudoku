#ifndef SUDOKUGAMER_H
#define SUDOKUGAMER_H

#include <QObject>
#include "sudokumatrix.h"
#include <QVariant>

class SudokuGamer: public QObject
{
    Q_OBJECT
public:
    explicit SudokuGamer(QObject *parent = 0);

    SudokuMatrix smatrix;
    void print_matrix();

    int difficulty;
protected:
    QObject *viewer;
signals:
    void makeit(QVariant m);
    void answer(QVariant ans);
public slots:
    void on_checking(int n, int ind);
    void on_set_diff(int n);
    void on_new_game();
};

#endif // SUDOKUGAMER_H
