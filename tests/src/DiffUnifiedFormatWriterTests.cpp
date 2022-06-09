/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "DiffUnifiedFormatWriterTests.hpp"
#include "Ishiko/Diff/DiffUnifiedFormatWriter.hpp"

using namespace Ishiko;

DiffUnifiedFormatWriterTests::DiffUnifiedFormatWriterTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DiffUnifiedFormatWriter tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DiffUnifiedFormatWriterTests::ConstructorTest1(Test& test)
{
    DiffUnifiedFormatWriter writer;

    ISHIKO_TEST_PASS();
}
