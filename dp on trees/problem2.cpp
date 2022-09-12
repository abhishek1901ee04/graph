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
vector<int>in,out;
void dfs1(vector<int>v[],int u,int parent){
    in[u] =0;
     // traverse the subtree
    for(auto child: v[u]){
        if(child == parent)
            continue;
        // dfs called 
        dfs1(v,child,u);
        in[u] = max(in[u],1+in[child]);
    }
}
void dfs2(vector<int>v[],int u,int parent){
    int max1=-1,max2=-1;
    for(auto child: v[u]){
        if(in[child]>=max1){
            max2 = max1;
            max1 = in[child];
        }
        else if(in[child] > max2)
            max2  = in[child];
    }
    for(auto child:v[u]){
        if(child == parent)
            continue;
        int longest = max1;
        if(max1 == in[child])
            longest = max2;
        out[child] = 1+ max(out[parent],1+longest);
        dfs2(v,child,u);
    }
}

void printheight(vector<int>v[],int n){
    // calculate in 
    dfs1(v,1,0);
    // calculate out
    dfs2(v,1,0);
    // print all maximum heights
    for(int i=1;i<=n;i++){
          cout << "The maximum height when node "
             << i << " is considered as root"
             << " is = " << max(in[i], out[i])
             << "\n";
    }
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
     v[1].push_back(2), v[2].push_back(1);
    v[1].push_back(3), v[3].push_back(1);
    v[1].push_back(4), v[4].push_back(1);
    v[2].push_back(5), v[5].push_back(2);
    v[2].push_back(6), v[6].push_back(2);
    v[3].push_back(7), v[7].push_back(3);
    v[7].push_back(10), v[10].push_back(7);
    v[7].push_back(11), v[11].push_back(7);
    v[4].push_back(8), v[8].push_back(4);
    v[4].push_back(9), v[9].push_back(4);
 
    // values of node 1, 2, 3....14
    // initialise dp
    // function call
    in.resize(n+1,0);
    out.resize(n+1,0);
    printheight(v,n);
    return 0;
}