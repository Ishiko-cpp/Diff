/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_DIFF_ALGORITHMS_H_
#define _ISHIKO_DIFF_ALGORITHMS_H_

#include <Ishiko/Types.h>
#include <string>
#include <vector>

namespace Ishiko
{
namespace Diff
{

/**
 * The Myers algorithm as described in "An O(ND) Difference Algorithm and its Variations", Eugene Myers, Algorithmica
 * Vol. 1 No. 2, 1986, pp. 251-266.
 * TODO: do I need a version that allows substitutions?
 * It's O(n * m) in space and time (worst case of totally different files).
 */
size_t MyersAlgorithm(const std::string& originalString, const std::string& newString);

/**
 * This variant of Myers returns the path to follow to in addition to the distance.
 * It's O(n * m) in space and time (worst case of totally different files).
 * The path always starts at (0, 0) so that is redundant information and not included in the path.
 */
size_t MyersAlgorithm(const std::string& originalString, const std::string& newString, std::vector<Point2D<int>>& path);

/**
 * The Wagner-Fischer algorithm as described here: https://en.wikipedia.org/wiki/Wagner%E2%80%93Fischer_algorithm
 * This is O(N*M) in space and time algorithm that finds the edit distance if 3 operations are allowed: deletion, insertion and substitution.
 * TODO: variations that don't allow substitution so it matches Myers? Other rules?
 */
size_t WagnerFischerAlgorithm(const std::string& originalString, const std::string& newString);

}
}

#include "linkoptions.h"

#endif
