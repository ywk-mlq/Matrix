#include <iostream>
#include "Numpy.cpp"

using namespace std;

int main()
{
	Numpy<int> np;

	// 1.²é¿´ NumPy °æ±¾ÐÅÏ¢
	cout << "Numpy's version: ";
	np.__version__();

	// 2.´´½¨È«Îª0µÄ¾ØÕó
	np.zeros(3, 4);
	cout << "Numpy's shape: ";
	np.shape();

	// 3.´´½¨È«Îª1µÄ¾ØÕó
	np.ones(5, 2);
	cout << "Numpy's shape: ";
	np.shape();


	return 0;
}
