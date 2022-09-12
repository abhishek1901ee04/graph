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
void addedge(vector<int>adj[], int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printarr(vector<int>&v){
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}
// void solve(int n,vector<int>adj[]){
//     vector<int>res;
//     findtoposortbfs(n,adj,res);
//     cout<<"topological sorted answer usign bfs"<<endl;
//     for(auto x: res)
//         cout<<x<<" ";
//     cout<<endl;
// }
void bfs(int n, vector<int>adj[],int src){
    vector<int>dist(n,1e9);
    queue<int>q;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }
    for(auto x:dist)
        cout<<x<<" ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
    int V = 9;
    vector<int> adj[9];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,2,6);
    addedge(adj,6,7);
    addedge(adj,7,8);
    addedge(adj,6,8);
    addedge(adj,5,6);
    addedge(adj,4,5);
    addedge(adj,3,4);
    addedge(adj,0,3);
    addedge(adj,1,3);
    bfs(V,adj,0);
    return 0;
}