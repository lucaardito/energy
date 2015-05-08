#!/bin/bash

./script/perf_record.sh "./bin/c-alloc" "./data" "alloc-c"
./script/perf_record.sh "./bin/cpp-alloc" "./data" "alloc-cpp"
