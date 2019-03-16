#ifndef SUDOKUMATRIX_H
#define SUDOKUMATRIX_H

#include <QVector>


class SudokuMatrix
{
public:
    SudokuMatrix();
    void newMatrix();
    void transpose();
    void swap_rows();
    void swap_cols();
    void mix_matrix();
    void save_matrix();
    void delete_cells(int dif);

    QVector<int> states;
    QVector<int> numbers;
    QVector<int> saved_numbers;
    int difficulty;
    int n;
};

#endif // SUDOKUMATRIX_H
