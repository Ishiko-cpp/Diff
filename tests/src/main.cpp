/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "AlgorithmsTests.hpp"
#include "DiffUnifiedFormatWriterTests.hpp"
#include "TextChunkTests.hpp"
#include "TextPatchTests.hpp"
#include "TextDiffTests.hpp"
#include "Ishiko/Diff/linkoptions.hpp"
#include <Ishiko/TestFramework/Core.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoDiff");

    theTestHarness.context().setTestDataDirectory("../../data");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<AlgorithmsTests>();
    theTests.append<TextChunkTests>();
    theTests.append<TextPatchTests>();
    theTests.append<TextDiffTests>();
    theTests.append<DiffUnifiedFormatWriterTests>();

    return theTestHarness.run();
}
