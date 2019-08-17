Google Interview Preparation

Write a program that takes as input a positive integer n and a size k<=n and returns a size-k subset of {0,1,2,3,.....n-1}. The subset should be represented as an array.The subsets should be equally likely and in addition all permutations of elements of the array should be equally likely. You may assume you have a function which takes as input a non negative integer t and returns an integer in the set {0,1,2,....t-1} with uniform probability.

     Solution :: 
	
	Brute Force ?
		n=4 , k=3
	1 -> {1}
	2-> {1,2}
	3-> {1,2,3}
	Return {1,2,3}
	
	class find_k_sized_subset{
	public:
		
		set<int,int> RandomSubset(int n,int k){
			/// hashmap is used to check the curr element has already exists in our set or not.
	unordered_map<int,int> m;

	/*
k_sized_subset is the output set of size k which has equal probability as others subset of size k
*/
	set<int,int> k_sized_subset;
	while(k_sized_subset.size().size()<k){
		int random_value=random_fn(n-1);
		if(m.count(random_value)==0){
			k_sized_subset.insert(random_value);
			m[random_value]++;
		}
		else{
		// We got a random number which already exists in the set.
			continue;
		}
	}
return k_sized_subset;
		}	
	
	};
	
	Time Complexity ::
	Expected Number of trials until we get k elements in out set is
		1+(1/(n-1))*n+(1/(n-2))*n+...(1/(n-k+1))*n
		<= n*(1/n + 1/(n-1)+....1/1)<=nlogn
	So, time complexity is O(NlogN).
	
	Optimised Solution ::
	
	unordered_map<int,int> changed_elements;
	default_random_engine seed((random_device())()); // Random num generator
	for(int i=0;i<k;i++){
	// Generate a random number in {i,...n-1}
		int rand_indx=uniform_int_distribution<int>(i,n-i)(seed);
		auto ptr1=changed_elements.find(rand_indx),
		        ptr2=changed_elements.find(i);
		if(ptr1==changed_elements.end() && ptr2==changed_elements.end()){
			changed_elements[indx]=i,
			changed_elements[i]=rand_indx;
		}	
		else if(ptr1!=changed_elements.end() &&ptr2==changed_elements.end()){	
			changed_elements[random_indx]=ptr1->second,
			ptr1->second=i;
		}	
		else if(ptr1==changed_elements.end()&&ptr2!=changed_elements.end()){	
			changed_elements[random_indx]=ptr2->second,
			ptr2->second=i;
		}	
		else{
			Int temp=ptr2->second;
			changed_elements[i]=ptr1->second;
			changed_elements[rand_indx]=temp;
		}
	}
	
	vector<int> result;
	for(int i=0;i<k;i++){
		result.emplace_back(changed_elements[i]);
	}	
	
	return result;
