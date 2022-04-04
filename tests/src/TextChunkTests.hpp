/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TESTS_TEXTCHUNKTESTS_HPP_
#define _ISHIKO_CPP_DIFF_TESTS_TEXTCHUNKTESTS_HPP_

#include <Ishiko/Tests/Core.hpp>

class TextChunkTests : public Ishiko::TestSequence
{
public:
    TextChunkTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
};

#endif
