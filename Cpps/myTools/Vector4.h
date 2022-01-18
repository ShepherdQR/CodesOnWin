/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-01-18 23:06:35
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-01-18 23:11:39
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/

class Vector4 {

public:

    public:
        Vector4() : e{0,0,0,0} {}
        Vector4(double e0, double e1, double e2, double e3)
         : e{e0, e1, e2, e3} {}

        double& x()  { return e[0]; }
        double& y()  { return e[1]; }
        double& z()  { return e[2]; }
        double& i()  { return e[3]; }

        Vector4 operator-() const { return Vector4(-e[0], -e[1], -e[2], -e[3]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        Vector4& operator+=(const Vector4 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            e[3] += v.e[3];
            return *this;
        }

        Vector4& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            e[3] *= t;
            return *this;
        }

        Vector4& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length() const {
            return sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]+ e[3]*e[3];
        }

    public:
        double e[4];







    // Vector4() : x(0),y(0),z(0),i(0) {}
    // Vector3(double e0, double e1, double e2, double e3) 
    // : x(e0),y(e1),z(e2),i(d3) {}

    // double x;
    // double y;
    // double z;
    // double i;
};