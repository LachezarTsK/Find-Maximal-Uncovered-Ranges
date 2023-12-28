
#include <ranges>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
    constexpr static int LOWER_LIMIT = 0;
    
public:
    vector<vector<int>> findMaximalUncoveredRanges(int upperLimit, vector<vector<int>>& ranges) const {
        //'upperLimit' is zero based, therefore '--upperLimit' brings it to its actual value.
        --upperLimit;

        vector<vector<int>> allMaximalUncoveredRanges;
        if (ranges.empty()) {
            allMaximalUncoveredRanges.push_back({LOWER_LIMIT, upperLimit});
            return allMaximalUncoveredRanges;
        }

        // Alternatively, prior to C++20 versions:
        // sort(ranges.begin(), ranges.end(), lambda expression);
        ranges::sort(ranges, [](const vector<int>& x, const vector<int>& y) {
            return x[0] < y[0]; });

        int previousMaxRangeEnd = LOWER_LIMIT - 1;
        for (const auto& currentRange : ranges) {
            int currentStart = currentRange[0];
            int currentEnd = currentRange[1];

            if (previousMaxRangeEnd + 1 < currentStart) {
                allMaximalUncoveredRanges.push_back({previousMaxRangeEnd + 1, currentStart - 1});
            }
            previousMaxRangeEnd = max(previousMaxRangeEnd, currentEnd);
        }

        if (previousMaxRangeEnd < upperLimit) {
            allMaximalUncoveredRanges.push_back({previousMaxRangeEnd + 1, upperLimit});
        }

        return allMaximalUncoveredRanges;
    }
};
