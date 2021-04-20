/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "AlgorithmsTests.h"
#include "TextDiffTests.h"
#include <Ishiko/TestFramework/TestFrameworkCore.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoDiff");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<AlgorithmsTests>();
    theTests.append<TextDiffTests>();

    return theTestHarness.run();
}
