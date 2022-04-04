/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "TextChunkTests.hpp"
#include "Ishiko/Diff/TextChunk.hpp"

using namespace Ishiko;

TextChunkTests::TextChunkTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "TextChunk tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void TextChunkTests::ConstructorTest1(Test& test)
{
    TextChunk chunk(3, 5, TextChunk::eIdentical, "abc");

    ISHIKO_TEST_FAIL_IF_NEQ(chunk.originalPosition(), 3);
    ISHIKO_TEST_FAIL_IF_NEQ(chunk.newPosition(), 5);
    ISHIKO_TEST_FAIL_IF_NEQ(chunk.type(), TextChunk::eIdentical);
    ISHIKO_TEST_FAIL_IF_NEQ(chunk.text(), "abc");
    ISHIKO_TEST_PASS();
}
