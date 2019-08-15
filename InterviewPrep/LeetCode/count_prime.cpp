class Solution {
public:
    int isprime(int n){
        if(n==2 || n==3)return true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
    int countPrimes(int n) {
        int cnt=0;
        for(int i=2;i<n;i++){
            if(isprime(i))cnt++;
        }
        return cnt;
    }
};
