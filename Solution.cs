
using System;
using System.Collections.Generic;

public class Solution
{
    private static readonly int LOWER_LIMIT = 0;

    public int[][] FindMaximalUncoveredRanges(int upperLimit, int[][] ranges)
    {
        //'upperLimit' is zero based, therefore '--upperLimit' brings it to its actual value.
        --upperLimit;

        IList<int[]> allMaximalUncoveredRanges = new List<int[]>();
        if (ranges.Length == 0)
        {
            allMaximalUncoveredRanges.Add(new int[] { LOWER_LIMIT, upperLimit });
            return allMaximalUncoveredRanges.ToArray<int[]>();
        }

        Array.Sort(ranges, (x, y) => x[0] - y[0]);

        int previousMaxRangeEnd = LOWER_LIMIT - 1;
        foreach (int[] currentRange in ranges)
        {
            int currentStart = currentRange[0];
            int currentEnd = currentRange[1];

            if (previousMaxRangeEnd + 1 < currentStart)
            {
                allMaximalUncoveredRanges.Add(new int[] { previousMaxRangeEnd + 1, currentStart - 1 });
            }
            previousMaxRangeEnd = Math.Max(previousMaxRangeEnd, currentEnd);
        }

        if (previousMaxRangeEnd < upperLimit)
        {
            allMaximalUncoveredRanges.Add(new int[] { previousMaxRangeEnd + 1, upperLimit });
        }

        return allMaximalUncoveredRanges.ToArray<int[]>();
    }
}
