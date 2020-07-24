#include <iostream>
#include "Numpy.cpp"

using namespace std;

int main()
{
	Numpy<int> np_1;
	Numpy<int> np_2;
	// 1.查看 NumPy 版本信息
	cout << "Numpy_1's version: ";
	np_1.__version__();
	cout << endl;

	// 2.创建全为0的矩阵
	np_1.zeros(3, 4);
	cout << "Numpy_1's shape: ";
	np_1.shape();
	cout << endl;

	// 3.创建全为1的矩阵
	np_1.ones(3, 5);
	cout << "Numpy_1's shape: ";
	np_1.shape();
	cout << endl;

	// 4.矩阵的加和
	np_2.ones(3, 5);
	cout << "Numpy_2's shape: ";
	np_2.shape();
	cout << "Numpy_2's info:\n";
	np_2.info();
	np_2 += np_1;
	cout << "Numpy_2's info:\n";
	np_2.info();
	cout << endl;

	// 5.矩阵的减法
	np_2 -= np_1;
	cout << "Numpy_2's info:\n";
	np_2.info();
	cout << endl;

	// 6.矩阵的乘法
	np_2 *= np_1;
	cout << "Numpy_2's info:\n";
	np_2.info();
	cout << endl;

	// 7.矩阵的除法
	np_2 /= np_1;
	cout << "Numpy_2's info:\n";
	np_2.info();
	cout << endl;

	return 0;
}
