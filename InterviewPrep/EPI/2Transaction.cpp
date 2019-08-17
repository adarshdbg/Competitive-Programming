6. Buy and Sell at-most twice to make maximum profit.
 Suppose “prices” is the input array 
for(int i=0;i<n;i++){
	for(int j=i;j<n;j++){
		for(int k=j+1;k<n;k++){
			for(int l=k;l<n;l++){
				// compute the profit if we buy the first stock ith day and sell it on jth day, and buy the second stock on kth day and sell it on lth day. And update the answer if this profit exceeds the maximum found so far.
			}
		}
	}
}
Time Complexity :: O(N^4)
Space Complexity :: O(1)

for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		// ‘i’ is the starting point for first stock and ‘j’ is the starting point for second stock.
		// So, we have to sell the first stock before the day we buy the second stock.
		for(int k=i;k<=j-1;k++)....
		for(int k=j;k<n;k++).....
	}
}

Time Complexity :: O(N^3)
Space Complexity :: O(1)

Use left[i-1]+right[i] for every i.
Time Complexity :: O(N)
Space Complexity :: O(N)
