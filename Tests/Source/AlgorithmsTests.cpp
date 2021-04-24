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
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 2", WagnerFischerAlgorithmTest2);
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 3", WagnerFischerAlgorithmTest3);
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 4", WagnerFischerAlgorithmTest4);
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 5", WagnerFischerAlgorithmTest5);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 1", MyersAlgorithmTest1);
}

void AlgorithmsTests::WagnerFischerAlgorithmTest1(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("", "");

    ISHTF_FAIL_IF_NEQ(distance, 0);
    ISHTF_PASS();
}

void AlgorithmsTests::WagnerFischerAlgorithmTest2(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("abc", "");

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::WagnerFischerAlgorithmTest3(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("", "abc");

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::WagnerFischerAlgorithmTest4(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("kitten", "sitting");

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::WagnerFischerAlgorithmTest5(Test& test)
{
    size_t distance1 = WagnerFischerAlgorithm("kitten", "smitten");
    size_t distance2 = WagnerFischerAlgorithm("kitten", "mitten");
    size_t distance3 = WagnerFischerAlgorithm("kitten", "kitty");
    size_t distance4 = WagnerFischerAlgorithm("kitten", "fitting");
    size_t distance5 = WagnerFischerAlgorithm("kitten", "written");
    size_t distance6 = WagnerFischerAlgorithm("Saturday", "Sunday");

    ISHTF_FAIL_IF_NEQ(distance1, 2);
    ISHTF_FAIL_IF_NEQ(distance2, 1);
    ISHTF_FAIL_IF_NEQ(distance3, 2);
    ISHTF_FAIL_IF_NEQ(distance4, 3);
    ISHTF_FAIL_IF_NEQ(distance5, 2);
    ISHTF_FAIL_IF_NEQ(distance6, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest1(Test& test)
{
    size_t distance = MyersAlgorithm("", "");

    ISHTF_FAIL_IF_NEQ(distance, 0);
    ISHTF_PASS();
}
