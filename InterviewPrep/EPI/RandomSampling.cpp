2.  Implement an algorithm that takes as input an array of distinct elements and a size k and returns a subset of the given size of the array elements. All subsets are equally likely. Return the result in input array itself.

class RandomSampling{
public:
	vector<int> Solution(vector<int & arr,int k){
		default _random_engine seed((random_device())());
		for(int i=0;i<k;i++){
			swap(a[i],a[uniform_int_distribution<int>{i,a.size()-1}(seed)]);
		}
		return arr;
	}
}
