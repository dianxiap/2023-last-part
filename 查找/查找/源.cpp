#include <iostream>
#include <vector>

// �۰���Һ���
int BinarySearch(const std::vector<int>& sorted_vec, int value) {
    int left = 0;
    int right = sorted_vec.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (sorted_vec[middle] == value) {
            // �ҵ�ֵ�����ض�Ӧ������
            return middle;
        }
        else if (sorted_vec[middle] < value) {
            // �м��ֵ��Ŀ��ֵС�������Ұ벿��
            left = middle + 1;
        }
        else {
            // �м��ֵ��Ŀ��ֵ��������벿��
            right = middle - 1;
        }
    }

    // û���ҵ�ֵ
    return -1;
}

int main() {
    std::vector<int> sorted_vec{ 1, 3, 4, 6, 8, 9, 11, 13, 15, 17 };
    int value = 9;

    // �����۰����
    int index = BinarySearch(sorted_vec, value);
    if (index != -1) {
        std::cout << "Value " << value << " found at index " << index << std::endl;
    }
    else {
        std::cout << "Value " << value << " not found." << std::endl;
    }

    return 0;
}