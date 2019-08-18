class Solution {
public:
    int missingNumber(vector<int>& a) {
        if(a.size()==1)return (!a[0]);
        bool f=false;
        for(int i=0;i<a.size();i++){
            if(a[i]==0){
                a[i]=a[(i+1)%a.size()];
                f=true;
            }
        }
        if(f==false)return 0;
        for(int i=0;i<a.size();i++){
            if(a[abs(a[i])-1]>=0)
                a[abs(a[i])-1]*=-1;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]>0)return i+1;
        }
        return 1;
    }
};
