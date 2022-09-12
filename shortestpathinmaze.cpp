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
int r, c;
vector<string>graph;
vector<vector<int>>dist;
vector<vector<pi32>>par;
vector<int>dr={1,0,-1,0};
vector<int>dc={0,1,0,-1};
bool check(int x ,int y){
    if(x>=0 && x<r && y>=0 && y<c && graph[x][y]!='#')return 1;
    return 0;
}
void bfs(pi32 st){
    queue<pi32>q;
    q.push(st);
    dist[st.f][st.s]=0;
    par[st.f][st.s] ={-1,-1};
    while(!q.empty()){
        int x = q.front().f;
        int y = q.front().s;
        q.pop();
        for(int k=0;k<4;k++){
            int di = dr[k]+x;
            int dj = dc[k]+y;
            if(check(di,dj) && dist[di][dj] > dist[x][y]+1){
                dist[di][dj] = dist[x][y]+1;
                par[di][dj]=make_pair(x,y);
                q.push({di,dj});
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
    cin>>r>>c;
    //cout<<r<<" "<<c<<endl;
    graph = vector<string>(r);
    for(int i=0;i<r;i++){
        cin>>graph[i];
    }
    // for(auto x: graph)
    //     cout<<x<<endl;
    pi32 st,en;
    cin>>st.f>>st.s;
    cin>>en.f>>en.s;
    dist = vector<vector<int>>(r,vector<int>(c,INT_MAX));
    par = vector<vector<pair<int,int>>>(r,vector<pi32>(c,{0,0}));
    bfs(st);
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout<<par[i][j].first<<" "<<par[i][j].second<<" , ";
    //     }
    //     cout<<endl;
    // }
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