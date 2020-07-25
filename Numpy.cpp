#include "Numpy.h"

template <typename Type>
inline
Numpy<Type>::Numpy()
	: Rank(0), Row(0), temp_Rank(0), Matrix(NULL), temp(NULL)
{
	cout << "The matrix has been initialized.\n";
}

template <typename Type>
inline
string Numpy<Type>::version_() const
{
	return version;
}

template <typename Type>
inline
void Numpy<Type>::__version__() const
{
	cout << "'" << version_() << "'" << endl;
}

template <typename Type>
inline
void Numpy<Type>::info() const
{
	Type** host = this->getMatrix();
	// 显示矩阵
	for (int i = 0; i < Rank; ++i)
	{
		for (int j = 0; j < Row; ++j)
		{
			cout << host[i][j] << "  ";
		}
		cout << endl;
	}
}

template <typename Type>
inline Type**
Numpy<Type>::array(const Type(&arrays)[2][3], int rank, int row)
{
	destroyedMatrix();
	Rank = rank;  Row = row;
	creatMatrix();
	Type** matrix = getMatrix();

	// 赋值
	for (int i = 0; i < Rank; ++i)
	{
		for (int j = 0; j < Row; ++j)
			matrix[i][j] = arrays[i][j];
	}
	return matrix;
}

template <typename Type>
inline
Type** Numpy<Type>::getMatrix() const
{
	return Matrix;
}

template <typename Type>
inline
void Numpy<Type>::creatMatrix()
{
	Matrix = new Type * [Rank];
	for (int i = 0; i < Rank; ++i)
		Matrix[i] = new Type[Row];
}

template <typename Type>
inline
Type** Numpy<Type>::zeros(const int rank, const int row)
{
	// 创建
	destroyedMatrix();
	Rank = rank;  Row = row;
	creatMatrix();
	Type** matrix = getMatrix();

	// 赋值
	for (int i = 0; i < Rank; ++i)
		for (int j = 0; j < Row; ++j)
			matrix[i][j] = 0;
	return matrix;
}

template <typename Type>
inline
Type** Numpy<Type>::ones(const int rank, const int row)
{
	// 创建
	destroyedMatrix();
	Rank = rank;  Row = row;
	creatMatrix();
	Type** matrix = getMatrix();

	// 赋值
	for (int i = 0; i < Rank; ++i)
		for (int j = 0; j < Row; ++j)
			matrix[i][j] = 1;
	return matrix;
}

template <typename Type>
inline
void Numpy<Type>::destroyedMatrix()
{
	if (Matrix != NULL)
	{
		for (int i = 0; i < Rank; ++i)
		{
			if (Matrix[i] != NULL)
			{
				delete[]Matrix[i];
				Matrix[i] = NULL;
			}
		}
		delete[]Matrix;
		Matrix = NULL;
		cout << "Matrix has been cleared.\n";
	}
}

template <typename Type>
inline
void Numpy<Type>::shape() const
{
	cout << "(" << Rank << ", " << Row << ")\n";
}

template <typename Type>
inline Numpy<Type>&
Numpy<Type>::operator += (const Numpy<Type>& r)
{
	Type** host_r = r.getMatrix();
	Type** host_t = this->getMatrix();
	// 加和运算
	for (int i = 0; i < this->Rank; ++i)
	{
		for (int j = 0; j < this->Row; ++j)
		{
			host_t[i][j] += host_r[i][j];
		}
	}
	cout << "The matrix addition is complete.\n";
	return *this;
}


template <typename Type>
inline Numpy<Type>&
Numpy<Type>::operator -= (const Numpy<Type>& r)
{
	Type** host_r = r.getMatrix();
	Type** host_t = this->getMatrix();
	// 减法运算
	for (int i = 0; i < this->Rank; ++i)
	{
		for (int j = 0; j < this->Row; ++j)
		{
			host_t[i][j] -= host_r[i][j];
		}
	}
	cout << "The matrix subtraction is done.\n";
	return *this;
}

template <typename Type>
inline Numpy<Type>&
Numpy<Type>::operator *= (const Numpy<Type>& r)
{
	Type** host_r = r.getMatrix();
	Type** host_t = this->getMatrix();
	// 加和运算
	for (int i = 0; i < this->Rank; ++i)
	{
		for (int j = 0; j < this->Row; ++j)
		{
			host_t[i][j] *= host_r[i][j];
		}
	}
	cout << "Matrix multiplication is done.\n";
	return *this;
}

template <typename Type>
inline
Numpy<Type>&
Numpy<Type>::operator *= (const Type& r)
{
	Type** host_t = this->getMatrix();
	for (int i = 0; i < Rank; ++i)
		for (int j = 0; j < Row; ++j)
			host_t[i][j] *= r;
	return *this;
}

template <typename Type>
inline Numpy<Type>&
Numpy<Type>::operator /= (const Numpy<Type>& r)
{
	Type** host_r = r.getMatrix();
	Type** host_t = this->getMatrix();
	// 加和运算
	for (int i = 0; i < this->Rank; ++i)
	{
		for (int j = 0; j < this->Row; ++j)
		{
			host_t[i][j] /= host_r[i][j];
		}
	}
	cout << "The matrix division operation is completed.\n";
	return *this;
}

template <typename Type>
inline
Numpy<Type>&
Numpy<Type>::operator /= (const Type& r)
{
	Type** host_t = this->getMatrix();
	for (int i = 0; i < Rank; ++i)
		for (int j = 0; j < Row; ++j)
			host_t[i][j] /= r;
	return *this;
}

template <typename Type>
inline Type**
Numpy<Type>::dot(const Numpy<Type>& r)
{
	return __dot(this, r);
}

template <typename Type>
inline Type**
Numpy<Type>::__dot(const Numpy<Type>* ths, const Numpy<Type>& r)
{
	temp = new Type * [this->Rank];
	temp_Rank = this->Rank;
	for (int i = 0; i < this->Rank; ++i)
	{
		temp[i] = new Type[r.Row];
		for (int h = 0; h < r.Row; ++h)
			temp[i][h] = 0;
	}

	Type** host_this = ths->getMatrix();
	Type** host_r	 = r.getMatrix();
		
	// 赋值
	for (int i = 0; i < this->Rank; ++i)
	{
		for (int j = 0; j < r.Row; ++j)
		{
			for (int p = 0; p < r.Rank; ++p)
			{
				temp[i][j] += host_this[i][p] * host_r[p][j];
			}
		}
	}
	return temp;
}

template <typename Type>
inline Type**
Numpy<Type>::T()
{
	Type** last  = getMatrix();
	Type** first = new Type * [Row];
	for (int i = 0; i < Row; ++i)
	{
		first[i] = new Type[Rank];
	}

	// 转换赋值
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Rank; ++j)
		{
			first[i][j] = last[j][i];
		}
	}

	// 转换变量
	destroyedMatrix();
	int temp = Rank;
	Rank = Row;
	Row = temp;
	if (Matrix == NULL)
		Matrix = first;
		
	return getMatrix();
}

template <typename Type>
inline
Numpy<Type>::~Numpy()
{
	// 释放矩阵
	destroyedMatrix();
	cout << "Matrix has been destroyed.\n";
	if (temp != NULL)
	{
		for (int i = 0; i < temp_Rank; ++i)
		{
			if (temp[i] != NULL)
			{
				delete[]temp[i];
				temp[i] = NULL;
			}
		}
		delete[]temp;
		temp = NULL;
		cout << "Temp has been destroyed.\n";
	}
}
