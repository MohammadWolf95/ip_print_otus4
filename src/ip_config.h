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
 * @file
 * @brief функция возвращает бла-бла
 * @param параметр - это
 *
 */

template<typename ...>
using to_void = void;

template<typename T, typename = void>
struct is_container : std::false_type
{};

template<typename T>
struct is_container<T,
        to_void<decltype(std::declval<T>().begin()),
                decltype(std::declval<T>().end()),
                typename T::value_type
        >> : std::true_type
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
typename enable_if<is_container<T>::value&&!is_same<T, string>::value, void>::type
print_ip(T ip){
    auto ip_end_it = ip.end();
    advance(ip_end_it, -1);
    for(auto it = ip.begin();it!=ip.end();++it){
        if(it == ip_end_it){
            cout<<*it<<endl;
            break;
        }
        cout<<*it<<'.';
    }
}

template <typename T>
typename enable_if<is_same<T, string>::value, void>::type
print_ip(T ip){
    cout<<ip<<endl;
}

#endif // IP_CONFIG_H
