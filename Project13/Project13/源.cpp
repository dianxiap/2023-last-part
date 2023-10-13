#include <iostream>
using namespace std;

class HeapOnly
{
public:
	HeapOnly()
	{}
	void destory()
	{
		delete this;
	}
private:
	~HeapOnly() {}
};

int main()
{
	HeapOnly* a = new HeapOnly;
	HeapOnly 

}