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
vector<vector<vector<int>>>dist;
vector<int>dr={1,0,-1,0};
vector<int>dc={0,1,0,-1};
bool check(int x ,int y){
    if(x>=0 && x<r && y>=0 && y<c && graph[x][y]!='#')return 1;
    return 0;
}
void bfs01(vector<pi32>&st,int index){
    deque<pi32>q;
    for(auto it:st){
          q.push_back(it);
          dist[index][it.f][it.s] =0;
    }
    while(!q.empty()){
        int x = q.front().f;
        int y = q.front().s;
        q.pop_front();
        for(int i=0;i<4;i++){
            int di = dr[i]+x;
            int dj = dc[i]+y;            
            if(check(di,dj)){
                int weight = (graph[di][dj]=='.')?1:0;
                if(dist[index][di][dj]>dist[index][x][y]+weight){
                    dist[index][di][dj]= dist[index][x][y]+weight;
                    if(weight ==0){
                        q.push_front({di,dj});
                    }
                    else {
                        q.push_back({di,dj});
                    }
                }
            }
        }
    }
}

void solve(){
    cin>>r>>c;
    graph = vector<string>(r);
    for(int i=0;i<r;i++){
        cin>>graph[i];
    }
    vector<pi32>s[4];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(graph[i][j]=='1')
            {
                s[1].push_back({i,j});
            }
             if(graph[i][j]=='2')
            {
                s[2].push_back({i,j});
            }
             if(graph[i][j]=='3')
            {
                s[3].push_back({i,j});
            }
        }
    }
  
    dist = vector<vector<vector<int>>>(4,vector<vector<int>>(r,vector<int>(c,1e8)));
    bfs01(s[1],1);
    bfs01(s[2],2);
    bfs01(s[3],3);
    int ans =1e9;
      for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int d = dist[1][i][j];
            cout<<d<<"  ";
        }
        cout<<endl;
    }
    cout<<"__________"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int d = dist[2][i][j];
            cout<<d<<"  ";
        }
        cout<<endl;
    }
      cout<<"__________"<<endl;
        for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int d = dist[3][i][j];
            cout<<d<<"  ";
        }
        cout<<endl;
    }
      cout<<"__________"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int d = dist[1][i][j]+dist[2][i][j]+dist[3][i][j];
            if(graph[i][j]=='.')
                ans = min(ans,d-2);
            else if(graph[i][j]!='#')
                ans = min(ans,d);
            cout<<ans<<"  ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
    solve();

}