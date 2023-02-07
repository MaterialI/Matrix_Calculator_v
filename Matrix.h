using namespace std;
class Matrix
{
public:
	Matrix();
	Matrix(int);
	Matrix(int,int);
	//copy constructor 
	Matrix(const Matrix&);
	Matrix(float**, int, int);
	Matrix& operator =(const Matrix&);
	~Matrix();
	void fill();
	void get_matrix() const;
	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix operator * (float);
	void rrefRow(); 
	void inverse();
private:	
	void rrefRowR(int curr);
	void rowReduceS(int decreased, int substracted);
	void rowReduceInverse(Matrix& identity, int decreased, int substracted);
	
	void inverseR(Matrix& identity, int curr);
	float** arr;
	int sizeX;
	int sizeY;
	void reset_size(int, int);
};


