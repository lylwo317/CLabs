#!/usr/bin/env bash
buildDir="cmake-build-debug"

if [[ ! -d ${buildDir} ]]; then    
    mkdir ${buildDir}
fi

cd ${buildDir}

cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" ..
# cmake --build ${pwd}cmake-build-debug --target PerrorTest -- -j 16
cores=`nproc`
numberThread=`bc <<< "${cores}*2"`
cmake --build . -- -j $numberThread

cd ..

if [[ -f ${buildDir}/compile_commands.json ]]; then
    ln -sf ${buildDir}/compile_commands.json
fi
