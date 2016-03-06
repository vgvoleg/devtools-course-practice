# Declare variables for binaries' names
set(MODULE      "kornyakov-kirill-scalc")
set(LIBRARY     "lib_${MODULE}")
set(TESTS       "test_${MODULE}")
set(APPLICATION "${MODULE}")

# Include directory with public headers
include_directories("./")

# Add all submodules
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(application)

#############################################
##### Testing
#############################################

include("CTestTests.txt")
