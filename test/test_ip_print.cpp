#define BOOST_TEST_MODULE IpTest
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include "ip_config.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(test_ip_output)

BOOST_AUTO_TEST_CASE(test_ip_type){

	boost::test_tools::output_test_stream output;

	{
		print_ip(char(-1));
	}

	BOOST_CHECK( output.is_equal( "255\n" ) );
}

BOOST_AUTO_TEST_SUITE_END()
