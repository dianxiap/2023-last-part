#define _CRT_SECURE_NO_WARNINGS 1

//1.���ݻ���
//2.�ļ�����

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

using namespace std;

struct Student
{
	int ID;
	string Name;
	string Group;
	int Score;
};

class SeqList
{
public:
	//���캯��
	SeqList()
	{
		_data = new Student[10];
		_size = 0;
		_capacity = 10;
	}
	//����
	~SeqList()
	{
		delete[] _data;
		_data = nullptr;
	}
	//���ļ��ж�ȡ
	void initFornFile(string filename)
	{
		ifstream file(filename);
		if (!file)
		{
			perror("file error");
			return ;
		}

		//������һ��
		string line;
		getline(file, line);

		Student s;
		while (file >> s.ID>>s.Name>>s.Group>>s.Score)
		{
			checkcapacity();
			_data[_size++] = s;
		}
		file.close();
	}
	//��ʾ
	void display()
	{
		cout << "ID" << "\t" << "Name" << "\t" << "Group" << "\t" << "Score" << endl;
		for (int i = 0; i < _size; i++)
		{
			cout << _data[i].ID << "\t" << _data[i].Name << "\t" << _data[i].Group << "\t" << _data[i].Score << endl;
		}
		//cout << endl;
	}
	//���ظ���
	int size()
	{
		return _size;
	}
	//��ID��
	int find(const int& val)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_data[i].ID == val)
				return i;
		}
		return -1;
	}
	//����
	void insert(const Student& s)
	{
		checkcapacity();

		_data[_size++] = s;
	}
	//ɾ��idx��������
	void remove(int idx)
	{
		for (int i = idx;i < _size-1;i++)
		{
			_data[i] = _data[i + 1];
		}
		_size--;
	}
	//ɾ������score����s��Ԫ��
	void removelessthen(const int& val)
	{
		int i = 0;
		while (i < _size)
		{
			if (_data[i].Score < val)
				remove(i);
			else i++;
		}
	}
	//д���ļ���
	void writeToFile(string filename)
	{
		ofstream file(filename);
		if (!file)
		{
			perror("file error");
			return;
		}
		file << "ID" << "\t" << "Name" << "\t" << "Group" << "\t" << "Score" << endl;
		for (int i = 0;i < _size;i++)
		{
			file << _data[i].ID << "\t" << _data[i].Name << "\t" << 
				_data[i].Group << "\t" << _data[i].Score << endl;
		}
		file.close();
	}
private:
	Student* _data;
	int _size;
	int _capacity;

	//���ռ�
	void checkcapacity()
	{
		if (_size == _capacity)
		{
			Student* newData = new Student[_capacity == 0 ? 10 : _capacity * 2];
			
			for (int i = 0; i < _size; i++)
				newData[i] = _data[i];
			delete[] _data;
			_data = newData;
			_capacity *= 2;
		}
	}
};

int main()
{
	SeqList list;
	list.initFornFile("test.txt");
	//list.display();

	//list.writeToFile("test.txt");

	//if (list.find(78) != -1)
	//	cout << "find success" << endl;
	//else cout << "find fail" << endl;

	//Student s = { 1005, "Alice", "Group B", 90 };
	//list.insert(s);
	//list.display();

	//list.remove(2);
	
	list.removelessthen(100);
	list.display(); 

	list.writeToFile("test.txt");
	//list.remove(2);
	//list.display();
}