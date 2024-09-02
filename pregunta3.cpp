#include<bits/stdc++.h>
#define ll long long int

#define all(a) a.begin(),a.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define vi vector<int>
#define vll vector<ll>
#define vct vector
#define pb push_back
#define er erase
#define fi(i,a,n,w) for(int i =a;i<n;i+=w)
#define fl(i,a,n,w) for(ll i=a;i<n;i+=w)
#define fr first
#define se second
#define sz(a) a.size()
#define mstr(r) for(auto i:r)cout<<i<<" ";
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ingr(r) fi(i,0,sz(r),1)cin>>r[i]; 

using namespace std;

int binarySearch(vector<int> &arr,int n,int key){
	int l=0;
	int r=n-1;
	int mid;

	while(l<=r){
		mid=(l+r)/2;
		if(arr[mid]==key)
			return mid;
		else if(key>arr[mid])
			l=mid+1;
		else 
			r=mid-1;
	}
	return -1;
}

void solve(){

	int n; cin>>n;
	vector<int> r={1,1,1,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,7,7,7,7,7,9};
	int tam=r.size()-1;


	if(tam==0){
		cout<<"No hay registro en las tablas";
	}
	else if(tam==1){
		cout<<"Solo hay un registro en la tabla";
	}
	else {
		int val=binarySearch(r,tam-1,n);

		if(val==-1)
			cout<<"no se ha encontrado registro de alguna tabla indexada";
		else 
			cout<<"se ha encontrado la tabla indexada en la posicion "<<val;
	}
		

}




int main(){

#ifndef ONLINE_JUDGE
freopen("D:/Problem Set Competitiva/input.txt","r",stdin);
freopen("D:/Problem Set Competitiva/output.txt","w",stdout);
#endif
fast
	int t=1;
	while(t--){
		solve();
	}

	return 0;
}