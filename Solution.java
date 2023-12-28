
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {

    private static final int LOWER_LIMIT = 0;

    public int[][] findMaximalUncoveredRanges(int upperLimit, int[][] ranges) {
        //'upperLimit' is zero based, therefore '--upperLimit' brings it to its actual value.
        --upperLimit;

        List<int[]> allMaximalUncoveredRanges = new ArrayList<>();
        if (ranges.length == 0) {
            allMaximalUncoveredRanges.add(new int[]{LOWER_LIMIT, upperLimit});
            return allMaximalUncoveredRanges.toArray(new int[allMaximalUncoveredRanges.size()][2]);
        }

        Arrays.sort(ranges, (x, y) -> x[0] - y[0]);

        int previousMaxRangeEnd = LOWER_LIMIT - 1;
        for (int[] currentRange : ranges) {
            int currentStart = currentRange[0];
            int currentEnd = currentRange[1];

            if (previousMaxRangeEnd + 1 < currentStart) {
                allMaximalUncoveredRanges.add(new int[]{previousMaxRangeEnd + 1, currentStart - 1});
            }
            previousMaxRangeEnd = Math.max(previousMaxRangeEnd, currentEnd);
        }

        if (previousMaxRangeEnd < upperLimit) {
            allMaximalUncoveredRanges.add(new int[]{previousMaxRangeEnd + 1, upperLimit});
        }

        return allMaximalUncoveredRanges.toArray(new int[allMaximalUncoveredRanges.size()][2]);
    }
}
