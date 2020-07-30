#ifndef __NUMPY__
#define __NUMPY__

/**
* autor		: yuwenkai
* date		: 2020.07.20
* update    : 2020.07.24
* upadte	: 2020.07.25
* update    : 2020.07.26
* updata	: 2020.07.27
* update    : 2020.07.29
* update    : 2020.07.30
* version	：1.0.7
*/

#include <cmath>
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
    const string version = "1.0.6";
    int Rank, Row;
    int temp_Rank;
    Type** Matrix;
    Type** temp;
    
    string version_() const;
    Type** getMatrix() const;
    void creatMatrix();
    void destroyedMatrix();
    int getRank() const { return Rank; }
    int getRow()  const { return Row; }

    // 矩阵的运算
    Numpy<Type>& __dot(const Numpy<Type>*, const Numpy<Type>&);


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
    Numpy<Type>& RankPlush(const Numpy<Type>&, const int number = 0);
    Numpy<Type>& RowPlush(const Numpy<Type>&, const int number = 0);
    bool operator == (const Numpy<Type>&) const;
    bool operator != (const Numpy<Type>&) const;
    Numpy<Type>& dot(const Numpy<Type>&);
    Numpy<Type>& T();

    // 矩阵友元运算
    friend Type tr(const Numpy<Type>& r);
    // friend Type det(const Numpy<Type>& r);
    friend Numpy<Type>& operator - (Numpy<Type>& r);
    
        

};

#endif
