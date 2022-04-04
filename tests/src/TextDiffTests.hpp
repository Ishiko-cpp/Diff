/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TESTS_TEXTDIFFTESTS_HPP_
#define _ISHIKO_CPP_DIFF_TESTS_TEXTDIFFTESTS_HPP_

#include <Ishiko/Tests/Core.hpp>

class TextDiffTests : public Ishiko::TestSequence
{
public:
    TextDiffTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CharacterDiffTest1(Ishiko::Test& test);
    static void CharacterDiffTest2(Ishiko::Test& test);
    static void CharacterDiffTest3(Ishiko::Test& test);
    static void CharacterDiffTest4(Ishiko::Test& test);
    static void CharacterDiffTest5(Ishiko::Test& test);
    static void CharacterDiffTest6(Ishiko::Test& test);
    static void CharacterDiffTest7(Ishiko::Test& test);
    static void CharacterDiffTest8(Ishiko::Test& test);
    static void CharacterDiffTest9(Ishiko::Test& test);
    static void WordDiffTest1(Ishiko::Test& test);
    static void WordDiffTest2(Ishiko::Test& test);
    static void WordDiffTest3(Ishiko::Test& test);
    static void WordDiffTest4(Ishiko::Test& test);
    static void WordDiffTest5(Ishiko::Test& test);
    static void WordDiffTest6(Ishiko::Test& test);
    static void WordDiffTest7(Ishiko::Test& test);
    static void WordDiffTest8(Ishiko::Test& test);
    static void WordDiffTest9(Ishiko::Test& test);
    static void WordDiffTest10(Ishiko::Test& test);
    static void WordDiffTest11(Ishiko::Test& test);
    static void LineDiffFilesTest1(Ishiko::Test& test);
    static void LineDiffFilesTest2(Ishiko::Test& test);
    static void LineDiffFilesTest3(Ishiko::Test& test);
    static void LineDiffFilesTest4(Ishiko::Test& test);
    static void LineDiffFilesTest5(Ishiko::Test& test);
    static void LineDiffFilesTest6(Ishiko::Test& test);
    static void LineDiffFilesTest7(Ishiko::Test& test);
};

#endif
