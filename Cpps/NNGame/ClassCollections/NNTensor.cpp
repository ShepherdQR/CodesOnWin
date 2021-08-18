#include "NNTensor.h"

#include <iostream>

NNTensor::NNTensor(std::vector<int>* ipvecSpaceMetric)
{
	if (!ipvecSpaceMetric || ipvecSpaceMetric->empty())
		return ;

	int numberParticle(1);
	_dim = ipvecSpaceMetric->size();
	numberParticle = (*ipvecSpaceMetric)[0];
	_pvecSpaceMetric = new std::vector<int>(_dim);
	for (int i = 0; i < _dim; ++i) {
		(*_pvecSpaceMetric)[i] = (*ipvecSpaceMetric)[i];
		__vecQuickLocate.push_back(numberParticle);
		numberParticle *= (*ipvecSpaceMetric)[i];
	}
	_pvecSpaceParticle = new std::vector<double>(numberParticle);
}


bool NNTensor::setValue(const double& iVal,
	std::vector<int>* ipvecLocation)
{
	int indexInternal(0);

	for (int i = 0; i < _dim; ++i) {
		int tempIndexVal = (*ipvecLocation)[i];
		if ((tempIndexVal < 0) || (tempIndexVal >= (*_pvecSpaceMetric)[i])) {
			return false;
		}
		indexInternal += tempIndexVal * __vecQuickLocate[i];
	}
	(*_pvecSpaceParticle)[indexInternal] = iVal;

	return true;
}






template<class T>
void release(T*& iT) {
	if (iT)
	{
		delete iT;
		iT = nullptr;
	}
}

NNTensor::~NNTensor()
{
	release(_pvecSpaceMetric);
	release(_pvecSpaceParticle);
}


void NNTensor::display()
{
	if (!_pvecSpaceParticle)
		return;

	if (__vecQuickLocate.size() == 2){
		for (double& cur : *_pvecSpaceParticle) {
			std::cout << cur << std::endl;
		}
	}

	if (__vecQuickLocate.size() >=3) {
		for (int i = 0; i < _dim; ++i) {
			std::cout << (* _pvecSpaceParticle )[i] << " ";
		}
	}

}