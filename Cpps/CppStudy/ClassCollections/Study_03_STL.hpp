/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2021-08-14 17:49:00
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-06-24 23:45:43
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

void stlTransform20210824()
{
    vector<int> num{2,3,5,7,11};

    transform(num.begin(), num.end(), ostream_iterator<int>(cout, " "), negate<int>());
    cout << endl;
}


double funcSquare20210824(const double& x){return x*x;}
void stlIO20210824()
{
    cout << endl;
    // input, until end(default is ctrl+z)
    transform(istream_iterator<double>(cin), istream_iterator<double>(),
    ostream_iterator<double>(cout, "\t"), funcSquare20210824);
    cout << endl;
}


template<class T, class InputIterator, class OutputIterator>
void funcSort20210824(InputIterator first, InputIterator last, OutputIterator result){
    vector<T> vecOri;
    for(;first!=last;++first)
        vecOri.push_back(*first);
    sort(vecOri.begin(), vecOri.end());
    copy(vecOri.begin(), vecOri.end(), result);
} 
void stlSort20210824()
{
    double array[5] = {2,10,1,7,4};
    funcSort20210824<double>(array, array+5,ostream_iterator<double>(cout, " "));cout << endl;

    funcSort20210824<int>(istream_iterator<int>(cin),istream_iterator<int>(),ostream_iterator<int>(cout, ", "));cout << endl;
}

//advance(p,n) do n times ++p
// distance(first, last) 





namespace studyVector{

    // [T00002] initialization
    void testFunc20210811(){
        int size = 6;
        vector<int> vecOut(size);
        for(const auto& cur:vecOut)
            cout << cur << endl;//six zeros
    }


    // [T00001] Test IO 
    void funcTestVector20210614()
    {
        vector<vector<int>> matrix;
        int valX(0), valY(0);

        while(cin>>valX >> valY){
            vector<int> vectorTemp;
            vectorTemp.push_back(valX);
            vectorTemp.push_back(valY);
            matrix.push_back(vectorTemp);
        }

        for(auto vectorCur:matrix)
            cout << vectorCur[0] << "\t" << vectorCur[1] << endl;
    }

    
}



