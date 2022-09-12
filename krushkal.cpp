#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb emplace_back
#define pp pop_back
#define re0 return 0;
#define ull unsigned long long
#define db double
#define Mod 1000000007
#define INF 0x7ffffffffffffff
#define Forp(a,b) for(int i=a;i<b;i++)
#define Form(a,b) for(int j=a;j<b;j++)
#define pi32 pair<int, int >
#define dbg(x) cerr << #x << '=' << x << endl
#define intl(x) x==0 ? 1 : (int)log10(x) + 1
#define py  cout<<"YES"<<endl;
#define pn cout<<"NO"<<endl;
#define vec32 vector<int,int>;
#define vec64 vector<long long ,long long >;
using namespace std;

struct node{
int u,v,wt;
node(int first, int second,int weight){
    u= first;
    v= second; wt=weight;
    }
};

void init_code(){
    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE
}

bool comp(node a ,node b){
    return a.wt<b.wt;
}

int findPar(int u, vector<int>&parent){
       if(u== parent[u] ) return u;
       return parent[u]= findPar(parent[u],parent);
}
void unioon (int u, int v, vector<int>&parent,vector<int>&rank){
       u = findPar(u,parent);
       v = findPar(v,parent);
       if(rank[u]<rank[v]){
              parent[u]=v;
       }
       else if( rank[u]>rank[v])
              parent[v]= u;
       else{
              parent[v]=u;
              rank[u]++;
       }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
       int n=5,m=6;
       vector<node>edges;
       edges.push_back(node(0,1,2));
       edges.push_back(node(0,3,6));
       edges.push_back(node(1,0,2));
       edges.push_back(node(1,2,3));
       edges.push_back(node(1,3,8));
       edges.push_back(node(1,4,5));
       edges.push_back(node(2,1,3));
       edges.push_back(node(2,4,7));
       edges.push_back(node(3,0,6));
       edges.push_back(node(3,1,8));
       edges.push_back(node(4,1,5));
       edges.push_back(node(4,2,7));
       sort(edges.begin(),edges.end(),comp);
       vector<int>parent(n);
       Forp(0,n)
       parent[i]=i;
       vector<int>rank(n,0);
       int cost =0;
       vector<pair<int,int>>mst;
       for(auto it:edges){
              if(findPar(it.u,parent)!= findPar(it.v,parent)){
                     cost+=it.wt;
                     mst.push_back({it.u,it.v});
                     unioon(it.u,it.v,parent,rank);
              }
       }
       cout<<cost<<endl;
       for(auto it:mst){
              cout<<it.first<<" -> "<<it.second<<endl;
       }
    return 0;
}