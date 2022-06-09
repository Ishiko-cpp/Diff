/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "DiffUnifiedFormatWriterTests.hpp"
#include "Ishiko/Diff/DiffUnifiedFormatWriter.hpp"
#include "Ishiko/Diff/TextDiff.hpp"
#include "Ishiko/Diff/TextPatch.hpp"
#include <boost/filesystem.hpp>

using namespace Ishiko;

DiffUnifiedFormatWriterTests::DiffUnifiedFormatWriterTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "DiffUnifiedFormatWriter tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("write test 1", WriteTest1);
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

void DiffUnifiedFormatWriterTests::WriteTest1(Test& test)
{
    boost::filesystem::path originalFile = test.context().getTestDataPath("EmptyFile1.txt");
    boost::filesystem::path newFile = test.context().getTestDataPath("EmptyFile2.txt");
    boost::filesystem::path output =
        test.context().getTestOutputPath("DiffUnifiedFormatWriterTests_WriteTest1.txt");

    Error error;
    TextPatch patch = TextDiff::LineDiffFiles(originalFile, newFile, error);

    DiffUnifiedFormatWriter writer(output, error);
    writer.writeOriginalFilePath(originalFile.string());
    writer.writeNewFilePath(newFile.string());
    writer.write(patch);
    writer.close();

    ISHIKO_TEST_FAIL_IF(error);
    ISHIKO_TEST_FAIL_IF_FILES_NEQ("DiffUnifiedFormatWriterTests_WriteTest1.txt",
        "DiffUnifiedFormatWriterTests_WriteTest1.txt");
    ISHIKO_TEST_PASS();
}
