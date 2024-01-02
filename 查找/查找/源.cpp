#include <iostream>
#include <vector>

// 折半查找函数
int BinarySearch(const std::vector<int>& sorted_vec, int value) {
    int left = 0;
    int right = sorted_vec.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (sorted_vec[middle] == value) {
            // 找到值，返回对应的索引
            return middle;
        }
        else if (sorted_vec[middle] < value) {
            // 中间的值比目标值小，搜索右半部分
            left = middle + 1;
        }
        else {
            // 中间的值比目标值大，搜索左半部分
            right = middle - 1;
        }
    }

    // 没有找到值
    return -1;
}

int main() {
    std::vector<int> sorted_vec{ 1, 3, 4, 6, 8, 9, 11, 13, 15, 17 };
    int value = 9;

    // 有序折半查找
    int index = BinarySearch(sorted_vec, value);
    if (index != -1) {
        std::cout << "Value " << value << " found at index " << index << std::endl;
    }
    else {
        std::cout << "Value " << value << " not found." << std::endl;
    }

    return 0;
}