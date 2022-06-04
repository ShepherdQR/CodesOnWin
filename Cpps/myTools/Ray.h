/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-01-19 21:36:50
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-02-01 23:01:21
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

#include"Vector3.h"

#pragma once




class Ray {
    public:

        Ray(const Vector3& origin, const Vector3& direction)
            : _origin(origin), _direction(direction)
        {}

        Vector3 at(double t) const {
            return _origin + t*_direction;
        }

        Color3 sky();

        Color3 sphere(const Vector3& iCenter,  const double iRadus);


        

        Vector3 _origin;
        Vector3 _direction;
};

#include <iostream>
Color3 Ray::sky()
{
    
    Vector3 unit_direction = unit_vector(_direction);
    auto t = 0.5*(unit_direction.y() + 1.0);
    // the t ranges as the ray varying along the tip of the pyramid and the each point of the bottom of the pyramid, it varys in range of about (0.68, 0.85)
    //std::cout << t << std::endl;
    return (1.0-t)*Color3(1.0, 1.0, 1.0) + t*Color3(0.5, 0.7, 1.0);
}

Color3 Ray::sphere(const Vector3& iCenter,  const double iRadus)
{
    Vector3 oc = _origin - iCenter;
    auto a = _direction.length_squared();//dot(_direction, _direction);
    auto b = /*2.0 * */dot(oc, _direction);// the following equation, devided by 2
    auto c = dot(oc, oc) - iRadus*iRadus;
    auto discriminant = b*b - /*4* */a*c;

    // Can be hitted
    if (discriminant >= 0)
    {
        /* ===========
            // Find the nearest root that lies in the acceptable range.
            auto root = (-half_b - sqrtd) / a;
            if (root < t_min || t_max < root) {
                root = (-half_b + sqrtd) / a;
                if (root < t_min || t_max < root)
                    return false;
            }

            rec.t = root;
            rec.p = r.at(rec.t);
            rec.normal = (rec.p - center) / radius;


        */



        double hitP(-1.);
        //return Vector3{1,0,0};
        hitP = (-b - sqrt(discriminant) ) / (/*2.0**/a);
        if(hitP > 0.){
            Vector3 N = unit_vector(this->at(hitP) - iCenter);
            return 0.5*Color3(N.x()+1, N.y()+1, N.z()+1);
        }
    }


    
    return Ray::sky();

}