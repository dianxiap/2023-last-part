#include <iostream>
#include <vector>

class BandedMatrix {
private:
    std::vector<double> data;
    int n; // �����С
    int b; // �����

public:
    BandedMatrix(int size, int bandwidth) : n(size), b(bandwidth), data(size* (2 * bandwidth + 1), 0) {}

    double& at(int i, int j) {
        if (std::abs(j - i) > b) {
            throw std::out_of_range("Indices are outside of the bandwidth");
        }
        return data[i * (2 * b + 1) + (j - i + b)]; // ������һά�����е�����������
    }

    void display() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (std::abs(j - i) <= b) {
                    std::cout << at(i, j) << " ";
                }
                else {
                    std::cout << "0 ";
                }
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int size = 5; // �����С
    int bandwidth = 2; // �����
    BandedMatrix mat(size, bandwidth);

    // ���һЩ����
    for (int i = 0; i < size; ++i) {
        for (int j = std::max(0, i - bandwidth); j <= std::min(size - 1, i + bandwidth); ++j) {
            mat.at(i, j) = i + j;
        }
    }

    // չʾ����
    mat.display();

    return 0;
}