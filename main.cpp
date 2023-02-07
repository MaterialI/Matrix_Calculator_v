//#include <iostream>
//#include<ctime>
//#include<random>
//#include "Matrix.h"
//using namespace std;
//int main()
//{
//	//more to be done
//	/*Matrix a(2,2);
//	a.fill();
//	Matrix b(2, 2);
//	b.fill();
//	a.get_matrix();
//	Matrix c = a * b;
//	c.get_matrix();*/
//	/*Matrix a(10, 10);
//	a.get_matrix();
//	cout << "________________________________" << endl;
//	Matrix b = a;
//	b.get_matrix();
//	Matrix c = a * b;
//	cout << "________________________________" << endl;
//	c.get_matrix();*/
//	/*int x = 1;
//	int y = 3;
//	float** arr1;
//	arr1 = new float* [y];
//	for (int i = 0; i < y; i++)
//	{
//		arr1[i] = new float[x];
//		for (int j = 0; j < x; j++)
//			arr1[i][j] = rand() % 101 - 50;
//		
//	}
//	Matrix a(arr1, y, x);
//	a.get_matrix();
//	
//	cout << "_________________________" << endl;
//	float** arr2;
//	arr2 = new float* [x];
//	for (int i = 0; i < x; i++)
//	{
//		arr2[i] = new float[y];
//		for (int j = 0; j < y; j++)
//			arr2[i][j] = rand() % 101 -50;
//	}
//	Matrix b(arr2,x, y);
//	b.get_matrix();
//	cout << "_________________________" << endl;
//	Matrix c = a.operator*(b);
//	c.operator*(0.1);
//	c.get_matrix();*/
//	cout << "Hello, this is Materiali speaking. \nLet me introduce you to basic matrix calculator. It has 4 main functions: \naddition(+), substraction(-), multiplication of 2 matricies(*), and matrix scaling(x). \nAnd several interesting features as: RRef(can be used to find solutions for systems of linear equations) , and matrix inverse" << endl;
//	cout << "So, lets roll" << endl;
//	char oper = '1';
//	Matrix* a;
//	Matrix* b;
//	Matrix* r;
//	int aX = 0, bX = 0, aY = 0, bY = 0;
//	while (oper != '0')
//	{
//		cout << "First of all, lets enter size of the first matrix and fill it" << endl;
//		cout << "enter 1-st matrix dimensions(int):" << endl;
//		cout << "y(vertical): ";
//		cin >> aY;
//		cout << "x(horizontal): ";
//		cin >> aX;
//		a = new Matrix(aY, aX);
//		cout << "Let's fill it: ";
//		a->fill();
//		
//		cout << "Now, lets enter size of the second matrix and fill it";
//		cout << "enter 2-nd matrix dimensions(int):" << endl;
//		cout << "y(vertical): ";
//		cin >> bY;
//		cout << "x(horizontal): ";
//		cin >> bX;
//		b = new Matrix(bY, bX);
//		cout << "Let's fill it: ";
//		b->fill();
//		cout << "Please, enter an operation, to exit enter (0)" << endl;
//		cin >> oper;
//		if (oper == '0')
//			break;
//		/*if (oper == '+'||oper=='-'||oper=='*')
//		{
//			cout << "Now, lets enter size of the second matrix and fill it";
//			cout << "enter 2-nd matrix dimensions(int):" << endl;
//			cout << "y(vertical): ";
//			cin >> bY;
//			cout << "x(horizontal): ";
//			cin >> bX;
//			b = new Matrix(bY, bX);
//			cout << "Let's fill it: ";
//			b->fill();
//		}*/
//		if (oper == '+')
//		{
//			cout << "You have chosen addition" << endl;
//			cout << "Matrix:" << endl;
//			r = new Matrix(a->operator+(*b));
//			r->get_matrix();
//			r->~Matrix();
//		}
//		else if (oper == '-')
//		{
//			cout << "You have chosen substraction" << endl;
//			cout << "Matrix:" << endl;
//			r = new Matrix(a->operator-(*b));
//			r->get_matrix();
//			r->~Matrix();
//		}
//		else if (oper == '*')
//		{
//			cout << "You have chosen multiplication" << endl;
//			cout << "Matrix:" << endl;
//			r = new Matrix(a->operator*(*b));
//			r->get_matrix();
//			r->~Matrix();
//		}
//		else if (oper == 'X')
//		{
//			float sc;
//			cout << "You have chosen scaling" << endl;
//			cout << "Enter your scalar: " << endl;
//			cin >> sc;
//			cout << "Matrix:" << endl;
//			r = new Matrix(a->operator*(sc));
//			r->get_matrix();
//			r->~Matrix();
//		}
//		else if (oper == 'I')
//		{
//			cout << "You have chosen multiplication" << endl;
//			cout << "Matrix:" << endl;
//			r = a;
//			r->inverse();
//			r->get_matrix();
//			r->~Matrix();
//		}
//	}
//}
#include <iostream>
#include<ctime>
#include<random>
#include "Matrix.h"
using namespace std;
int main()
{
	//more to be done
	/*Matrix a(2,2);
	a.fill();
	Matrix b(2, 2);
	b.fill();
	a.get_matrix();
	Matrix c = a * b;
	c.get_matrix();*/
	/*Matrix a(10, 10);
	a.get_matrix();
	cout << "________________________________" << endl;
	Matrix b = a;
	b.get_matrix();
	Matrix c = a * b;
	cout << "________________________________" << endl;
	c.get_matrix();*/
	srand(time(0));
	
	int x = 2;
	int y = 2;
	Matrix ind(x);
	ind.get_matrix();
	cout << "___________________________" << endl;
	float** arr1;
	arr1 = new float* [y];
	for (int i = 0; i < y; i++)
	{
		arr1[i] = new float[x];
		for (int j = 0; j < x; j++)
			arr1[i][j] = rand() % 11 - 5;

	}
	Matrix a(arr1, y, x);
	a.get_matrix();

	cout << "_________________________" << endl;
	float** arr2;
	arr2 = new float* [x];
	for (int i = 0; i < x; i++)
	{
		arr2[i] = new float[y];
		for (int j = 0; j < y; j++)
			arr2[i][j] = rand() % 11 - 5;
	}
	arr2[0][0] = 10;
	arr2[0][1] = 10;
	arr2[1][0] = 7;
	arr2[1][1] = 10;
	Matrix b(arr2, x, x);
	b.get_matrix();
	cout << "_________________________" << endl;
	b.inverse();
	b.get_matrix();
	/*Matrix c = a.operator*(b);
	c.operator*(0.1);
	c.get_matrix();*/
}