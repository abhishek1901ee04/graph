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
    adj[v].push_back(u);
}
void printarr(vector<int>&v){
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
}
// bool bipartitebfs(int ind,vector<int>adj[],vector<int>color){
//     queue<int>q;
//     q.push(ind);
//     color[ind]=1;
//     while(!q.empty()){
//         int node = q.front();
//         q.pop();
//         for(auto it:adj[node]){
//             if(color[it]==-1){
//                 color[it]= 1-color[node];
//                 q.push(it);
//             }
//             else if(color[it] == color[node])
//                 return false;
//         }
//     }
//     return true;
// }

bool bipartiteBfs(int src, vector<int> adj[], vector<int>& color) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
bool bipartiteDfs(int src, vector<int> adj[], vector<int>&color) { 
    for(auto it : adj[src]) {
        if(color[it] == -1) {
            color[it] = 1 - color[src]; 
            if(!(bipartiteDfs(it,adj,color)) )
                return false;
        } else if(color[it] == color[src]) {
            return false; 
        }
    }
    return true; 
}
bool checkBipartite(vector<int>adj[],int n){
    vector<int>color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1)
        {
            color[i] =1;
            if(!bipartiteDfs(i,adj,color))
                return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(checkBipartite(adj,n))
    {
        py;
    }
    else
    {
        pn;
    }
    return 0;
}