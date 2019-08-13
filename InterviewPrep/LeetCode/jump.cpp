class Solution {
public:
    map<int,int> m;
    int climbStairs(int n) {
        if(n<0)return 0;
        if(n==0)return 1;
        if(m.count(n))return m[n];
        return m[n]=climbStairs(n-1)+climbStairs(n-2);
    }
};
