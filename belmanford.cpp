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
struct node{
int u;
int v;
int w;
node(int first,int second,int weight){
    u=first;
    v= second;
    w= weight;

    }
};

void init_code(){
    #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();
    int n =6,m=7;
    vector<node>edges;
    edges.push_back(node(0,1,5));
    edges.push_back(node(1,2,-2));
    edges.push_back(node(1,5,-3));
    edges.push_back(node(2,4,3));
    edges.push_back(node(3,2,6));
    edges.push_back(node(3,4,-2));
    edges.push_back(node(5,3,1));
    int src =0;
    vector<int>dist(n,1e9);
    dist[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto it:edges){
            if(dist[it.u]+it.w <dist[it.v])
                dist[it.v]= dist[it.u]+it.w;
        }
    }
    int fl =0;
    for(auto it:edges)
    {
        if(dist[it.u]+it.w< dist[it.v]){
            cout<<-1;
            fl=1;
            break;
        }
    }
    if(!fl){
        for (auto x: dist)
            cout<<x<<" ";
        cout<<endl;
    }

}