#include <bits/stdc++.h>
using namespace std;
struct node{
  int v;
  struct node *l;
  struct node *r;
};
void insert(node *p, int x){
  node *next = new node;
  next->l=NULL;
  next->r=NULL;
  next->v=x;
  if(p->v > x) p->l=next;
  else p->r=next;
}
node *search(node *p, int d){
  node *q;
  while(p!=NULL){
    q=p;
    if(p->v > d)p = p->l;
    else p = p->r;
  }
  return q;
}
void preorder(node *p){
  if(p!=NULL){
    cout<<p->v<<' ';
    preorder(p->l);
    preorder(p->r);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n,v;
  node *inode;
  while(cin>>n){
    cin>>v;
    node *ro = new node;
    ro->l = NULL;
    ro->r = NULL;
    ro->v = v;
    for(int i = 1;i < n;i++){
      cin>>v;
      inode =search(ro, v); 
      insert(inode, v);
    }
    preorder(ro);
    cout<<'\n';
  }
}
