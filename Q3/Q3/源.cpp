#include <iostream>
#include <vector>
#include <algorithm>

struct Triple {
    int row, col;
    int value;
};

class SparseMatrix {
public:
    int rows, cols;
    std::vector<Triple> triples;

    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void insert(int r, int c, int value) {
        if (value != 0) {
            triples.push_back({ r, c, value });
        }
    }

    SparseMatrix fastTranspose() {
        SparseMatrix transposed(cols, rows);
        std::vector<int> rowSize(cols, 0);
        std::vector<int> rowStart(cols, 0);

        for (auto& trip : triples) {
            rowSize[trip.col]++;
        }

        int start = 0;
        for (int i = 0; i < cols; ++i) {
            rowStart[i] = start;
            start += rowSize[i];
        }

        for (auto& trip : triples) {
            int index = rowStart[trip.col]++;
            transposed.triples.push_back({ trip.col, trip.row, trip.value });
        }

        return transposed;
    }

    void print() {
        std::cout << "Row\tColumn\tValue\n";
        for (auto& trip : triples) {
            std::cout << trip.row << '\t' << trip.col << '\t' << trip.value << '\n';
        }
    }
};

int main() {
    int rows, cols, numElements;

    std::cout << "Enter the number of rows and columns for the sparse matrix: ";
    std::cin >> rows >> cols;

    SparseMatrix sm(rows, cols);

    std::cout << "Enter the number of non-zero elements: ";
    std::cin >> numElements;

    std::cout << "Enter the row index, column index, and value of each non-zero element:\n";
    for (int i = 0; i < numElements; ++i) {
        int r, c, value;
        std::cin >> r >> c >> value;
        sm.insert(r, c, value);
    }

    std::cout << "\nOriginal Sparse Matrix:\n";
    sm.print();

    SparseMatrix transposed = sm.fastTranspose();

    std::cout << "\nTransposed Sparse Matrix:\n";
    transposed.print();

    return 0;
}