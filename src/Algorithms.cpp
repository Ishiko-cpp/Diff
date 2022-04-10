/*
    Copyright (c) 2021-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/diff/blob/main/LICENSE.txt
*/

#include "Algorithms.hpp"
#include <Ishiko/Collections.hpp>
#include <algorithm>
#include <vector>

namespace Ishiko
{

size_t MyersAlgorithm(const std::string& originalString, const std::string& newString)
{
    int max = originalString.size() + newString.size();
    if (max == 0)
    {
        return 0;
    }

    std::vector<int> v;
    v.resize((2 * max) + 2); // TODO: can we get rid of +2 here?
    v[max] = 0;
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
                return d;
            }
        }
    }
    return 0;
}

size_t MyersAlgorithm(const std::string& originalString, const std::string& newString, std::vector<Point2D<int>>& path)
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
                    while ((x > 0) && (y > 0) && (originalString[x-1] == newString[y-1]))
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

size_t WagnerFischerAlgorithm(const std::string& originalString, const std::string& newString)
{
    Vector2D<size_t> distances(newString.size() + 1, originalString.size() + 1);

    for (size_t j = 0; j < (originalString.size() + 1); ++j)
    {
        distances.get(0, j) = j;
    }

    for (size_t i = 0; i < newString.size(); ++i)
    {
        distances.get(i + 1, 0) = (i + 1);
        for (size_t j = 0; j < originalString.size(); ++j)
        {
            size_t substitutionCost = 0;
            if (newString[i] != originalString[j])
            {
                substitutionCost = 1;
            }

            size_t insertionCost = distances.get(i, j + 1) + 1;
            size_t deletionCost = distances.get(i + 1, j) + 1;
            substitutionCost += distances.get(i, j);

            distances.get(i + 1, j + 1) = std::min({ insertionCost, deletionCost, substitutionCost });
        }
    }

    return distances.get(newString.size(), originalString.size());
}

}
