set -e

# Variables
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cmake_build_dir="${DIR}/../devtools_build"
cpplint="${DIR}/3rdparty/cpplint.py"

# This function executes command and stops
# execution if return status isn't 0
function try {
    "$@"
    status=$?
    if [ $status -ne 0 ]; then
        echo "ERROR with '$@' in $dir"
        exit $status
    fi
    return $status
}

function Header {
    echo ""
    echo "*****************************************************"
    echo "$@"
    echo "*****************************************************"
    echo ""
}

function Clean {
    rm -rf $cmake_build_dir
}

function CheckGoogleStyleInDir {
    retCode=0

    # hpp_files=`find . -name "*.hpp"`
    # if [[ $hpp_files ]]; then
    #     echo "ERROR: Please use *.h extension instead of *.hpp:"
    #     echo " - $hpp_files"
    #     retCode=1
    # fi

    echo "Checking $dir"
    sources=`find . -name "*.hpp" -or -name "*.h" -or -name "*.cpp" -or -name "*.cxx"`
    for file in $sources;
    do
        python $cpplint $file
        status=$?
        if [ $status -ne 0 ]; then
            retCode=$status
        fi
    done

    return $retCode
}

function CheckGoogleStyle {
    # Go through all directories and check Google style
    Header "Check \"Google C++ Style\""

    for dir in */;
    do
        if [ "$dir" == "3rdparty/" ]; then
            continue
        fi

        cd $dir
        try CheckGoogleStyleInDir
        cd ..
        echo ""
    done
}

function BuildCMakeProject {
    Header "Build common CMake project"

    dir=$cmake_build_dir
    mkdir -p $cmake_build_dir
    cd $cmake_build_dir
    try cmake -DWITH_CODE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug $DIR
    try make
}

function CTest {
    Header "Run all CTest tests"
    try ctest --output-on-failure
}

function GoogleTest {
    Header "Run all GoogleTest tests"

    for test in $(ls -1 ./bin/test_*)
    do
        Header "Testing $test"
        try $test
    done
}

function Main {
    # Clean
    CheckGoogleStyle
    BuildCMakeProject
    CTest
    GoogleTest
}

Main
