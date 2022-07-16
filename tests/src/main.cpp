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
#include <exception>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    try
    {
        TestHarness::CommandLineSpecification commandLineSpec;
        commandLineSpec.setDefaultValue("context.data", "../../data");
        commandLineSpec.setDefaultValue("context.output", "../../output");
        commandLineSpec.setDefaultValue("context.reference", "../../reference");

        Configuration configuration = commandLineSpec.createDefaultConfiguration();
        CommandLineParser::parse(commandLineSpec, argc, argv, configuration);

        TestHarness theTestHarness("Ishiko/C++ Diff Library Tests", configuration);

        TestSequence& theTests = theTestHarness.tests();
        theTests.append<AlgorithmsTests>();
        theTests.append<TextChunkTests>();
        theTests.append<TextPatchTests>();
        theTests.append<TextDiffTests>();
        theTests.append<DiffUnifiedFormatWriterTests>();

        return theTestHarness.run();
    }
    catch (const std::exception& e)
    {
        return TestApplicationReturnCode::exception;
    }
    catch (...)
    {
        return TestApplicationReturnCode::exception;
    }
}
