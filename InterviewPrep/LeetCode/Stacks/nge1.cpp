class Solution {
public:
    
    vector<int> NGE(vector<int> a){
        vector<int> b(a.size(),0);
        stack<int> s;
        s.push(0);
        for(int i=1;i<a.size();i++){
            if(a[i]<a[s.top()]){
                s.push(i);
            }
            else{
                while(!s.empty() && a[i]>a[s.top()]){
                    b[s.top()]=i;
                    s.pop();
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            b[s.top()]=-1;
            s.pop();
        }
        return b;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> b(nums1.size(),-1);
        if(nums1.size()==0){
            vector<int> z;
            return z;
        }
        if(nums2.size()==0){
            return b;
        }
        vector<int> a=NGE(nums2);
        map<int,int> m;
        for(int i=0;i<a.size();i++){
            if(a[i]==-1){
                m[nums2[i]]=-1;
            }
            else
            m[nums2[i]]=nums2[a[i]];
        }
        for(int i=0;i<nums1.size();i++){
            b[i]=m[nums1[i]];
        }
        return b;
    }
};
