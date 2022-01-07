/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "TextDiff.h"
#include "Algorithms.h"
#include "TextChunk.h"
#include <Ishiko/FileSystem.hpp>
#include <Ishiko/Text.h>
#include <unordered_set>
#include <vector>

using namespace Ishiko::FileSystem;
using namespace Ishiko::Text;

namespace Ishiko
{
namespace Diff
{

TextPatch TextDiff::CharacterDiff(const std::string& originalString, const std::string& newString)
{
    TextPatch result;

    std::vector<Point2D<int>> path;
    MyersAlgorithm(originalString, newString, path);

    Point2D<int> previousPosition(0, 0);
    for (const Point2D<int>& edit : path)
    {
        Point2D<int> move(edit.x - previousPosition.x, edit.y - previousPosition.y);

        // As a result of the Myers algorithm the move is a single horizontal (deletion from the original string) or
        // vertical (insertion from the new string) move followed by a 'snake'.
        if (move.x > move.y)
        {
            // Deletion from the original string
            result.append(TextChunk(previousPosition.x, previousPosition.y, TextChunk::eDeletion,
                originalString.substr(previousPosition.x, 1)));
        }
        else if (move.y > move.x)
        {
            // Insertion from the new string
            result.append(TextChunk(previousPosition.x, previousPosition.y, TextChunk::eInsertion,
                newString.substr(previousPosition.y, 1)));
        }

        previousPosition = edit;
    }

    return result;
}

TextPatch TextDiff::WordDiff(const std::string& originalString, const std::string& newString)
{
    TextPatch result;

    std::vector<std::string> originalWords = ASCII::Split(originalString);
    std::vector<std::string> newWords = ASCII::Split(newString);

    std::unordered_set<std::string> wordsSet(originalWords.begin(), originalWords.end());
    wordsSet.insert(newWords.begin(), newWords.end());
    
    std::vector<size_t> originalHashesString;
    for (const std::string& word : originalWords)
    {
        // We use the address in the unordered_set as that is guaranteed to be collision-free
        originalHashesString.push_back((size_t)(&(*wordsSet.find(word))));
    }
    std::vector<size_t> newHashesString;
    for (const std::string& word : newWords)
    {
        // We use the address in the unordered_set as that is guaranteed to be collision-free
        newHashesString.push_back((size_t)(&(*wordsSet.find(word))));
    }

    std::vector<Point2D<int>> path;
    MyersAlgorithm(originalHashesString, newHashesString, path);

    Point2D<int> previousPosition(0, 0);
    for (const Point2D<int>& edit : path)
    {
        Point2D<int> move(edit.x - previousPosition.x, edit.y - previousPosition.y);

        // As a result of the Myers algorithm the move is a single horizontal (deletion from the original string) or
        // vertical (insertion from the new string) move followed by a 'snake'.
        if (move.x > move.y)
        {
            // Deletion from the original string
            result.append(TextChunk(previousPosition.x, previousPosition.y, TextChunk::eDeletion,
                *(std::string*)(originalHashesString[previousPosition.x])));
        }
        else if (move.y > move.x)
        {
            // Insertion from the new string
            result.append(TextChunk(previousPosition.x, previousPosition.y, TextChunk::eInsertion,
                *(std::string*)(newHashesString[previousPosition.y])));
        }

        previousPosition = edit;
    }

    return result;
}

TextPatch TextDiff::LineDiffFiles(const boost::filesystem::path& originalFile, const boost::filesystem::path& newFile,
    Error& error)
{
    TextPatch result;

    std::string originalString = ReadFile(originalFile, error);
    std::string newString = ReadFile(newFile, error);
    
    std::vector<std::string> originalLines = ASCII::GetLines(originalString);
    std::vector<std::string> newLines = ASCII::GetLines(newString);

    std::unordered_set<std::string> linesSet(originalLines.begin(), originalLines.end());
    linesSet.insert(newLines.begin(), newLines.end());

    std::vector<size_t> originalHashesString;
    for (const std::string& word : originalLines)
    {
        // We use the address in the unordered_set as that is guaranteed to be collision-free
        originalHashesString.push_back((size_t)(&(*linesSet.find(word))));
    }
    std::vector<size_t> newHashesString;
    for (const std::string& word : newLines)
    {
        // We use the address in the unordered_set as that is guaranteed to be collision-free
        newHashesString.push_back((size_t)(&(*linesSet.find(word))));
    }

    std::vector<Point2D<int>> path;
    MyersAlgorithm(originalHashesString, newHashesString, path);

    Point2D<int> previousPosition(0, 0);
    for (const Point2D<int>& edit : path)
    {
        Point2D<int> move(edit.x - previousPosition.x, edit.y - previousPosition.y);

        // As a result of the Myers algorithm the move is a single horizontal (deletion from the original string) or
        // vertical (insertion from the new string) move followed by a 'snake'.
        if (move.x > move.y)
        {
            // Deletion from the original string
            result.append(TextChunk(previousPosition.x, previousPosition.y, TextChunk::eDeletion,
                *(std::string*)(originalHashesString[previousPosition.x])));
        }
        else if (move.y > move.x)
        {
            // Insertion from the new string
            result.append(TextChunk(previousPosition.x, previousPosition.y, TextChunk::eInsertion,
                *(std::string*)(newHashesString[previousPosition.y])));
        }

        previousPosition = edit;
    }

    return result;
}

}
}
