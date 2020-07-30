#include <iostream>
#include "Numpy.cpp"

using namespace std;

int main()
{
    Numpy<int> np_1;
    Numpy<int> np_2;

    // 1.查看 NumPy 版本信息
    cout << "\nNo.1 View NumPy version information.\n";
    cout << "Numpy_1's version: ";
    np_1.__version__();
    cout << endl;

    // 2.创建全为0的矩阵
    cout << "No.2 Create all 0 matrices.\n";
    np_1.zeros(3, 4);
    cout << "Numpy_1's shape: ";
    np_1.shape();
    cout << endl;

    // 3.创建全为1的矩阵
    cout << "No.3 Create all 1 matrices.\n";
    np_1.ones(3, 5);
    cout << "Numpy_1's shape: ";
    np_1.shape();
    cout << endl;

    // 4.矩阵的加和
    cout << "No.4 Sum of matrices.\n";
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
    cout << "No.5 Matrix subtraction.\n";
    np_2 -= np_1;
    cout << "Numpy_2's info:\n";
    np_2.info();
    cout << endl;

    // 6.矩阵的乘法
    cout << "No.6 Matrix multiplication.\n";
    np_2 *= np_1;
    cout << "Numpy_2's info:\n";
    np_2.info();
    cout << endl;

    // 7.矩阵的除法
    cout << "No.7 Matrix division.\n";
    np_2 /= np_1;
    cout << "Numpy_2's info:\n";
    np_2.info();
    cout << endl;

    // 8.矩阵的点乘
    cout << "No.8 Dot product of a matrix.\n";
    np_1.ones(2, 3);
    np_2.ones(3, 2);
    np_1.dot(np_2);
    // 显示数据
    cout << "np_1's info:\n";
    np_1.info();
    cout << endl;

    // 9.创建矩阵
    cout << "No.9 Create a matrix.\n";
    int arrays[2][3] = { {1, 2, 3},
                         {4, 5, 6 } };
    cout << "Numpy_1's info:\n";
    np_1.info();
    np_1.array(arrays, 2, 3);
    cout << "Numpy_1's info:\n";
    np_1.info();
    cout << endl;

    // 10.矩阵的转换
    cout << "Mo.10 Transpose of a matrix.\n";
    np_1.T();
    cout << "Numpy_1's info:\n";
    np_1.info();
    cout << endl;

    // 11.矩阵与数的乘法
    cout << "No.11 Matrix and number multiplication.\n";
    cout << "Numpy_2's info:\n";
    np_2.info();
    np_2 *= 3;
    cout << "Numpy_2's info:\n";
    np_2.info();
    cout << endl;

    // 12.矩阵与数的除法
    cout << "No.12 Matrix and number division.\n";
    np_1 /= 2;
    cout << "Numpy_1's info:\n";
    np_1.info();
    cout << endl;

    // 13.行拼接矩阵
    cout << "No.13 Rank splice matrix.\n";
    try {
        np_1.RankPlush(np_2, 1);
    }
    catch (const char* str) {
        cerr << str;
    }
    cout << "Numpy_1's info:\n";
    np_1.info();
    cout << endl;

    // 14.列拼接矩阵
    cout << "No.14 Column splicing matrix.\n";
    np_2.ones(6, 2);
    try {
        np_1.RowPlush(np_2, 0);
    }
    catch (const char* str) {
        cerr << str;
    }
    cout << "Numpy_1's info:\n";
    np_1.info();
    cout << endl;
 
    // 15.矩阵的迹
    cout << "No.15 Matrix trace.\n";
    try
    {
        np_1.RowPlush(np_2);
    }
    catch (const char* str)
    {
        cerr << str;
    }
    np_1.info();
    cout << "tr(np_1*3) = " << tr(np_1 *= 3) << endl;
    np_1.info();
    cout << endl;

    // 16.矩阵的负
    cout << "No.16 The negative of the matrix.\n";
    cout << "Numpy_2's info:\n";
    np_2.info();
    -np_2;
    cout << "Numpy_2's info:\n";
    np_2.info();
    cout << endl;

    // 17.判断矩阵是否相等
    cout << "No.17 Determine if the matrices are equal.\n";
    if (np_1 == np_2)
        cout << "np_1 == np_2\n";
    else
        cout << "np_1 != np_2\n";
    if (np_1 == np_1)
        cout << "np_1 == np_1\n";
    else
        cout << "np_1 != np_1\n";
    cout << endl;



    return 0;
}
