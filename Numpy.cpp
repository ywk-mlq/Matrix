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
inline Numpy<Type>&
Numpy<Type>::RankPlush(const Numpy<Type>& r, const int number)
{
    if (this->Row != r.Row || number < 0 || number > this->Rank)
    {
        throw "Type error!\n";
        return *this;
    }

    int newRank = this->Rank + r.Rank;
    Type** newMat = new Type * [newRank];
    for (int i = 0; i < newRank; ++i)
    {
        newMat[i] = new Type[this->Row];
    }

    // 拼接矩阵
    int this_Rank = 0, r_Rank = 0, new_Rank = 0;
    for (this_Rank = 0; this_Rank < number; ++this_Rank, ++new_Rank)
    {
        for (int i = 0; i < this->Row; ++i)
        {
            newMat[new_Rank][i] = this->Matrix[this_Rank][i];
        }
    }
    for (r_Rank = 0; r_Rank < r.Rank; ++r_Rank, ++new_Rank)
    {
        for (int i = 0; i < r.Row; ++i)
        {
            newMat[new_Rank][i] = r.Matrix[r_Rank][i];
        }
    }
    for (this_Rank; this_Rank < this->Rank; ++this_Rank, ++new_Rank)
    {
        for (int i = 0; i < this->Row; ++i)
        {
            newMat[new_Rank][i] = this->Matrix[this_Rank][i];
        }
    }

    this->destroyedMatrix();
    this->Rank = newRank;
    Matrix = newMat;
    cout << "The splicing matrix is complete.\n";

    return *this;
}

template <typename Type>
inline Numpy<Type>&
Numpy<Type>::RowPlush(const Numpy<Type>& r, const int number)
{
    if (this->Rank != r.Rank || number < 0 || number > this->Row)
    {
        throw "Type error!\n";
        return *this;
    }
    int newRow = this->Row + r.Row;
    Type** newMat = new Type * [this->Rank];
    for (int i = 0; i < this->Rank; ++i)
    {
        newMat[i] = new Type[newRow];
    }

    // 拼接矩阵
    // Rank都一样
    int this_Row = 0, r_Row = 0, new_Row = 0;
    for (int i = 0; i < this->Rank; ++i)
    {
        for (this_Row = 0; this_Row < number; ++this_Row)
        {
            newMat[i][this_Row] = Matrix[i][this_Row];
        }
    }
    for (int i = 0; i < this->Rank; ++i)
    {
        new_Row = this_Row;
        for (r_Row = 0; r_Row < r.Row; ++r_Row)
        {
            newMat[i][new_Row++] = r.Matrix[i][r_Row];
        }
    }
    int temp_1 = new_Row;
    int temp_2 = this_Row;

    for (int i = 0; i < this->Rank; ++i)
    {
        for (new_Row = temp_1, this_Row = temp_2; new_Row < newRow; ++new_Row, ++this_Row)
        {
            newMat[i][new_Row] = this->Matrix[i][this_Row];
        }
    }
    this->destroyedMatrix();
    this->Row = newRow;
    Matrix = newMat;
    cout << "The splicing matrix is complete.\n";
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
    Type** host_r = r.getMatrix();

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
inline Numpy<Type>&
Numpy<Type>::T()
{
    Type** last = getMatrix();
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

    return *this;
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


inline 
int tr(const Numpy<int>& r)
{
    int sum = 0;
    int rank = r.getRank(), row = r.getRow();
    if (rank != row)
        throw "Type error!\n";
    int** host = r.getMatrix();
    for (int i = 0; i < rank; ++i)
    {
        sum += host[i][i];
    }
    return sum;
}

inline
double tr(const Numpy<double>& r)
{
    double sum = 0;
    int rank = r.getRank(), row = r.getRow();
    if (rank != row)
        throw "Type error!\n";
    double** host = r.getMatrix();
    for (int i = 0; i < rank; ++i)
    {
        sum += host[i][i];
    }
    return sum;
}

inline
float tr(const Numpy<float>& r)
{
    float sum = 0;
    int rank = r.getRank(), row = r.getRow();
    if (rank != row)
        throw "Type error!\n";
    float** host = r.getMatrix();
    for (int i = 0; i < rank; ++i)
    {
        sum += host[i][i];
    }
    return sum;
}
