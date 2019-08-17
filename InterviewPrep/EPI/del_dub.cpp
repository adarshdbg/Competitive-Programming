7. Delete dublicates from sorted-array.
Int write_index=0;
for(int i=0;i<n-1;i++){
	if(a[i]!=a[i+1]){
		a[write_index]=a[i];
	}
}
Return write_index;
