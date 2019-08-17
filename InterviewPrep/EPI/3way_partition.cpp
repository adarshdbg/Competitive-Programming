10. Dutch flag partition 
Seggregate 0s,1s,2s.
Int lesser=0,equal=0,higher=a.size()-1;
{0….lesser}-->0s
{lesser+1…..equal}-->1s
{equal...high}->unclassified
{high+1..end} → 2s

while(mid<=high){
	if(a[mid]==0){
		swap(a[low],a[mid]);
		Low++;
		mid++;
	}
	Else if(a[mid]==1){
		mid++;
	}
	Else{
		swap(a[mid],a[high--]);
	}
}
