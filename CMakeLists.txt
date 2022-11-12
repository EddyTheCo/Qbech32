cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
include(local_conf.cmake OPTIONAL)
project(Qtbech32 VERSION 0.1 DESCRIPTION "Qt bech32 library " LANGUAGES CXX)


set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
	set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
		STRING "Choose the type of build." FORCE)
	# Set the possible values of build type for cmake-gui
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
		"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_library(qbech32 include/encoding/qbech32.hpp qbech32.cpp src/bech32.cpp
        src/bech32.h src/segwit_addr.cpp src/segwit_addr.h src/iota_addr.h src/iota_addr.cpp)

find_package(Qt6 REQUIRED COMPONENTS Core)
target_link_libraries(qbech32 PUBLIC  Qt6::Core )

target_include_directories(qbech32 PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	"$<INSTALL_INTERFACE:include>")
target_include_directories(qbech32 PRIVATE  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
	"$<INSTALL_INTERFACE:src>")

install(TARGETS qbech32 EXPORT qbech32Targets DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/)

install(EXPORT qbech32Targets
	FILE qbech32Targets.cmake
	DESTINATION lib/cmake/qbech32
	)
include(CMakePackageConfigHelpers)
# generate the config file that is includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
	"${CMAKE_CURRENT_BINARY_DIR}/qbech32Config.cmake"
	INSTALL_DESTINATION "lib/cmake/qbech32"
	NO_SET_AND_CHECK_MACRO
	NO_CHECK_REQUIRED_COMPONENTS_MACRO
	)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/qbech32ConfigVersion.cmake"
	VERSION "0.1.1.0"
	COMPATIBILITY AnyNewerVersion
	)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/qbech32Config.cmake
	${CMAKE_CURRENT_BINARY_DIR}/qbech32ConfigVersion.cmake
	DESTINATION lib/cmake/qbech32
	)
export(EXPORT qbech32Targets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/qbech32Targets.cmake"
	)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
