/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "TextDiffTests.h"
#include "Ishiko/Diff/TextDiff.h"

using namespace Ishiko::Diff;
using namespace Ishiko::Tests;

TextDiffTests::TextDiffTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "TextDiff tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void TextDiffTests::ConstructorTest1(Test& test)
{
    TextDiff diff;

    ISHTF_PASS();
}
