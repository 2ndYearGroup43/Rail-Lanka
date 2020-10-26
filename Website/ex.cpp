#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std; 



int a[100000];
vector<long> stones;



void makeset(){
	vector<long>::iterator ip;
	ip=unique(stones.begin(),stones.begin()+stones.size());
	stones.resize(distance(stones.begin(),ip));
}

void magic(long spell[],long n){
	long i;
	long np=-1;
	vector<long> temp;
	do{
		temp=stones;
		for(i=0;i<n;i++){
			stones[i]=spell[stones[i]];
		}
		makeset();
		sort(stones.begin(),stones.end());
		np++;
		if(a[stones.size()]<0){
			a[stones.size()]=np;
		}
		
	}while(temp!=stones);
	

	
}

 int main(){
 	long n,q,s,i,k;
 	cin>>n;
 	long spell[n];
 	for(i=0;i<100000;i++){
 		a[i]=-1;
	 }
 	for(i=0;i<n;i++){
 		stones.push_back(i+1);
		cin>>s;
 		spell[i]=s;
	 }
	 magic(spell,n);
	 cin>>q;
	 long out[q];
	 for(i=0;i<q;i++){
	 	cin>>k;
	 	out[i]=a[k];
	 }
	 
	 for(i=0;i<q;i++){
	 	cout<<out[i]<<endl;
	 }

 	
 	
 }