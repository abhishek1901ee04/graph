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
void addEdge(vector<int>adj[], int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printarr(vector<int>&v){
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}
void bfs(int V,vector<int>g[],vector<int>&res){
    vector<int>vis(V+1,0);
    queue<int>q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto x: g[node]){
            if(!vis[x]){
                q.push(x);
                vis[x]=1;
            }
        }
    }
}
void dfs(int ind,vector<int>g[],vector<int>&res,vector<int>&vis){
    if(vis[ind])
        return;
    vis[ind]=1;
    res.push_back(ind);
    for(auto x: g[ind]){
        if(!vis[x])
            dfs(x,g,res,vis);
    }
}
vector<int>dfsofgraph(int V,vector<int>g[]){
    vector<int>vis(V+1,0);
    vector<int>res;
    for(int i=1;i<=V;i++){
        if(!vis[i])
            dfs(i,g,res,vis);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
     vector<int> adj[6];
    
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,1,5);
    addEdge(adj,2,4);
    addEdge(adj,2,1);
    addEdge(adj,3,1);
    addEdge(adj,4,1);
    addEdge(adj,4,2);
    addEdge(adj,5,1);
  vector<int>res;
  bfs(5,adj,res);
  printarr(res);
  vector<int>arr;
    arr =dfsofgraph(5,adj);
    printarr(arr); 

    return 0;
}