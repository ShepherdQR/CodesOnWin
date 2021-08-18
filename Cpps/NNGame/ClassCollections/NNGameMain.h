#pragma once

#include <iostream>
//
//#include "unsupported/Eigen/CXX11/Tensor"
//#include "Eigen\Dense"
//
//const int MAX_DIM=11;
//
//template<class T>
//void release(T*& iT) {
//	if (iT)
//	{
//		delete iT;
//		iT = nullptr;
//	}
//}
//
//void testFunc1() {
//	using namespace std;
//	Eigen::Vector<double, Eigen::Dynamic>* pt;
//
//	int row(4), col(3);
//	pt = new Eigen::Vector<double, Eigen::Dynamic>;
//	pt->resize(row);
//	(*pt) << 1, 2, 3, 4;
//	cout << *pt << endl;
//
//
//
//	Eigen::Tensor<double, MAX_DIM>* ptBoard;
//
//	Eigen::array<Eigen::DenseIndex, MAX_DIM> offsets;
//
//
//
//
//	Eigen::Tensor<int, 3> a(2,4,3);
//	a.setValues( {
//		{ {0, 100, 200}, {300, 400, 500}, {600, 700, 800}, {900, 1000, 1100} },
//		{ { 1, 1001, 2001 }, { 3001, 4001, 5001 }, { 6001, 7001, 8001 }, { 9001, 10001, 11001 } }
//
//});
//	Eigen::Tensor<int,2> row_3 = a.chip(0,  0);
//	Eigen::Tensor<int, 2> col_2 = a.chip(1,  0);
//	cout << "a" << endl << a << endl;
//	cout << "row_3" << endl << row_3 << endl;
//	cout << "col_2" << endl << col_2 << endl;
//
//
//
//	ptBoard = new Eigen::Tensor<double, MAX_DIM>;
//
//	/*int itt = 4;
//	std::array<int, MAX_DIM> d;*/
//	//ptBoard->resize(*pt);
//	//(*ptBoard) << 1, 2, 3, 4;
//
//	cout << *ptBoard << endl;
//
//
//
//	release(pt);
//	release(ptBoard);
//}
//
//void testFunc() {
//	using namespace std;
//	Eigen::Vector<double, Eigen::Dynamic>* pt;
//
//	int row(4), col(3);
//	pt = new Eigen::Vector<double, Eigen::Dynamic>;
//	pt->resize(row);
//	cout << *pt << endl;
//}
//
//void test() {
//	using namespace std;
//
//	Eigen::Tensor<double, 3> epsilon(3, 3, 3);
//	epsilon.setZero();
//	epsilon(0, 2, 2) = 1;
//	epsilon(1, 2, 0) = 1;
//	epsilon(2, 0, 1) = 1;
//	epsilon(1, 0, 2) = -1;
//	epsilon(2, 1, 0) = -1;
//	epsilon(0, 2, 1) = -1;
//	cout << epsilon << endl;
//
//
//
//	using namespace Eigen;
//
//	Matrix2d a;
//	a << 1, 2,
//		3, 4;
//	MatrixXd b(2, 2);
//	b << 2, 3,
//		1, 4;
//	cout << "a + b =\n" << a + b << endl;
//	cout << "a - b =\n" << a - b << endl;
//	cout << "Doing a += b;" << endl;
//	a += b;
//	cout << "Now a =\n" << a << endl;
//	cout << "a^T=  " << a.transpose() << endl;
//	cout << "a*b= " << a * b << endl;
//	Vector3d v(1, 2, 3);
//	Vector3d w(1, 0, 0);
//	cout << "-v + w - v =\n" << -v + w - v << endl;
//	cout << v << endl;
//	cout << v.transpose() << endl;
//	system("pause");
//}