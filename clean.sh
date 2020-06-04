#!/usr/bin/env bash
buildDir="cmake-build-debug"

if [[ -d ${buildDir} ]]; then    
    rm -rf ${buildDir}
fi


# cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ..
# # cmake --build ${pwd}cmake-build-debug --target PerrorTest -- -j 16
# cores=`nproc`
# numberThread=`bc <<< "${cores}*2"`
# cmake --build . -- -j $numberThread

