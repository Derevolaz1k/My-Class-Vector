#include <iostream>
#include "MyVector.h"
using namespace std;

int main()
{
	MyVector a(10, new int[10]{ 1,2,3,4,5,6,7,8,9,10});
	MyVector b(a);
	MyVector c(13, new int[2]{ 1,2 });
	b.printArr();
	//b.insert(2, 7,2);
	cout << endl;
	b.printArr();
	b.erase(0,7);
	cout << endl;
	b.printArr();
	cout << " cap = " << b.capacity();
	b.resize(30);
	b = a;
	cout<<endl<<(b == a);
	cout << endl;
	b.printArr();
	cout << " cap = " << b.capacity()<<endl;
	system("pause");
	return 0;
}