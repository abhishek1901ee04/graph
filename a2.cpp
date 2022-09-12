#include <bits/stdc++.h>
#define f first
#define s second
#define mk make_pair
#define pb push_back
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
#define py  cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define vec32 vector<int,int>
#define vec64 vector<long long ,long long >
using namespace std;
void init_code(){
    #ifndef ONLINE_JUDGE

    freopen("input1.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

    #endif // ONLINE_JUDGE
}
int  sub_check_kar(vector<int> &v1, vector<int> &v2){
    int n = v1.size(), m = v2.size();
    int i = 0, j = 0;
    while(i<n and j <m){
        if(v1[i] == v2[j]){
            i++;
            j++;
            if(j == m){
                return 1;
            }
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    return 0;
}

void solve_kar_bhsdk(int t,int n , int k , vector<int>&v1,vector<int>&v2)
{
    
    if(v1 == v2){
        if(k%2==0 || k!=1) {
        	py;
        }
        else if(n==2 && k==1) {
        	py;
        }
        else{
        	pn;
        }
        return;
    }
    if(n == 2){
        if(k%2) {
        	py;
        }
        else {
        	pn;
        }
        return;
    }
    for(int i=0; i<n; i++){
        v1.pb(v1[i]);
    }
    if(sub_check_kar(v1,v2) and k > 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
int main()
{
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);   cout.tie(NULL);
    init_code();

    int temp;
    cin >> temp;

    for(int i=1; i<temp+1; i++){
    		int n,k;
		    cin >> n >> k;
		    vector<int> v1(n), v2(n);
		    for(int i=0; i<n; i++){
		        cin >> v1[i];
		    }
		    for(int i=0; i<n; i++){
		        cin >> v2[i];
		    }

    	cout << "Case #" << i<< ": ";
            solve_kar_bhsdk(i,n,k,v1,v2);

    }

    return 0;
}