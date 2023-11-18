#include <iostream>
#include <cstring>

class Block {
public:
    char data[4];
    Block* next;

    Block() {
        std::memset(data, '\0', 4);
        next = nullptr;
    }
};

class BlockChainString {
private:
    Block* head;

public:
    BlockChainString() {
        head = new Block();
    }

    ~BlockChainString() {
        Block* current = head;
        while (current != nullptr) {
            Block* next = current->next;
            delete current;
            current = next;
        }
    }

    BlockChainString(const BlockChainString& other) {
        head = new Block();
        Block* current = head;
        Block* otherCurrent = other.head;
        while (otherCurrent != nullptr) {
            std::memcpy(current->data, otherCurrent->data, 4);
            if (otherCurrent->next != nullptr) {
                current->next = new Block();
                current = current->next;
            }
            otherCurrent = otherCurrent->next;
        }
    }

    BlockChainString& operator=(const BlockChainString& other) {
        if (this == &other) {
            return *this;
        }

        Block* current = head;
        while (current != nullptr) {
            Block* next = current->next;
            delete current;
            current = next;
        }

        head = new Block();
        current = head;
        Block* otherCurrent = other.head;
        while (otherCurrent != nullptr) {
            std::memcpy(current->data, otherCurrent->data, 4);
            if (otherCurrent->next != nullptr) {
                current->next = new Block();
                current = current->next;
            }
            otherCurrent = otherCurrent->next;
        }

        return *this;
    }

    void insert(int index, const char* str) {
        Block* current = head;
        int currentIndex = 0;
        int length = std::strlen(str);
        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        if (currentIndex == index) {
            for (int i = 0; i < 4 && *str != '\0'; i++) {
                current->data[i] = *str++;
            }
            for (int i = 4; i < length; i += 4) {
                current->next = new Block();
                current = current->next;
                for (int j = 0; j < 4 && *str != '\0'; j++) {
                    current->data[j] = *str++;
                }
            }
        }
    }

    void remove(int index, int length) {
        Block* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < index) {
            current = current->next;
            currentIndex++;
        }
        if (currentIndex == index) {
            int offset = 0;
            while (current != nullptr && offset < length) {
                if (current->data[offset] != '\0') {
                    current->data[offset] = '\0';
                    offset++;
                }
                else {
                    Block* temp = current;
                    current = current->next;
                    delete temp;
                    offset = 0;
                }
            }
        }
    }

    int Strindex(const BlockChainString& substr) {
        Block* current = head;
        int index = 0;
        while (current != nullptr) {
            int i = 0;
            while (i < 4 && current->data[i] != '\0') {
                int j = 0;
                while (j < 4 && substr.head->data[j] != '\0') {
                    if (current->data[i + j] != substr.head->data[j]) {
                        break;
                    }
                    j++;
                }
                if (substr.head->data[j] == '\0') {
                    return index;
                }
                i++;
            }
            current = current->next;
            index += i;
        }
        return -1;
    }

    void StrReplace(int index, int length, const char* replacement) {
        remove(index, length);
        std::string tempStr(replacement);
        BlockChainString temp;
        temp.insert(0, tempStr.c_str());
    }
};

int main() {
    BlockChainString str1;
    str1.insert(0, "Hello");
    str1.insert(5, "World");

    BlockChainString str2(str1);
    str2.StrReplace(0, 5, "Hi");

    // Do something with str1 and str2
    return 0;
}