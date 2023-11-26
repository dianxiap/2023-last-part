#include <iostream>
#include <vector>

class BandedMatrix {
private:
    std::vector<double> data;
    int n; // 矩阵大小
    int b; // 半带宽

public:
    BandedMatrix(int size, int bandwidth) : n(size), b(bandwidth), data(size* (2 * bandwidth + 1), 0) {}

    double& at(int i, int j) {
        if (std::abs(j - i) > b) {
            throw std::out_of_range("Indices are outside of the bandwidth");
        }
        return data[i * (2 * b + 1) + (j - i + b)]; // 计算在一维数组中的索引并返回
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
    int size = 5; // 矩阵大小
    int bandwidth = 2; // 半带宽
    BandedMatrix mat(size, bandwidth);

    // 填充一些数据
    for (int i = 0; i < size; ++i) {
        for (int j = std::max(0, i - bandwidth); j <= std::min(size - 1, i + bandwidth); ++j) {
            mat.at(i, j) = i + j;
        }
    }

    // 展示矩阵
    mat.display();

    return 0;
}