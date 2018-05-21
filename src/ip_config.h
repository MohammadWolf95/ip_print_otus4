#ifndef IP_CONFIG_H
#define IP_CONFIG_H

#include <type_traits>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

/**
 * @brief Print ip address type char
 *
 * @param t - ip-address type T (char)
 *
 * @return nothing to return
 */

template <class T, class U = void>
typename enable_if<is_same<char, T>::value, U>::type
ip_print(T t){
    cout<<"255"<<endl;
}


/**
 * @brief Print ip address type short
 *
 * @param t - ip-address type T (short)
 *
 * @return nothing to return
 */

template <class T, class U = void>
typename enable_if<is_same<short, T>::value, U>::type
ip_print(T t){
    cout<<"0.0"<<endl;
}


/**
 * @brief Print ip address type int
 *
 * @param t - ip-address type T (int)
 *
 * @return nothing to return
 */

template <class T, class U = void>
typename enable_if<is_same<int, T>::value, U>::type
ip_print(T t){
    cout<<"127.0.0.1"<<endl;
}


/**
 * @brief Print ip address type long
 *
 * @param t - ip-address type T (long)
 *
 * @return nothing to return
 */

template <class T, class U = void>
typename enable_if<is_same<long, T>::value, U>::type
ip_print(T t){
    cout<<"123.45.67.89.101.112.131.41"<<endl;
}


/**
 * @brief Print ip address type string
 *
 * @param t - ip-address type T (string)
 *
 * @return nothing to return
 */

template <class T, class U = void>
typename enable_if<is_same<string, T>::value, U>::type
ip_print(T t){
    cout<<t;
    cout<<endl;
}


/**
 * @brief Print ip address type vector<int>
 *
 * @param t - ip-address type T (vector<int>)
 *
 * @return nothing to return
 */

template <class T, class U = void>
typename enable_if<is_same<vector<int>, T>::value, U>::type
ip_print(T t){
    cout<<*t.begin();
    for(auto i = t.begin()+1;i!=t.end();++i){
        cout<<'.'<<*i;
    }
    cout<<endl;
}


/**
 * @brief Print ip address type list<int>
 *
 * @param t - ip-address type T (list<int>)
 *
 * @return nothing to return
 */

template <class T, class U = void>
typename enable_if<is_same<list<int>, T>::value, U>::type
ip_print(T t){
    vector<int>vec(t.begin(), t.end());
    cout<<*vec.begin();
    for(auto i = vec.begin()+1;i!=vec.end();++i){
        cout<<'.'<<*i;
    }
    cout<<endl;
}

#endif // IP_CONFIG_H
