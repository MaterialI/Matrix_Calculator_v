#include <iostream>
#include "Matrix.h"
using namespace std;
int main()
{
	//more to be done
	Matrix a(2,2);
	a.fill();
	Matrix b(2, 2);
	b.fill();
	Matrix c = a.operator*(b);
	c.get_matrix();
	
}