#include <iostream>
#include <src/ip_config.h>

using namespace std;

int main(int argc, char *argv[])
{
    ip_print(static_cast<char>(-1));
    ip_print(static_cast<short>(0));
    ip_print(static_cast<int>(2130706433));
    ip_print(static_cast<long>(8875824491850138409));

    

    string str = "10.54.6.1";
    ip_print(str);

    vector<int> ip = {1, 56, 21, 45};
    ip_print(ip);

    list<int> ip_list = {1, 50, 70, 111};
    ip_print(ip_list);
}
