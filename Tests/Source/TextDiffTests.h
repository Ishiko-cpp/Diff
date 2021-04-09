/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_DIFF_TESTS_TEXTDIFFTESTS_H_
#define _ISHIKO_DIFF_TESTS_TEXTDIFFTESTS_H_

#include <Ishiko/TestFramework/TestFrameworkCore.h>

class TextDiffTests : public Ishiko::Tests::TestSequence
{
public:
    TextDiffTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);

private:
    static void ConstructorTest1(Ishiko::Tests::Test& test);
};

#endif
