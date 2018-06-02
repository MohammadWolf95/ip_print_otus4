#define BOOST_TEST_MODULE IpTest
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include "ip_config.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(test_ip_output)

struct cout_redirect {
    cout_redirect( std::streambuf * new_buffer ) 
        : old( std::cout.rdbuf( new_buffer ) )
    { }

    ~cout_redirect( ) {
        std::cout.rdbuf( old );
    }

private:
    std::streambuf * old;
};

int add( int i, int j ) { return i+j; }

boost::test_tools::output_test_stream output;

BOOST_AUTO_TEST_CASE(test_ip_type){
	{
		cout_redirect guard( output.rdbuf( ) );
		print_ip(char(-1));
		print_ip(short(0));
    	print_ip(int(2130706433));
    	print_ip(long(8875824491850138409));
	}

	BOOST_CHECK( output.is_equal( 	"255\n"
									"0.0\n"
									"127.0.0.1\n"
									"123.45.67.89.101.112.131.41\n" ) );
}

BOOST_AUTO_TEST_CASE(test_ip_container){
	/*output.flush();
	vector<int> ip_vec = {14,1,5,6};
    list<short> ip_list = {14,45,5,6};
    string ip_string = "140.1.5.6";
    print_ip(ip_vec);
    print_ip(ip_list);
    print_ip(ip_string);

	BOOST_CHECK( output.is_equal( 	"14.1.5.6\n"
									"14.45.5.6\n"
									"140.1.5.6\n" ) );*/

	BOOST_CHECK( output.is_equal( 	"" ) );
}

BOOST_AUTO_TEST_SUITE_END()
