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
	}

	BOOST_CHECK( output.is_equal( "255\n" ) );
}

BOOST_AUTO_TEST_SUITE_END()
