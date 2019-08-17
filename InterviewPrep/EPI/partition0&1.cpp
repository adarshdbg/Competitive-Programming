11.  Partition the array such that first part contains 0s only and other contains 1s only.

Int next_even=0,next_odd=a.size()-1;
while(next_even<next_odd){
	if(a[next_even]%2==0){
		next_even++;
	}
	Else{
		swap(a[next_even],a[next_odd--]);
	}
}
