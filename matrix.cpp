#include "matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

matrix::matrix(int row1 , int col1 , int num[]){    /// constructor take the data of matrix
    row = row1;
    col = col1;
    data = new int[row*col];
    for (int i = 0; i< row*col; ++i)
    {
        data[i] = num[i];
    }
}
void matrix::setrow(int r){                         /// set to row
    row=r;
}
void matrix::setcolumn(int c){                      /// set to column
    col=c;
}
void matrix::setdata(int row, int col,int num[]){   /// set to data
    int* data=new int[row*col];
    for(int i=0; i< row*col; ++i)
    {
        data[i]=num[i];
    }
}
int matrix::getrow(){                               /// get the rows
    return row;
}
int matrix::getcolumn(){                            /// get the columns
    return col;
}
int* matrix::getdata(){                             /// get the data
    return data;
}



/// Student One ///////////// Ali Khaled //////

matrix matrix:: operator+(matrix mat2){
    matrix mat(row,col,data);
    if(mat.row == mat2.row && mat.col ==mat2.col)
    {
        for(int i = 0 ; i< mat2.row*mat2.col ; i++)
        {
            mat.data[i] =data[i]+mat2.data[i] ;
        }
    }
    return mat ;
}
matrix matrix:: operator-(matrix mat2) {
	matrix mat(row, col, data);
	if (mat.row == mat2.row && mat.col == mat2.col)
	{
		for (int i = 0; i< mat2.row*mat2.col; i++)
		{
			mat.data[i] = data[i] - mat2.data[i];
		}
	}
	return mat;
}
matrix matrix::operator* (matrix mat2){
	matrix mat1(row,mat2.col);
    int x = 0;
	for (int i = 0; i < mat2.row*mat2.col; i += mat2.col)
	{
		for (int j = 0; j < (row*col / mat2.col); j++)
		{
			int temp = 0;
			for (int t = 0; t < mat2.col; t++)
			{
				temp += mat2.data[i + t] * data[j + t*mat2.row];
			}
			mat1.data[x] = temp;
			x++;
		}
	}
	return mat1;
}
matrix matrix:: operator+(int scalar){
    matrix mat1(row,col,data);
    for(int i = 0 ; i< mat1.row*mat1.col ; i++)
    {
        mat1.data[i] =data[i]+scalar ;
    }
    return mat1 ;
}
matrix matrix:: operator-(int scalar){
    matrix mat1(row,col,data);
    for(int i = 0 ; i< mat1.row*mat1.col ; i++)
    {
        mat1.data[i] =data[i]-scalar ;
    }
    return mat1 ;
}
matrix matrix:: operator*(int scalar){
    matrix mat1(row,col,data);
    for(int i = 0 ; i< mat1.row*mat1.col ; i++)
    {
        mat1.data[i] =data[i]*scalar ;
    }
    return mat1 ;
}


///  Student 2 //// Mustafa Badr /////////////////////////

matrix matrix::operator+= (matrix mat2){  /// add two matrices and put the addition in the first matrix

    if (row == mat2.row && col == mat2.col)
    {

        for (int i = 0; i<(row*col); ++i)
        {
           data[i] += mat2.data[i];
        }
    }
    else
    {
        cout << "The Two Mattresses can't be add: ";
    }

    return* data;
}
matrix matrix::operator-= (matrix mat2) { /// subtract two matrices and put the subtraction in the first matrix

	if (row == mat2.row && col == mat2.col)
	{
		for (int i = 0; i<(row*col); ++i)
		{
			data[i] -= mat2.data[i];
		}

	}
	else
	{
		cout << "The Two Mattresses can't be add: ";
	}

	return *data;
}
matrix matrix::operator+= (int scalar){   /// add an integer to each element in the matrix

    for(int i=0; i<(row*col); ++i)
    {
        data[i]=data[i]+scalar;
    }
    return *data;
}
matrix matrix::operator-= (int scalar) {  /// subtract each element by an integer

	for (int i = 0; i<(row*col); ++i)
	{
		data[i] = data[i] - scalar;
	}
	return *data;
}
void matrix::operator++ (){               /// add one to each element in the matrix

    matrix mat(row,col,data);
    for(int i=0; i<(row*col); ++i)
    {
       data[i]=data[i]+1;
    }
}
void matrix::operator-- () {              /// subtract one from each element in the matrix

	for (int i = 0; i<(row*col); ++i)
	{
		data[i] = data[i]- 1;
	}
}

/// Student 3 ///// Marwan Mohamed /////////////////////////

bool matrix::operator== (matrix mat2){
    matrix mat1(row,col,data);
    bool status = true;
    if (mat1.col==mat2.col && mat1.row==mat2.row){
        for (int i=0; i<mat1.col*mat1.row; i++){
            if (mat1.data[i] != mat2.data[i]){
                status = false;
                break;
            }
        }
    }
    else {
        status = false;
    }
    return status;
}
bool matrix::operator!= (matrix mat2){
    matrix mat1(row,col,data);
    bool status = false;
    if (mat1.col==mat2.col && mat1.row==mat2.row){
        for (int i=0; i<mat1.col*mat1.row; i++){
            if (mat1.data[i] != mat2.data[i]){
                status = true;
                break;
            }
        }
    }
    else {
        status = true;
    }
    return status;
}
bool matrix::isSquare (){
    matrix mat(row,col,data);
    bool status = true;
    if (mat.row != mat.col){
        status = false;
    }
    return status;
}
matrix transpose();
bool matrix::isSymetric(){
    matrix mat(row,col,data);
    bool status = true;
    if (mat.row==mat.col){
        for (int i=0; i<mat.col*mat.row; i++){
            if (transpose().data[i]!= mat.data[i]){
                status = false;
                break;
            }
        }
    }
    else {
        status = false;
    }
    return status;
}
bool matrix::isIdentity(){
    matrix mat(row,col,data);
    bool status = true;
    if (mat.row==mat.col){
        for (int i=0 ; i<mat.row*mat.col; i++){
            if (mat.data[i]!= 1 && mat.data[i]!=0){
                status = false;
                break;
            }
            else if (mat.data[i]=1){
                if (i != 0 && i!= 4 && i!=8){
                    status = false ;
                }
            }
        }
    }
    else {
        status = false;
    }
    return status;
}
matrix matrix::transpose(){
    matrix mat(row,col,data);
    int x=0;
    for (int i=0 ; i<mat.col; i++){
            for (int f=0; f<mat.row; f++){
                mat.data[i]= mat.data[(mat.row*f)+i];
                x++;
            }
    }
    return mat;
}

/// The Additional Function from prof.

void matrix:: operator= (matrix mat){

	row = mat.row;
	col = mat.col;
    data = new int[row*col];
	for (int i = 0; i < row *col; i++)
	{
		data[i] = mat.data[i];
	}
}
