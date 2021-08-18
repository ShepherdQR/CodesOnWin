#pragma once

#include <vector>

class NNRender{
public:
	NNRender(std::vector<int>* iDimDisperse);
	~NNRender();

	void redraw();

};