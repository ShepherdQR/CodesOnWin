
#include "NNSpace.h"
#include "NNTensor.h"



NNSpace::NNSpace(const int& iNumberRace,
	std::vector<int>* iDimDisperse)
{
	_numberRace = iNumberRace >= 2 ? iNumberRace : 2;
	_ptData = new NNTensor(iDimDisperse);
}

NNSpace::~NNSpace() 
{
	if (_ptData) {
		delete _ptData;
		_ptData = nullptr;
	}
}

bool NNSpace::oneStep(const int& iNumberRace,
	std::vector<int>* iDimDisperse)
{
	_ptData->setValue(iNumberRace, iDimDisperse);
	return true;
}
NNTensor* NNSpace::glance()const
{
	return nullptr;
}







//NNBoard::
//NNBoard(const int& iDim,
//	const int& iPlayer,
//	const Eigen::Vector<double, Eigen::Dynamic>* iDimDisperse)
//{
//	_dim = iDim >= 1 ? iDim : 1;
//	_numberPlayer = iPlayer >= 2 ? iDim : 2;
//
//
//}
//NNBoard::
//~NNBoard() 
//{
//
//}
//bool NNBoard::oneStep(const int& iPlayer,
//	const Eigen::Vector<double, Eigen::Dynamic>* iDimDisperse)
//{
//	return true;
//}
//Eigen::Tensor<double, Eigen::Dynamic>* NNBoard::glanceBoard()const
//{
//	return nullptr;
//}