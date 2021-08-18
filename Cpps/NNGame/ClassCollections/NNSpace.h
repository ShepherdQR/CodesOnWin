#pragma once

#include <vector>
class NNTensor;


class NNSpace {

public:


	NNSpace(const int& iNumberRace,
		std::vector<int>* iDimDisperse);

	~NNSpace();

	bool oneStep(const int& iNumberRace,
		std::vector<int>* iDimDisperse);

	NNTensor* glance()const;

private:
	NNTensor* _ptData = nullptr;

	int _numberRace = 0; // The number of the races in the space.
};



//
//
//#include "unsupported/Eigen/CXX11/Tensor"
//class NNBoard {
//	
//public:
//	NNBoard(const int& iDim,
//		const int& iPlayer,
//		const Eigen::Vector<double, Eigen::Dynamic>* iDimDisperse);
//
//	~NNBoard();
//
//	bool oneStep(const int& iPlayer,
//		const Eigen::Vector<double, Eigen::Dynamic>* iDimDisperse);
//
//	Eigen::Tensor<double, Eigen::Dynamic>* glanceBoard()const;
//
//private:
//	Eigen::Tensor<double, Eigen::Dynamic>* ptBoard;
//	
//	int _numberPlayer;
//	int _dim;
//};