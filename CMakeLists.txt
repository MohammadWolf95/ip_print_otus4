cmake_minimum_required(VERSION 3.2) 

project(ip_print VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")

set(TEST_PATH "${PROJECT_TEST_DIR}/test")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(ip_print ${
				SOURCE_PATH}/main.cpp
				SOURCE_PATH}/ip_config.h)

#add_library()

#add_executable(test_ip_print ${TEST_PATH}/test_ip_print.cpp)

add_compile_options(-std=c++11)

#set_target_properties(ip_print test_ip_print PROPERTIES
set_target_properties(ip_print PROPERTIES
		CXX_STANDARD 14
		CXX_STANDARD_REQUIRED ON
		COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

#set_target_properties(test_ip_print PROPERTIES
#	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#  	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)

#target_link_libraries(test_ip_print
#	${Boost_LIBRARIES}
#)

install(TARGETS ip_print RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT abdulvadudovmagomed@mail.ru)

include(CPack)

enable_testing()

add_subdirectory(test)
#add_test(test_ip_valid test_ip_print)