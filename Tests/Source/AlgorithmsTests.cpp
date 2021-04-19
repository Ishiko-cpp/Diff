/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "AlgorithmsTests.h"
#include "Ishiko/Diff/Algorithms.h"

using namespace Ishiko::Diff;
using namespace Ishiko::Tests;

AlgorithmsTests::AlgorithmsTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Algorithms tests", environment)
{
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 1", WagnerFischerAlgorithmTest1);
}

void AlgorithmsTests::WagnerFischerAlgorithmTest1(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("", "");

    ISHTF_FAIL_IF_NEQ(distance, 0);
    ISHTF_PASS();
}
