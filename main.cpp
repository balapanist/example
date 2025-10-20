#include <iostream>

bool catchValue(int rows, int cols) {
    return (rows > 0 && cols > 0);
}

void fillMatrix(int* mat[], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> mat[i][j];
        }
    }
}

void printMatrix(int* mat[], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "[" << mat[i][j] << "]";
        }
        std::cout << "\n";
    }
}

void printTransposed(int* transp[], int transpRows, int transpCols) {
    for (int i = 0; i < transpRows; ++i) {
        for (int j = 0; j < transpCols; ++j) {
            std::cout << "[" << transp[i][j] << "]";
        }
        std::cout << "\n";
    }
}

void freeMatrix(int** mat, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

int main() {
    int rows = 0, cols = 0;
    if (!(std::cin >> rows >> cols)) {
        return 1;
    }
    if (!catchValue(rows, cols)) {
        return 1;
    }

    int** mat = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        mat[i] = new int[cols];
    }

    int** transp = new int* [cols];
    for (int i = 0; i < cols; ++i) {
        transp[i] = new int[rows];
    }

    fillMatrix(mat, rows, cols);

    std::cout << "Исходная матрица:\n";
    printMatrix(mat, rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transp[j][i] = mat[i][j];
        }
    }

    std::cout << "Транспонированная матрица:\n";
    printTransposed(transp, cols, rows); 

    freeMatrix(mat, rows);
    freeMatrix(transp, cols);
}
