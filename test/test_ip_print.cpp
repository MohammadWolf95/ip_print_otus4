#define BOOST_TEST_MODULE IpTest
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include "ip_config.h"

using namespace std;

//BOOST_AUTO_TEST_SUITE(test_ip_output)

int add( int i, int j ) { return i+j; }

BOOST_AUTO_TEST_CASE(test_ip_type){
	/*print_ip(char(-1));

	boost::test_tools::output_test_stream output;
	BOOST_CHECK( output.is_equal( "255\n" ) );*/
	BOOST_CHECK_EQUAL( add( 2,2 ), 4 );
}

//BOOST_AUTO_TEST_SUITE_END()
