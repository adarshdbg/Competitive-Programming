class Solution {
public:
    int reverse(int x) {
        if (x > INT_MAX || x < INT_MIN) return 0;
        
        int reverse = 0;
        
        while(x != 0) {     
            if ((reverse > INT_MAX/10 || reverse < INT_MIN/10) && ((x > 0 && (x % 10 <= 7)) || x < 0 && (x % 10 >= -8))) return 0;
            
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return reverse;
    }
};
