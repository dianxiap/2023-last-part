#include <iostream>
#include <fstream>

using namespace std;

struct Node 
{
    int data;    //数据
    Node* next;  //指向下一个节点
};

class LinkedList 
{
public:
    //构造函数
    LinkedList()
    {
        head = nullptr;
    }
    //从文件中初始化
    void initializeFromFile(const char* filename) {
        ifstream file;
        file.open(filename);

        if (file.is_open()) {
            int value;
            while (file >> value) {
                insert(value);
            }
            file.close();
            //cout << "Successfully initialized from file." << endl;
        }
        else {
            cout << "Failed to open the file." << endl;
        }
    }

    //插入
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    //顺序输出
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    //获取长度
    int length() {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    //查找
    Node* find(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    //某节点插入
    void insertAfter(int afterValue, int value) {
        Node* nodeToInsert = new Node;
        nodeToInsert->data = value;

        Node* current = head;
        while (current != nullptr) {
            if (current->data == afterValue) {
                nodeToInsert->next = current->next;
                current->next = nodeToInsert;
                //cout << "Inserted " << value << " after " << afterValue << endl;
                return;
            }
            current = current->next;
        }
        //cout << "Unable to find " << afterValue << endl;
    }

    //删除
    void remove(int value) {
        //空
        if (head == nullptr) {
            return;
        }
        //头
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                cout << "Removed " << value << endl;
                return;
            }
            current = current->next;
        }

    }

    //删除所有比s小的
    void removeLowScore(int s) {
        Node* current = head;
        while (current != nullptr && current->data < s) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = current;

        Node* previous = head;
        while (current != nullptr) {
            if (current->data < s) {
                Node* temp = current;
                previous->next = current->next;
                current = current->next;
                delete temp;
            }
            else {
                previous = current;
                current = current->next;
            }
        }
    }

    //倒序输出
    void reverseDisplay() {
        reverseDisplayHelper(head);
    }

    //保存到文化中
    void saveToFile(const char* filename) {
        ofstream file;
        file.open(filename);

        if (file.is_open()) {
            Node* temp = head;
            while (temp != nullptr) {
                file << temp->data << endl;
                temp = temp->next;
            }
            file.close();
            cout << "Data saved to file." << endl;
        }
        else {
            cout << "Failed to open the file." << endl;
        }
    }
private:
    Node* head;
    void reverseDisplayHelper(Node* node) {
        if (node == nullptr) {
            return;
        }
        reverseDisplayHelper(node->next);
        cout << node->data << " ";
    }
};

int main() {
    LinkedList list;
    list.initializeFromFile("data.txt");
    list.display();
    cout << "Length: " << list.length() << endl;

    int valueToFind = 5;
    Node* foundNode = list.find(valueToFind);
    if (foundNode != nullptr) {
        cout << "Found " << valueToFind << endl;
    }
    else {
        cout << "Unable to find " << valueToFind << endl;
    }

    int afterValue = 4;
    int valueToInsert = 8;
    list.insertAfter(afterValue, valueToInsert);
    list.display();

    int valueToRemove = 6;
    list.remove(valueToRemove);
    list.display();

    int scoreThreshold = 4;
    list.removeLowScore(scoreThreshold);
    list.display();

    cout << "Reverse order: ";
    list.reverseDisplay();
    cout << endl;

    list.saveToFile("data.txt");


    return 0;
}