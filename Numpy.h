#ifndef __NUMPY__
#define __NUMPY__

/**
* autor		: yuwenkai
* date		: 2020.07.20
* update    	: 2020.07.24
* upadte	: 2020.07.25
* update    	: 2020.07.26
* version	：1.0.3
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
	const string version = "1.0.3";
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

	// 矩阵的显示
	void shape() const;
	void info() const;

	// 矩阵的创建
	Type** array(const Type(&arrays)[2][3], int, int);
	Type** zeros(const int rank, const int row);
	Type** ones(const int rank, const int row);

	// 矩阵的运算
	Numpy<Type>& operator += (const Numpy<Type>&);
	Numpy<Type>& operator -= (const Numpy<Type>&);
	Numpy<Type>& operator *= (const Numpy<Type>&);
	Numpy<Type>& operator /= (const Numpy<Type>&);
	Numpy<Type>& operator *= (const Type&);
	Numpy<Type>& operator /= (const Type&);
	Type** dot(const Numpy<Type>&);
	Type** T();
};

#endif
