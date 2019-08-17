4. Compute the next permutation .

ex-> {1,2,3,5,4,0} 
        {1,2,4,0,3,5}
Class NextPermutation{
public:
	vector<int> ComputeNextPermutation(vector<int> &arr){
		Int starting_indx=-1;
		for(int i=arr.size()-2;i>=0;i--){
			if(arr[i]<arr[i+1]){
				starting_indx=i;
break;
			}
		}
		if(starting_indx==-1){
			Return { };
		}	
		if(starting_indx==a.size()-2)swap(arr[starting_indx],arr[starting_indx+1]);
Else{
	swap(arr[starting_indx],a[starting_indx+2]);
	reverse(arr.begin()+starting_indx+1,arr.end());
}	
Return arr;
	}
};
