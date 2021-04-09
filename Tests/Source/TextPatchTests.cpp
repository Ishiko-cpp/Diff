/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "TextPatchTests.h"
#include "Ishiko/Diff/TextPatch.h"

using namespace Ishiko::Diff;
using namespace Ishiko::Tests;

TextPatchTests::TextPatchTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "TextPatch tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void TextPatchTests::ConstructorTest1(Test& test)
{
    TextPatch patch;

    ISHTF_PASS();
}
