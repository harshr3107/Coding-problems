class Solution {
public:
    bool judgeSquareSum(int c) {
        int start = 0;
        int end = static_cast<int>(sqrt(c));

        while (start <= end) {
            long long int sum = static_cast<long long>(start) * start + static_cast<long long>(end) * end;
            if (sum == c) {
                return true;
            } else if (sum > c) {
                end--;
            } else {
                start++;
            }
        }

        return false;
    }
};