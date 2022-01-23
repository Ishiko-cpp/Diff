/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "TextPatchTests.h"
#include "Ishiko/Diff/TextPatch.h"

using namespace Ishiko::Diff;
using namespace Ishiko::Tests;

TextPatchTests::TextPatchTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "TextPatch tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void TextPatchTests::ConstructorTest1(Test& test)
{
    TextPatch patch;

    ISHIKO_PASS();
}
