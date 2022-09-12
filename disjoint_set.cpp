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
ull n,x;
map<ull,int>mp;
ull ans =100;

void init_code(){
    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE
}
  
int parent[100000];
int rank[100000];
void makeSet(){
    for(int i=1;i<=n;i++){
        parent[i] = i;
        rank[i]=0;
    }
}
int findPar(int node){
    if(node == parent[node])
        return node;
    return parent[node] =findPar(parent[node]);
}
void union(int u,int v){
    u = findPar(u);
    v= findPar(v);
    if(rank(u) <rank(v))
        parent[u] =v;
    else if(rank(u)>rank(v))
        paarent[v]=u;
    else{
        parent[v]=u;
        rank[u]+=1; 
    }
}

void solve(){
  

        
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
    int n= 5,m=6,source =1;
    vector <pi32>g[n+1];
    // Constructing the graph
    g[1].push_back({2,2});
    g[1].push_back({4,1});
    g[2].push_back({1,2});
    g[2].push_back({3,4});
    g[3].push_back({2,4});
    g[3].push_back({4,3});
    g[3].push_back({5,1});
    g[4].push_back({1,1});
    g[4].push_back({3,3});
    g[5].push_back({2,5});
    g[5].push_back({3,1});  
    // Dijkshtra Algorithm 
    priority_queue<pi32,vector<pi32>,greater<pi32>>pq;
    vector<int>dist_to (n+1,INT_MAX);
    dist_to[source]=0;
    pq.push(make_pair(0,source)); // dist, source
    while(!pq.empty()){
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();
        for(auto it =g[prev].begin();it!=g[prev].end();it++){
            int next = it->first;
            int nextdist= it->second;
            if(dist_to[next] >dist_to[prev]+nextdist){
                dist_to[next] = dist_to[prev]+nextdist;
                pq.push(make_pair(dist_to[next],next));
            }
        }
    }
     cout << "The distances from source " << source << " are : \n";
    for(int i = 1 ; i<=n ; i++) cout << dist_to[i] << " ";
    cout << "\n";
    return 0;
}