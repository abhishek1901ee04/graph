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

void init_code(){
    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE
}
void addEdge(vector<int>adj[], int u,int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
}
void printarr(vector<int>&v){
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}

bool checkforcyclebfs(int ind,vector<int>adj[],vector<int>&vis){
    queue<pi32>q;
    q.push({ind,-1});
    vis[ind]=1;
    while(!q.empty()){
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto child:adj[node]){
            if(!vis[child])
            {
                q.push({child,node});
                vis[child]=1;
            }
            else if(child!=par)
                return true;
        }
    }
    return false;
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
bool checkforcycledfs(int ind,int parent,vector<int>adj[],vector<int>&vis){
    vis[ind]=1;
    for(auto it:adj[ind]){
        if(!vis[it]){
           if( checkforcycledfs(it,ind,adj,vis))
            return true;
        }
        else if(it!=parent)
            return true;
    }
    return false;
}
void findtoposort(int ind,vector<pi32>adj[],vector<int>&vis,stack<int>&stk){
    vis[ind]=1;
    for(auto node:adj[ind]){
        if(!vis[node.first])
            findtoposort(node.first,adj,vis,stk);
    }   
    stk.push(ind);  
}
void shortestpath(int src,int n,vector<pi32>adj[]){
    vector<int>vis(n,0);
    stack<int>stk;
    for(int i=0;i<n;i++){
        if(!vis[i]){
         findtoposort(i,adj,vis,stk);
        }
    }
    vector<int>dist(n,1e9);
    dist[src]=0;
    while(!stk.empty()){
        int node = stk.top();
        stk.pop();
        for(auto it:adj[node]){
            if(dist[node]+it.second <dist[it.first])
            {
                dist[it.first] = dist[node]+it.second;
            }
        }
    }
    for(auto x:dist)
        cout<<x<<" ";
    cout<<endl;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
    int n,m;
    cin>>n>>m;
    vector<pi32>adj[n];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
    }
    shortestpath(0,n,adj);
    return 0;
}