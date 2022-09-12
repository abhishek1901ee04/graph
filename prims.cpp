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
  

void dfs(ull x, ull s){
    if(s>ans)
        return;
    int cnt=0;
    ull temp = x;
    vector<int>dig(10,0);
    while(temp){
        dig[temp%10]=1;
        temp = temp/10;
        cnt++;
    }
    //cout<<x<<" "<<cnt<<" , ";
    if(mp.count(x) && s>=mp[x])
        return ;
    mp[x]=s;
    if(cnt >=n){
        ans = s;
        return ;
    }
   ull res;
    for(int i =9;i>=2;i--){
        if(dig[i])
        dfs(x*i,s+1);
    }
}
void solve(){
  
    cin>>n>>x;
   dfs(x,0);
   if(ans >=100)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
        
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
  int n=5,m=6;
    vector<pair<int,int> > adj[n]; 
    adj[0].push_back({1,2});
    adj[0].push_back({3,6});
    adj[1].push_back({0,2});
    adj[1].push_back({2,3});
    adj[1].push_back({3,8});
    adj[1].push_back({4,5});
    adj[2].push_back({1,3});
    adj[2].push_back({4,7});
    adj[3].push_back({0,6});
    adj[3].push_back({1,8});
    adj[4].push_back({1,5});
    adj[4].push_back({2,7});
    // Prims Algorithm 
    //cout<<"hello bhsdk"<<endl;
    vector<int>key(n+1,1e9);
    vector<int>mst(n+1,0);
    vector<int>parent(n+1,-1);
    key[0]=0;
    int answeight=0;
    for(int i=0;i<n-1;i++){
        int mini = INT_MAX; int u;
        for(int j=0;j<=n;j++){
            if(mst[j]==0 && key[j]<mini)
            mini = min(mini,key[j]),u=j;
        }
        mst[u]=1;
        for(auto it:adj[u]){
            int node = it.first;
            int weight = it.second;
            if(mst[node]==0 && weight<key[node])
                parent[node]=i,key[node]= weight;
        }
    }
    
     for(int i=1;i<n;i++)
        cout<<parent[i]<<" - "<<i<<endl;
    // cout<<"hello"<<endl;
    return 0;
}