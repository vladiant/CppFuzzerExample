# CppFuzzerExample

libFuzzer can be combined with [AddressSanitizer](https://clang.llvm.org/docs/AddressSanitizer.html) (ASAN) or [UndefinedBehaviorSanitizer](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html) (UBSAN).

## Fuzz Targets Features
* The fuzzing engine will execute the fuzz target many times with different inputs in the same process.
* It must tolerate any kind of input (empty, huge, malformed, etc).
* It must not exit() on any input.
* It may use threads but ideally all threads should be joined at the end of the function.
* It must be as deterministic as possible. Non-determinism (e.g. random decisions not based on the input bytes) will make fuzzing inefficient.
* It must be fast. Try avoiding cubic or greater complexity, logging, or excessive memory consumption.
* Ideally, it should not modify any global state (although that’s not strict).
* Usually, the narrower the target the better. E.g. if your target can parse several data formats, split it into several targets, one per format.

## References
* [libFuzzer – a library for coverage-guided fuzz testing](https://llvm.org/docs/LibFuzzer.html)
* [An introduction to LLVM libFuzzer](https://www.moritz.systems/blog/an-introduction-to-llvm-libfuzzer/)
* [Secure Coding in C and C++ Using Fuzz Testing](https://www.code-intelligence.com/blog/secure-coding-cpp-using-fuzzing)
* <https://github.com/OFxGL/FuzzingTest>
* <https://github.com/kshitijl/minimal-fuzzing-example/>