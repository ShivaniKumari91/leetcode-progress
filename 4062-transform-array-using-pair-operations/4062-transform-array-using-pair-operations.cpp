
class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {

        // Operation:
        // source[i] = source[i] + source[j] - delta
        // source[j] = delta

        // IMPORTANT OBSERVATION:
        // Sum of source[i] and source[j] remains same.
        //
        // New sum:
        // (source[i] + source[j] - delta) + delta
        // = source[i] + source[j]
        //
        // Therefore, TOTAL SUM of the array never changes.

        long long sumSource = 0;
        long long sumTarget = 0;

        for(int i = 0; i < source.size(); i++) {
            sumSource += source[i];
            sumTarget += target[i];
        }

        // If total sums are different,
        // target can NEVER be obtained.
        if(sumSource != sumTarget)
            return false;


        // WHY EQUAL SUM IS SUFFICIENT?
        //
        // We can fix the elements one by one.
        //
        // Suppose current values at i and j are:
        //       [a, b]
        //
        // We want source[i] = target[i].
        //
        // Choose:
        // delta = a + b - target[i]
        //
        // Then:
        // new source[i]
        // = a + b - delta
        // = target[i]
        //
        // And:
        // new source[j] = delta
        //
        // So one operation can make ONE chosen position
        // exactly equal to its target value.
        //
        // We don't need to touch that position again.
        //
        // We can repeat this:
        //
        // [a, b, c, d]
        //    ↓
        // [target[0], *, c, d]
        //    ↓
        // [target[0], target[1], *, d]
        //    ↓
        // [target[0], target[1], target[2], *]
        //
        // Finally, the last '*' automatically becomes target[last]
        // because TOTAL SUM is already equal.
        //
        // Therefore:
        // sum(source) == sum(target)
        // => transformation is possible.

        return true;
    }
};

//Remember:**
//Operation = redistribution between two positions`
//`Total sum never changes`
//Equal total sum ⇒ we can fix positions one by one.`
