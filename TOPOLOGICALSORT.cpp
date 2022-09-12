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
void findtoposort(int ind,vector<int>adj[],vector<int>&vis,stack<int>&stk){
    vis[ind]=1;
    for(auto node:adj[ind]){
        if(!vis[node])
            findtoposort(node,adj,vis,stk);
    }   
    stk.push(ind);  
}
void solve1(int n,vector<int>adj[]){
    vector<int>vis(n+1,0);
    stack<int>stk;
    for(int i=0;i<n;i++){
        if(!vis[i]){
         findtoposort(i,adj,vis,stk);
        }
    }
    cout<< "the topological sorted answer "<<endl;
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}
void findtoposortbfs(int n,vector<int>adj[],vector<int>&res){
    queue<int>q;
    vector<int>intree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i])
            intree[it]++;
    }
    for(int i=0;i<n;i++){
        if(intree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        for(auto it:adj[node]){
            intree[it]--;
            if(intree[it]==0)
                q.push(it);
        }
    }
}
void solve(int n,vector<int>adj[]){
    vector<int>res;
    findtoposortbfs(n,adj,res);
    cout<<"topological sorted answer usign bfs"<<endl;
    for(auto x: res)
        cout<<x<<" ";
    cout<<endl;
}
bool iscycle(int n, vector<int>adj[]){
    queue<int>q;
    vector<int>intree(n,0);
    for(int i=0;i<n;i++){
        for(auto it:adj[i])
            intree[it]++;
    }
    for(int i=0;i<n;i++){
        if(intree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it:adj[node]){
            intree[it]--;
            if(intree[it]==0)
                q.push(it);
        }
    }
    if(cnt==n)return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
    int V = 6;
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);
    solve1(V,adj);
    cout<<endl;
    solve(V,adj);
    if(iscycle(V,adj))
        cout<<"conataining a cycle"<<endl;
    else
        cout<<"not containing any cycle "<<endl;
    return 0;
}