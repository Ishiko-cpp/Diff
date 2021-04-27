/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "TextDiffTests.h"
#include "Ishiko/Diff/TextDiff.h"

using namespace Ishiko;
using namespace Ishiko::Diff;
using namespace Ishiko::Tests;

TextDiffTests::TextDiffTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "TextDiff tests", environment)
{
    append<HeapAllocationErrorsTest>("Diff test 1", DiffTest1);
    append<HeapAllocationErrorsTest>("Diff test 2", DiffTest2);
}

void TextDiffTests::DiffTest1(Test& test)
{
    boost::filesystem::path originalFile = test.environment().getTestDataPath("File1.txt");
    boost::filesystem::path newFile = test.environment().getTestDataPath("File2.txt");

    Error error;
    TextPatch patch = TextDiff::Diff(originalFile, newFile, error);

    ISHTF_FAIL_IF(error);
    ISHTF_FAIL_IF(patch.hasChanges());
    ISHTF_PASS();
}

void TextDiffTests::DiffTest2(Test& test)
{
    boost::filesystem::path originalFile = test.environment().getTestDataPath("File1.txt");
    boost::filesystem::path newFile = test.environment().getTestDataPath("File2.txt");

    Error error;
    TextPatch patch = TextDiff::Diff(originalFile, newFile, error);

    ISHTF_FAIL_IF(error);
    ISHTF_FAIL_IF_NOT(patch.hasChanges());
    ISHTF_PASS();
}
