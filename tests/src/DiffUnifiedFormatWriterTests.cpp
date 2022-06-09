/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "DiffUnifiedFormatWriterTests.hpp"
#include "Ishiko/Diff/DiffUnifiedFormatWriter.hpp"
#include <boost/filesystem.hpp>

using namespace Ishiko;

DiffUnifiedFormatWriterTests::DiffUnifiedFormatWriterTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DiffUnifiedFormatWriter tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void DiffUnifiedFormatWriterTests::ConstructorTest1(Test& test)
{
    boost::filesystem::path output =
        test.context().getTestOutputPath("DiffUnifiedFormatWriterTests_ConstructorTest1.txt");

    Error error;
    DiffUnifiedFormatWriter writer(output, error);
    writer.close();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_FILES_NEQ("DiffUnifiedFormatWriterTests_ConstructorTest1.txt",
        "DiffUnifiedFormatWriterTests_ConstructorTest1.txt");
    ISHIKO_TEST_PASS();
}
