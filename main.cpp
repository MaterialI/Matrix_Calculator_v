#include <iostream>
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
	a.operator-(b).get_matrix();*/
	Matrix a(10, 10);

	a.get_matrix();
	cout << "________________________________" << endl;
	Matrix b = a;
	b.get_matrix();
	Matrix c = a * b;
	cout << "________________________________" << endl;
	c.get_matrix();
	
}