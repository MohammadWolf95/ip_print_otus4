#ifndef IP_CONFIG_H
#define IP_CONFIG_H

#include <type_traits>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

/**
* @file util.h
* @brief this header file will contain all required
* definitions and basic utilities functions.
*
* @author Dr.Zhao Zhang
*
* @date 2/28/2009
*/

template<typename ...>
using to_void = void; // maps everything to void, used in non-evaluated contexts

template<typename T, typename = void>
struct is_container : std::false_type
{};

template<typename T>
struct is_container<T,
        to_void<decltype(std::declval<T>().begin()),
                decltype(std::declval<T>().end()),
                typename T::value_type
        >> : std::true_type // will  be enabled for iterable objects
{};


template <typename T>
typename enable_if<!is_container<T>::value, void>::type
print_ip(T ip){
    auto size = sizeof(ip);
    vector<int> bytes(size);
    for(auto i = 0;i<size;++i){
        bytes[i] = (ip >> (8 * i)) & 0xFF;
    }
    reverse(bytes.begin(), bytes.end());
    for(auto it = bytes.begin();it!=bytes.end();++it){
        if(it==(bytes.end()-1)){
            cout<<*it<<endl;
            break;
        }
        cout<<*it<<'.';
    }
}

template <typename T>
typename enable_if<is_container<T>::value, void>::type
print_ip(T ip){
    cout<<"is container";
}

#endif // IP_CONFIG_H
