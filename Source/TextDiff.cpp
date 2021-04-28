/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "TextDiff.h"
#include "Algorithms.h"
#include "TextChunk.h"
#include <Ishiko/FileSystem.h>

using namespace Ishiko::FileSystem;

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

TextPatch TextDiff::LineDiffFiles(const boost::filesystem::path& originalFile, const boost::filesystem::path& newFile,
    Error& error)
{
    TextPatch result;

    std::string originalString = ReadFile(originalFile, error);
    std::string newString = ReadFile(newFile, error);
    
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

}
}
