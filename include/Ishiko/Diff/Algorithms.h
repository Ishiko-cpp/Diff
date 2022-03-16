/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_DIFF_ALGORITHMS_H_
#define _ISHIKO_DIFF_ALGORITHMS_H_

#include <Ishiko/Types.hpp>
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

// TODO: add tests for this
template <class T>
size_t MyersAlgorithm(const std::vector<T>& originalString, const std::vector<T>& newString, std::vector<Point2D<int>>& path)
{
    int max = originalString.size() + newString.size();
    if (max == 0)
    {
        return 0;
    }

    std::vector<int> v;
    v.resize((2 * max) + 2); // TODO: can we get rid of +2 here?
    v[max] = 0;
    std::vector<std::vector<int>> oldVs;
    for (int d = 0; d <= max; ++d)
    {
        for (int k = -d; k <= d; k += 2)
        {
            int x = 0;
            int y = 0;
            if ((k == -d) || ((k != d) && (v[max + k - 1] < v[max + k + 1])))
            {
                x = v[max + k + 1];
            }
            else
            {
                x = v[max + k - 1] + 1;
            }
            y = (x - k);
            while ((x < originalString.size()) && (y < newString.size()) && (originalString[x] == newString[y]))
            {
                ++x;
                ++y;
            }
            v[max + k] = x;
            if ((x >= originalString.size()) && (y >= newString.size()))
            {
                path.emplace(path.begin(), x, y);
                int oldVIndex = oldVs.size() - 1;
                while (oldVIndex > 0)
                {
                    // TODO: this needs more out of bounds testing
                    while ((x > 0) && (y > 0) && (originalString[x - 1] == newString[y - 1]))
                    {
                        --x;
                        --y;
                    }
                    if (oldVs[oldVIndex][max + k + 1] == x)
                    {
                        k = k + 1;
                        --y;
                    }
                    else if ((oldVs[oldVIndex][max + k - 1] + 1) == x)
                    {
                        k = k - 1;
                        --x;
                    }
                    else
                    {
                        // TODO: ERROR?
                    }
                    path.emplace(path.begin(), x, y);
                    --oldVIndex;
                }
                // TODO: this is messy. Other implementations usually eliminate the common prefix to avoid this. I
                // guess we will have to do the same. In the meantime this is trying to figure out retroactively if
                // there was such a common prefix by looking at the last (x,y) that we put in the path and adding an
                // entry for it if we detect it.
                if (x != y)
                {
                    // The conditions here check if the first entry in path is not (1,0) or (0,1)
                    if ((x > y) && (x != 1))
                    {
                        path.emplace(path.begin(), x - 1, y);
                    }
                    else if ((y > x) && (y != 1))
                    {
                        path.emplace(path.begin(), x, y - 1);
                    }
                }
                return d;
            }
        }
        oldVs.push_back(v);
    }
    return 0;
}

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
