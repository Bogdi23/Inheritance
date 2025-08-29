#include<iostream>
using namespace std;

const char* Hello()
{
	return "Hello";
}
int Add(int a, int b)
{
	return a + b;
}
int Subtract(int a, int b)
{
	return a - b;
}
double Div(int a, int b)
{
	return (double)a / b;
}
int Calculate(int a, int b, int (*operation)(int, int))
{
	return (*operation)(a, b);
}

void main()
{
	setlocale(LC_ALL, "");
	cout << Hello << endl;
	const char* (*pHello)() = Hello;
	cout << (*pHello)() << endl;

	/*int (*pAdd)(int, int) = Add;
	int (*pSubtract)(int, int) = Subtract;

	cout << (*pAdd)(2, 3) << endl;
	cout << (*pSubtract)(8, 3) << endl;*/

	cout << Calculate(8, 3, Add) << endl;
	cout << Calculate(8, 3, Subtract) << endl;
}