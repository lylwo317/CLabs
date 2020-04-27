#!/usr/bin/env bash
buildDir="cmake-build-debug"

if [[ ! -d ${buildDir} ]]; then    
    mkdir ${buildDir}
fi

cd ${buildDir}

cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ..
# cmake --build ${pwd}cmake-build-debug --target PerrorTest -- -j 16
cmake --build . -- -j 16
