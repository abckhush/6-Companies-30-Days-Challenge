class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long lcm = (divisor1 * divisor2) / __gcd(divisor1, divisor2);
        long long total = uniqueCnt1 + uniqueCnt2;
        long long l = total, r = 1e12;
        long long ans = 0;
        while (l <= r){
            long long mid = (l + r) / 2;
            long long both = mid / lcm;
            long long onlyA = mid / divisor2 - both;
            long long onlyB = mid / divisor1 - both;
            total = max(0ll, uniqueCnt1 - onlyA) + max(0ll, uniqueCnt2 - onlyB);
            if (mid - onlyA - onlyB >= total + both){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
        
    }
};
