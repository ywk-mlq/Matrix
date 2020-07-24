#ifndef __NUMPY__
#define __NUMPY__

/**
* autor		: yuwenkai
* date		: 2020.07.20
* update    	: 2020.07.24
* version	：1.0.1
*/

#include <cstring>
#include <iostream>
using namespace std;

/**
* 矩阵的类
* 仿Python--numpy
*/
template <typename Type>
class Numpy
{
private:
	const string version = "1.0.1";
	int Rank, Row;
	Type** Matrix;
	Type** temp;
	int temp_Rank;

	string version_() const;
	Type** getMatrix() const;
	void creatMatrix();
	void destroyedMatrix();

	// 矩阵的运算
	Type** __dot(const Numpy<Type>*, const Numpy<Type>&);
	

public:
	Numpy();
	~Numpy();
	void __version__() const;
	void array();

	// 矩阵的显示
	void shape() const;
	void info() const;

	// 矩阵的创建
	Type** zeros(const int rank, const int row);
	Type** ones(const int rank, const int row);

	// 矩阵的运算
	Numpy<Type>& operator += (const Numpy<Type>&);
	Numpy<Type>& operator -= (const Numpy<Type>&);
	Numpy<Type>& operator *= (const Numpy<Type>&);
	Numpy<Type>& operator /= (const Numpy<Type>&);
	Type** dot(const Numpy<Type>&);
};

#endif
