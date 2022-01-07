/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TESTS_ALGORITHMSTESTS_H_
#define _ISHIKO_CPP_DIFF_TESTS_ALGORITHMSTESTS_H_

#include <Ishiko/Tests/Core.hpp>

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
    static void WagnerFischerAlgorithmTest6(Ishiko::Tests::Test& test);
    static void WagnerFischerAlgorithmTest7(Ishiko::Tests::Test& test);
    static void WagnerFischerAlgorithmTest8(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest1(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest2(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest3(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest4(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest5(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest6(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest7(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest8(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest9(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest10(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest11(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest12(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest13(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest14(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest15(Ishiko::Tests::Test& test);
    static void MyersAlgorithmTest16(Ishiko::Tests::Test& test);
};

#endif
