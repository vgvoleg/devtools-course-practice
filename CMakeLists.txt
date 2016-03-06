cmake_minimum_required(VERSION 2.8.6)
project(DevTools)

# Enable C++11
# FIXME(Kornyakov): use other flags for GCC
set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")

# Setup output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_PDB_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

foreach(cfg ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER "${cfg}" cfg)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${cfg} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${cfg} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${cfg} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_PDB_OUTPUT_DIRECTORY_${cfg} ${CMAKE_BINARY_DIR}/lib)
endforeach()

# Add Google Test
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/gtest")
set(LIBRARY_DEPS "gtest")

# Include all modules
file(GLOB SUBDIRS "${CMAKE_CURRENT_SOURCE_DIR}/modules/*")
foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach()

# Report variables
message(STATUS "")
message(STATUS "General configuration for ${PROJECT_NAME}")
message(STATUS "==================================")
message(STATUS "")
message(STATUS "   Configuration:        ${CMAKE_BUILD_TYPE}")
message(STATUS "   Enable code coverage: ${WITH_CODE_COVERAGE}")
message(STATUS "   Detected modules:")
foreach(subdir ${SUBDIRS})
    get_filename_component(DIR_NAME ${subdir} NAME)
    message(STATUS "    - ${DIR_NAME}")
endforeach()
message(STATUS "")

# Enable testing
enable_testing()
