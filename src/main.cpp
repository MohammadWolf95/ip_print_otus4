#include <iostream>
#include <src/ip_config.h>

using namespace std;

int main(int argc, char *argv[])
{
    print_ip(char(-1));
    print_ip(short(0));
    print_ip(int(2130706433));
    print_ip(long(8875824491850138409));

    vector<int> ip = {14,1,5,6};

    print_ip(ip);
}
