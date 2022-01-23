/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_CPP_DIFF_TESTS_TEXTDIFFTESTS_H_
#define _ISHIKO_CPP_DIFF_TESTS_TEXTDIFFTESTS_H_

#include <Ishiko/Tests/Core.hpp>

class TextDiffTests : public Ishiko::Tests::TestSequence
{
public:
    TextDiffTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestContext& context);

private:
    static void CharacterDiffTest1(Ishiko::Tests::Test& test);
    static void CharacterDiffTest2(Ishiko::Tests::Test& test);
    static void CharacterDiffTest3(Ishiko::Tests::Test& test);
    static void CharacterDiffTest4(Ishiko::Tests::Test& test);
    static void CharacterDiffTest5(Ishiko::Tests::Test& test);
    static void CharacterDiffTest6(Ishiko::Tests::Test& test);
    static void CharacterDiffTest7(Ishiko::Tests::Test& test);
    static void CharacterDiffTest8(Ishiko::Tests::Test& test);
    static void CharacterDiffTest9(Ishiko::Tests::Test& test);
    static void WordDiffTest1(Ishiko::Tests::Test& test);
    static void WordDiffTest2(Ishiko::Tests::Test& test);
    static void WordDiffTest3(Ishiko::Tests::Test& test);
    static void WordDiffTest4(Ishiko::Tests::Test& test);
    static void WordDiffTest5(Ishiko::Tests::Test& test);
    static void WordDiffTest6(Ishiko::Tests::Test& test);
    static void WordDiffTest7(Ishiko::Tests::Test& test);
    static void WordDiffTest8(Ishiko::Tests::Test& test);
    static void WordDiffTest9(Ishiko::Tests::Test& test);
    static void WordDiffTest10(Ishiko::Tests::Test& test);
    static void WordDiffTest11(Ishiko::Tests::Test& test);
    static void LineDiffFilesTest1(Ishiko::Tests::Test& test);
    static void LineDiffFilesTest2(Ishiko::Tests::Test& test);
    static void LineDiffFilesTest3(Ishiko::Tests::Test& test);
    static void LineDiffFilesTest4(Ishiko::Tests::Test& test);
    static void LineDiffFilesTest5(Ishiko::Tests::Test& test);
    static void LineDiffFilesTest6(Ishiko::Tests::Test& test);
    static void LineDiffFilesTest7(Ishiko::Tests::Test& test);
};

#endif
