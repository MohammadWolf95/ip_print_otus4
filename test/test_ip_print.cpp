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

BOOST_AUTO_TEST_CASE(test_ip_type){

	boost::test_tools::output_test_stream output;
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

BOOST_AUTO_TEST_SUITE_END()
