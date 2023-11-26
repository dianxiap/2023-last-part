#include <iostream>
using namespace std;

class SymmetricMatrix {
private:
    int n;  // 矩阵的阶数
    int* matrix;  // 存储对称矩阵的一维数组

public:
    // 构造函数，创建矩阵
    SymmetricMatrix(int n) : n(n) {
        matrix = new int[n * (n - 1) / 2];
        // 初始化矩阵为 0
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            matrix[i] = 0;
        }
    }

    // 析构函数，释放内存
    ~SymmetricMatrix() {
        delete[] matrix;
    }

    // 访问矩阵元素
    int& access(int i, int j) {
        if (i < j) {
            // 交换 i 和 j
            int temp = i;
            i = j;
            j = temp;
        }
        // 计算在一维数组中的下标位置
        return matrix[i * (i - 1) / 2 + j];
    }

    // 打印矩阵的上三角元素
    void printUpperTriangle() 
    {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cout << access(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 4;
    SymmetricMatrix mtx(n);

    // 使用 for 循环插入矩阵元素
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            mtx.access(i, j) = count++;
        }
    }

    // 输出矩阵的上三角元素
    mtx.printUpperTriangle();

    return 0;
}