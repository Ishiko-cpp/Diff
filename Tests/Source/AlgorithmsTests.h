/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_DIFF_TESTS_ALGORITHMSTESTS_H_
#define _ISHIKO_DIFF_TESTS_ALGORITHMSTESTS_H_

#include <Ishiko/TestFramework/TestFrameworkCore.h>

class AlgorithmsTests : public Ishiko::Tests::TestSequence
{
public:
    AlgorithmsTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void WagnerFischerAlgorithmTest1(Ishiko::Tests::Test& test);
    static void WagnerFischerAlgorithmTest2(Ishiko::Tests::Test& test);
    static void WagnerFischerAlgorithmTest3(Ishiko::Tests::Test& test);
    static void WagnerFischerAlgorithmTest4(Ishiko::Tests::Test& test);
    static void WagnerFischerAlgorithmTest5(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest1(Ishiko::Tests::Test& test);
};

#endif
