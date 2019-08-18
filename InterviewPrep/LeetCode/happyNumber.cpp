class Solution {
public:
    int ans=0;
    unordered_map<int,int> m;
    
    int sum(int n){
        int ans=0;
        while(n){
            ans+=(n%10)*(n%10);
            n/=10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        
        while(m.count(n)==0 && n!=1){
            m[n]++;
            n=sum(n);
        }
        return (n==1);
    }
};
