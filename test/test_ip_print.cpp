#include "../src/ip_config.h"

#define BOOST_TEST_MODULE test_ip_print
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
using namespace std;

BOOST_AUTO_TEST_SUITE(test_ip_output)

BOOST_AUTO_TEST_CASE(test_ip_type){
	print_ip(char(-1));

	boost::test_tools::output_test_stream output;
	BOOST_CHECK( output.is_equal( "255\n" ) );
}

BOOST_AUTO_TEST_SUITE_END()
