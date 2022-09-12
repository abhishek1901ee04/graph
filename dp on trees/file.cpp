#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb emplace_back
#define pp pop_back
#define re0 return 0;
#define ull unsigned long long
#define ll long long int
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
#define pe  cout<<"EVEN"<<endl;
#define po cout<<"ODD"<<endl;
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
void bfs(int V,vector<int>g[],vector<int>&res){
    vector<int>vis(V+1,0);
    queue<int>q;
    q.push(0);
    vis[0]=1;
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
// void dfs(int ind,vector<int>g[],vector<int>&res,vector<int>&vis){
//     if(vis[ind])
//         return;
//     vis[ind]=1;
//     res.push_back(ind);
//     for(auto x: g[ind]){
//         if(!vis[x])
//             dfs(x,g,res,vis);
//     }
// }
// vector<int>dfsofgraph(int V,vector<int>g[]){
//     vector<int>vis(V+1,0);
//     vector<int>res;
//     dfs(0,g,res,vis);
//     return res;
// }
vector<int>dp;
void dfs(int a[],vector<int>adj[],int u, int parent){
    dp[u] = a[u-1];
    int maximum = 0;
    for(auto node: adj[u]){
        if (node == parent)
            continue;
        // call dfs oon further traversal
        dfs(a,adj,node,u);
        maximum = max(maximum,dp[node]);

    }
    dp[u]+=maximum;
}
int maximumValue(int arr[],vector<int>adj[]){
    dfs(arr,adj,1,0);
    return dp[1];
}

/*Don't just sit and hope that God will solve this
fucking do some thing, try to observe or solve it a different way.
Use that pen and paper.
If nothing works take a deep breath and start again*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
    int n = 14;
 
    // adjacency list
    vector<int> v[n + 1];
 
    // create undirected edges
    // initialize the tree given in the diagram
    v[1].push_back(2), v[2].push_back(1);
    v[1].push_back(3), v[3].push_back(1);
    v[1].push_back(4), v[4].push_back(1);
    v[2].push_back(5), v[5].push_back(2);
    v[2].push_back(6), v[6].push_back(2);
    v[3].push_back(7), v[7].push_back(3);
    v[4].push_back(8), v[8].push_back(4);
    v[4].push_back(9), v[9].push_back(4);
    v[4].push_back(10), v[10].push_back(4);
    v[5].push_back(11), v[11].push_back(5);
    v[5].push_back(12), v[12].push_back(5);
    v[7].push_back(13), v[13].push_back(7);
    v[7].push_back(14), v[14].push_back(7);
 
    // values of node 1, 2, 3....14
    int a[] = { 3, 2, 1, 10, 1, 3, 9, 1, 5, 3, 4, 5, 9, 8 };
    // initialise dp
      dp = vector<int>(n+1,0);
    // function call
    cout << maximumValue(a, v);
    return 0;
}