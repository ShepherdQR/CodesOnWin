/* ===========
//  * Author: Shepherd Qirong
//  * Date: 2022-07-23 22:40:28
//  * Github: https://github.com/ShepherdQR
//  * LastEditors: Shepherd Qirong
//  * LastEditTime: 2022-07-23 22:42:01
//  * Copyright (c) 2019--20xx Shepherd Qirong. All rights reserved.
*/


#pragma once

#include<iostream>
#include<type_traits>
#include<memory>
#include<vector>
#include<array>
#include<string>
#include <functional>
#include <algorithm>
#include<set>
#include<span>


namespace Tools{



    // cout << enum_class_member << endl
    template<typename T>
    std::ostream& operator<<(
        typename std::enable_if<std::is_enum<T>::value,
        std::ostream>::type& stream, const T& e)
    {
        return stream << static_cast<typename std::underlying_type<T>::type>(e);
    }


}