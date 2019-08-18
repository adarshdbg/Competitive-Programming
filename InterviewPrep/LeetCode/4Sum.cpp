class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        if(a.size()==0)return ans;
        map<vector<int>,int> m;
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                int k=j+1,l=a.size()-1;
                if(k==l)break;
                while(k<l){
                    int sum=a[i]+a[j]+a[k]+a[l];
                    if(sum==target){
                        vector<int> s={a[i],a[j],a[k],a[l]};
                        k++;
                        l--;
                        if(m.count(s)==0)
                            ans.push_back(s);
                        m[s]++;
                    }
                    else if(sum<target)k++;
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
