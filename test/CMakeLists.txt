if(BUILD_TESTING)
	find_package (Boost COMPONENTS unit_test_framework REQUIRED)
	
	add_executable(ip_test test_ip_print.test.cpp)

	set_target_properties(ip_test PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra
		COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  		INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
  		INCLUDE_DIRECTORIES ${SOURCE_PATH}
  		LINK_LIBRARIES ${Boost_LIBRARIES}
	)

	add_test(IpTest ip_test)

endif()