#include<bits/stdc++.h>
using namespace std;
class SGTree {
public:
  vector<int> seg;
  SGTree(int n) {
    seg.resize(4*n+1);
  }
  void build(int ind,int low,int high,int a[],int orr) {
    if(low == high) {
      seg[ind] = a[low];
      return;
    }
    int mid = (low+high)/2;
    build(2*ind+1,low,mid,a,!orr);
    build(2*ind+2,mid+1,high,a,!orr);
    if(orr) {
      seg[ind] = seg[2*ind + 1]|seg[2*ind + 2];
    }
    else {
      seg[ind] = seg[2*ind + 1] ^ seg[2*ind + 2];
    }
  } 
  int query(int ind,int low,int high,int l,int r) {
    if(low>r || high<l) {
      return 0;
    }
    if(low>=l && high<=r) {
      return seg[ind];
    }
    int mid = (low+high)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return left|right;
  } 
  void update(int ind,int low,int high,int i,int val,int orr) {
    if(low == high) {
      seg[ind] = val;
      return;
    }
    int mid = (low+high)/2;
    if(i <= mid) {
      update(2*ind+1,low,mid,i,val,!orr);
    }
    else {
      update(2*ind+2,mid+1,high,i,val,!orr);
    }
    if(orr) {
      seg[ind] = seg[2*ind + 1]|seg[2*ind + 2];
    }
    else {
      seg[ind] = seg[2*ind + 1] ^ seg[2*ind + 2];
    }
  }
};

int main() {
  int m,n;
  cin>>n>>m;
  int sz = pow(2,n);
  int a[sz]; 
  for(int i=0;i<sz;i++) {
    cin>>a[i];
  }
  SGTree sg1(sz);
  if(n%2 == 1) {
      sg1.build(0,0,sz-1,a,1);
    }
    else {
      sg1.build(0,0,sz-1,a,0);
    }
  while(m--) {
    int p,b;
    cin>>p>>b;
    a[p-1] = b;
    if(n%2 == 1) {
      sg1.update(0,0,sz-1,p-1,b,1);
    }
    else {
      sg1.update(0,0,sz-1,p-1,b,0);
    }
    cout<<sg1.seg[0]<<endl;
  }
}






