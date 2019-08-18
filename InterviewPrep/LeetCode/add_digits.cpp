class Solution {
public:
    int get_sum(int n){
        int ans=0;
        while(n){
            ans+=(n%10);
            n/=10;
        }
        return ans;
    }
    int addDigits(int num) {
        while((num/10)){
            num=get_sum(num);
        }
        return num;
    }
};
