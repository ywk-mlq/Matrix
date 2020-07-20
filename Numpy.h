#ifndef __NUMPY__
#define __NUMPY__

/**
* autor		: yuwenkai
* date		: 2020.07.20
* version	£º1.0.0
*/

#include <cstring>
#include <iostream>
using namespace std;

/**
* ¾ØÕóµÄÀà
* ·ÂPython--numpy
*/

template <typename Type>
class Numpy
{
private:
	const string version = "1.0.0";
	int Rank, Row;
	Type** Matrix;

	string version_() const;
	Type** getMatrix() const;
	void creatMatrix();
	void destroyedMatrix();

public:
	Numpy();
	~Numpy();
	void __version__() const;
	void array();
	void shape() const;
	Type** zeros(const int rank, const int row);
	Type** ones(const int rank, const int row);
};

#endif
