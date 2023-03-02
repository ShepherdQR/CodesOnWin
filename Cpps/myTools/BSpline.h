/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-09-06 23:01:44
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2023-03-02 22:10:55
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#pragma once

#include"Vector3.h"
#include <vector>


class BSpline{
public:

    /*explicit*/ BSpline(std::vector<Vector3> ivecPoint, const int k);

    std::shared_ptr<std::vector<Vector3> > _uplistPoint;
private:

    double deBoor_Cox(const int iIndexControl,const int ik, const double t);

    int _k{4};// k阶，k-1次
    std::vector<double> _vecKnot; // number =  numberPoint + _k + 1
};


BSpline::BSpline(std::vector<Vector3> ivecPoint, const int k)
{
    if(k>0){
        _k = k;
    }

    _vecKnot.clear();
    //double totalVal = (ivecPoint.size()+_k)*(ivecPoint.size()+_k)*0.5;
    for(int i=0;i<ivecPoint.size()+_k;++i){
        _vecKnot.push_back(i);
        std::cout << " " << _vecKnot[i] << std::endl;
    }

    auto tLeft = _k-1; // 4阶就是3次
    auto  tRight = ivecPoint.size()+1;

    _uplistPoint = std::make_shared<std::vector<Vector3> >();

    int inserctionNumber{50};
    double steps =(tRight - tLeft) / (inserctionNumber -1);
    for(int i = 0;i<inserctionNumber;++i){

        Vector3 p;

        double t = tLeft + i* steps;
        for(int j=0;j<ivecPoint.size();++j){
            double cof{deBoor_Cox(j, _k-1, t)};

            p += cof * ivecPoint[j];
        }
        _uplistPoint->push_back(p);
    }

   
    // for(int t = tLeft;t<tRight;++t){//t ok

    //     Vector3 p;

    //     //double t = tLeft + i* steps;
    //     for(int j=0;j<ivecPoint.size();++j){
    //         double cof{deBoor_Cox(j, _k-1, t)};

    //         p += cof * ivecPoint[j];

    //     }
    //     _uplistPoint->push_back(p);
    // }

}


double BSpline::deBoor_Cox(const int iIndexControl,const int ik, const double t)
{
    if(ik==0)
    {
        if(_vecKnot[iIndexControl] <t && t< _vecKnot[iIndexControl+1]){
            return 1.0;
        }
        else{
            return 0.0;
        }
    }

    double u1{_vecKnot[iIndexControl+ik]-_vecKnot[iIndexControl]};
    double u2{_vecKnot[iIndexControl+ik+1]-_vecKnot[iIndexControl+1]};

    
    double u1_0{t-_vecKnot[iIndexControl]};
    double u2_0{_vecKnot[iIndexControl+ik+1]-t};

    double cof1{ (u1 == 0.0)?0.0:       u1_0 / u1 };
    double cof2{(u2 == 0.0)?0.0: u2_0/u2};

    return cof1 * deBoor_Cox(iIndexControl, ik-1, t) + cof2*deBoor_Cox(iIndexControl+1,ik-1, t);
}


