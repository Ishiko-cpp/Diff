/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "TextChunkTests.h"
#include "Ishiko/Diff/TextChunk.h"

using namespace Ishiko::Diff;
using namespace Ishiko::Tests;

TextChunkTests::TextChunkTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "TextChunk tests", environment)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void TextChunkTests::ConstructorTest1(Test& test)
{
    TextChunk chunk(TextChunk::eIdentical, "");

    ISHTF_PASS();
}
