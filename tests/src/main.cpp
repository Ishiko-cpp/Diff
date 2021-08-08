/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "AlgorithmsTests.h"
#include "TextChunkTests.h"
#include "TextPatchTests.h"
#include "TextDiffTests.h"
#include <Ishiko/Tests/Core.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoDiff");

    theTestHarness.environment().setTestDataDirectory("../../data");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<AlgorithmsTests>();
    theTests.append<TextChunkTests>();
    theTests.append<TextPatchTests>();
    theTests.append<TextDiffTests>();

    return theTestHarness.run();
}
