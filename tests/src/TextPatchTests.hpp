/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TESTS_TEXTPATCHTESTS_HPP_
#define _ISHIKO_CPP_DIFF_TESTS_TEXTPATCHTESTS_HPP_

#include <Ishiko/Tests/Core.hpp>

class TextPatchTests : public Ishiko::TestSequence
{
public:
    TextPatchTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
};

#endif
