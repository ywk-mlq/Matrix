#include "Numpy.h"

template <typename Type>
inline
Numpy<Type>::Numpy()
	: Rank(0), Row(0), Matrix(NULL)
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
	// ´´½¨
	destroyedMatrix();
	Rank = rank;  Row = row;
	creatMatrix();
	Type** matrix = getMatrix();

	// ¸³Öµ
	for (int i = 0; i < Rank; ++i)
		for (int j = 0; j < Row; ++j)
			matrix[i][j] = 0;
	return matrix;
}

template <typename Type>
inline
Type** Numpy<Type>::ones(const int rank, const int row)
{
	// ´´½¨
	destroyedMatrix();
	Rank = rank;  Row = row;
	creatMatrix();
	Type** matrix = getMatrix();

	// ¸³Öµ
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
inline
Numpy<Type>::~Numpy()
{
	// ÊÍ·Å¾ØÕó
	destroyedMatrix();
	cout << "Matrix has been destroyed.\n";
}
