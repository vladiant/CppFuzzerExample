# fuzztest library

## Unit test mode
```
cmake .. -DCMAKE_CXX_COMPILER=/usr/bin/clang++ 
make
./FuzztestExample
```

## Fuzzing mode
```
cmake .. -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DFUZZTEST_FUZZING_MODE=on
make
./FuzztestExample --fuzz=MyTestSuite.IntegerAdditionCommutes
```

## Compatibility mode
```
CC=clang CXX=clang++ cmake -DCMAKE_BUILD_TYPE=RelWithDebug -DFUZZTEST_COMPATIBILITY_MODE=libfuzzer ..
make
./FuzztestExample --fuzz=MyTestSuite.IntegerAdditionCommutes
```

## References
* <https://github.com/google/fuzztest>
* [Quickstart with CMake](https://github.com/google/fuzztest/blob/main/doc/quickstart-cmake.md#quickstart-with-cmake)

