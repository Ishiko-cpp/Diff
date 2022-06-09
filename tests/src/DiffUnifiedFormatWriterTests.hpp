/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TESTS_DIFFUNIFIEDFORMATWRITERTESTS_HPP_
#define _ISHIKO_CPP_DIFF_TESTS_DIFFUNIFIEDFORMATWRITERTESTS_HPP_

#include <Ishiko/TestFramework/Core.hpp>

class DiffUnifiedFormatWriterTests : public Ishiko::TestSequence
{
public:
    DiffUnifiedFormatWriterTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void WriteTest1(Ishiko::Test& test);
    static void WriteTest2(Ishiko::Test& test);
    static void WriteTest3(Ishiko::Test& test);
};

#endif
