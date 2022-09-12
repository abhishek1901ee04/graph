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
#define vec32 vector<int,int>
#define vec64 vector<long long ,long long >
using namespace std;
void init_code(){
    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE
}
int n, c;
vector<string>graph;
vector<int>dist;
//vector<vector<pi32>>par;
vector<int>dr={1,0,-1,0};
vector<int>dc={0,1,0,-1};
bool check(int x ,int y){
    if(x>=0 && x<r && y>=0 && y<c && graph[x][y]!='#')return 1;
    return 0;
}
void bfs(int st,vector<int>adj[]){
    deque<int>q;
    q.push_back(st);
    dist[st]=0;
    while(!q.empty()){
        int par = q.front();
        q.pop_front();
        for(auto it: adj[par]){
            int child = it.f;
            int weight = it.s;
            if(dist[child]>dist[par]+weight){
                dist[child]= dist[par]+weight;
                if(weight ==0){
                    q.push_front(child);
                }
                else {
                    q.push_back(child);
                }
            }
        }
    }
}
void ppath(pi32 en){
    if(en ==make_pair(-1,-1))return;
    cout<<en.f<<" "<< en.s<<" -> ";
    ppath(par[en.f][en.s]);
}
void solve(){
    int m;
    cin>>n>>m;
    graph = vector<pi32>adj[n+1];
    for(int i=0;i<n;i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int st,en;
    cin>>st;
    cin>>en;
    dist = vector<int>(n,1e9);
    bfs01(st);
    cout<<dist[en.f][en.s]<<endl;
    ppath(en);
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
    solve();

}