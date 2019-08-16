// Напишите функцию, которая принимает на вход целочисленную матрицу M (другими словами, просто двумерный целочисленный массив) размера rows×cols, и 
// возвращает транспонированную матрицу MT (тоже двумерный целочисленный массив) размера cols×rows. Если в M на пересечении i-ой строки и j-ого столбца 
// стояло число x, то на пересечении  j-ой строки и i-ого столбца в матрице MT тоже будет стоять число x, или другими словами MT[j][i]=M[i][j].

// Обратите внимание, что вам неизвестно, каким именно способом выделялась память для массива M.
// Выделять память под массив MT можете любым удобным вам способом. Изменять исходную матрицу нельзя.

// Требования к реализации: при выполнении этого задания вы можете определять любые вспомогательные функции. Вводить или выводить что-либо не нужно. 
// Реализовывать функцию main не нужно.


int ** create_2dmatrix(unsigned rows, unsigned cols) {
    int **m = new int * [rows];
    m[0] = new int [rows * cols];
    for (auto i = 1; i < rows; ++i)
        m[i] = m[i - 1] + cols;
    return m;
}

int ** transpose(const int * const * m, int rows, int cols) {
    int **m_t = create_2dmatrix(cols, rows);
    for (auto i = 0; i < rows; ++i)
        for (auto j = 0; j < cols; ++j)
            m_t[j][i] = m[i][j];
    return m_t;
}