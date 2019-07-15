#include <bits/stdc++.h>
using namespace std;
int n,m;
bool isPossible(vector<vector<char>> board,string s,int pos,int i,int j,vector<vector<int>> &visited){
// 	return true;
	if(pos==s.length()-1){
		return (!visited[i][j] && (s[pos]==board[i][j]));
	}
	
	if(visited[i][j]==true){
		return false;
	}
	
	if(board[i][j]!=s[pos]){
		return false;
	}
	bool ans=false;
	visited[i][j]=true;
	// 1. (i+1,j-1) , (i+1,j) , (i+1,j+1)
	if(i+1<n && j>=1){
		if(!visited[i+1][j-1] && (board[i+1][j-1]==s[pos+1])){
			ans|=(isPossible(board,s,pos+1,i+1,j-1,visited));
		}
	}
	if(i+1<n){
		if(!visited[i+1][j] && board[i+1][j]==s[pos+1]){
			ans|=(isPossible(board,s,pos+1,i+1,j,visited));
		}
	}
	if(i+1<n && j+1<m){
		if(!visited[i+1][j+1] && board[i+1][j+1]==s[pos+1]){
			ans|=(isPossible(board,s,pos+1,i+1,j+1,visited));
		}
	}
	// 2. (i,j+1) , (i,j-1)
	if(j+1<m){
		if(!visited[i][j+1] && board[i][j+1]==s[pos+1]){
			ans|=(isPossible(board,s,pos+1,i,j+1,visited));
		}
	}
	if(j>=1){
		if(!visited[i][j-1] && board[i][j-1]==s[pos+1]){
			ans|=(isPossible(board,s,pos+1,i,j-1,visited));
		}
	}
	// 3. (i-1,j-1) , (i-1,j) , (i-1,j+1)
	if(i>=1 && j>=1){
		if(!visited[i-1][j-1] && board[i-1][j-1]==s[pos+1]){
			ans|=isPossible(board,s,pos+1,i-1,j-1,visited);
		}
	}
	if(i>=1){
		if(!visited[i-1][j] && board[i-1][j]==s[pos+1]){
			ans|=(isPossible(board,s,pos+1,i-1,j,visited));
		}
	}
	if(i>=1 && j+1<m){
		if(!visited[i-1][j+1] && board[i-1][j+1]==s[pos+1]){
			ans|=(isPossible(board,s,pos+1,i-1,j+1,visited));
		}
	}
	visited[i][j]=false;
	return ans;
}

bool isPresent(vector<vector<char>> board,string s){
	vector<vector<int>> visited(n,vector<int>(m));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j]=0;
		}
	}
	for(int i=0;i<s.length();i++){
		for(int j=0;j<s.length();j++){
			if(isPossible(board,s,0,i,j,visited)){
				return true;
			}
		}
	}
	return false;
}

vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
  // Write your code here.
	n=board.size();
	m=board[0].size();
	vector<string> ans;
	for(int i=0;i<words.size();i++){
		if(isPresent(board,words[i])){
			ans.push_back(words[i]);
		}
	}
	return ans;
}
