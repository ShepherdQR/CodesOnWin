#pragma once

#include<vector>

class NNTensor {

public:

	NNTensor(std::vector<int>* ipvecSpaceMetric);
	~NNTensor();

	bool setValue(const double& iVal,
		std::vector<int>* ipvecLocation);

	void display();
	
private:

	std::vector<int>* _pvecSpaceMetric = nullptr;
	std::vector<double>* _pvecSpaceParticle = nullptr;

	std::vector<int> __vecQuickLocate;

	int _dim = 0;
};