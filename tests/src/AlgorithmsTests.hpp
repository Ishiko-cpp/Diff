/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TESTS_ALGORITHMSTESTS_HPP_
#define _ISHIKO_CPP_DIFF_TESTS_ALGORITHMSTESTS_HPP_

#include <Ishiko/Tests/Core.hpp>

class AlgorithmsTests : public Ishiko::TestSequence
{
public:
    AlgorithmsTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void WagnerFischerAlgorithmTest1(Ishiko::Test& test);
    static void WagnerFischerAlgorithmTest2(Ishiko::Test& test);
    static void WagnerFischerAlgorithmTest3(Ishiko::Test& test);
    static void WagnerFischerAlgorithmTest4(Ishiko::Test& test);
    static void WagnerFischerAlgorithmTest5(Ishiko::Test& test);
    static void WagnerFischerAlgorithmTest6(Ishiko::Test& test);
    static void WagnerFischerAlgorithmTest7(Ishiko::Test& test);
    static void WagnerFischerAlgorithmTest8(Ishiko::Test& test);
    static void MyersAlgorithmTest1(Ishiko::Test& test);
    static void MyersAlgorithmTest2(Ishiko::Test& test);
    static void MyersAlgorithmTest3(Ishiko::Test& test);
    static void MyersAlgorithmTest4(Ishiko::Test& test);
    static void MyersAlgorithmTest5(Ishiko::Test& test);
    static void MyersAlgorithmTest6(Ishiko::Test& test);
    static void MyersAlgorithmTest7(Ishiko::Test& test);
    static void MyersAlgorithmTest8(Ishiko::Test& test);
    static void MyersAlgorithmTest9(Ishiko::Test& test);
    static void MyersAlgorithmTest10(Ishiko::Test& test);
    static void MyersAlgorithmTest11(Ishiko::Test& test);
    static void MyersAlgorithmTest12(Ishiko::Test& test);
    static void MyersAlgorithmTest13(Ishiko::Test& test);
    static void MyersAlgorithmTest14(Ishiko::Test& test);
    static void MyersAlgorithmTest15(Ishiko::Test& test);
    static void MyersAlgorithmTest16(Ishiko::Test& test);
};

#endif
