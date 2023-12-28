
/**
 * @param {number} upperLimit
 * @param {number[][]} ranges
 * @return {number[][]}
 */
var findMaximalUncoveredRanges = function (upperLimit, ranges) {
    const LOWER_LIMIT = 0;
    //'upperLimit' is zero based, therefore '--upperLimit' brings it to its actual value.
    --upperLimit;

    const allMaximalUncoveredRanges = new Array();
    if (ranges.length === 0) {
        allMaximalUncoveredRanges.push([LOWER_LIMIT, upperLimit]);
        return allMaximalUncoveredRanges;
    }

    ranges.sort((x, y) => x[0] - y[0]);

    let previousMaxRangeEnd = LOWER_LIMIT - 1;
    for (let [currentStart, currentEnd] of ranges) {
        if (previousMaxRangeEnd + 1 < currentStart) {
            allMaximalUncoveredRanges.push([previousMaxRangeEnd + 1, currentStart - 1]);
        }
        previousMaxRangeEnd = Math.max(previousMaxRangeEnd, currentEnd);
    }

    if (previousMaxRangeEnd < upperLimit) {
        allMaximalUncoveredRanges.push([previousMaxRangeEnd + 1, upperLimit]);
    }

    return allMaximalUncoveredRanges;
};
