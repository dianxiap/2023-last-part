#include <iostream>
using namespace std;

class SymmetricMatrix {
private:
    int n;  // ����Ľ���
    int* matrix;  // �洢�Գƾ����һά����

public:
    // ���캯������������
    SymmetricMatrix(int n) : n(n) {
        matrix = new int[n * (n - 1) / 2];
        // ��ʼ������Ϊ 0
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            matrix[i] = 0;
        }
    }

    // �����������ͷ��ڴ�
    ~SymmetricMatrix() {
        delete[] matrix;
    }

    // ���ʾ���Ԫ��
    int& access(int i, int j) {
        if (i < j) {
            // ���� i �� j
            int temp = i;
            i = j;
            j = temp;
        }
        // ������һά�����е��±�λ��
        return matrix[i * (i - 1) / 2 + j];
    }

    // ��ӡ�����������Ԫ��
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

    // ʹ�� for ѭ���������Ԫ��
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            mtx.access(i, j) = count++;
        }
    }

    // ��������������Ԫ��
    mtx.printUpperTriangle();

    return 0;
}