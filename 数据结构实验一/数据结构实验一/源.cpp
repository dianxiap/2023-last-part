#define _CRT_SECURE_NO_WARNINGS 1

//1.扩容机制
//2.文件操作

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
	//构造函数
	SeqList()
	{
		_data = new Student[10];
		_size = 0;
		_capacity = 10;
	}
	//析构
	~SeqList()
	{
		delete[] _data;
		_data = nullptr;
	}
	//从文件中读取
	void initFornFile(string filename)
	{
		ifstream file(filename);
		if (!file)
		{
			perror("file error");
			return ;
		}

		//跳过第一行
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
	//显示
	void display()
	{
		cout << "ID" << "\t" << "Name" << "\t" << "Group" << "\t" << "Score" << endl;
		for (int i = 0; i < _size; i++)
		{
			cout << _data[i].ID << "\t" << _data[i].Name << "\t" << _data[i].Group << "\t" << _data[i].Score << endl;
		}
		//cout << endl;
	}
	//返回个数
	int size()
	{
		return _size;
	}
	//按ID查
	int find(const int& val)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_data[i].ID == val)
				return i;
		}
		return -1;
	}
	//插入
	void insert(const Student& s)
	{
		checkcapacity();

		_data[_size++] = s;
	}
	//删除idx处的数据
	void remove(int idx)
	{
		for (int i = idx;i < _size-1;i++)
		{
			_data[i] = _data[i + 1];
		}
		_size--;
	}
	//删除所有score低于s的元素
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
	//写入文件中
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

	//检查空间
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