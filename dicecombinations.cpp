    #include <iostream>
    #include <bits/stdc++.h>
    #include<stdio.h> 
    #include<string.h>
   #define ll long long int
   #define pb push_back
   #define cl CLOCKS_PER_SEC
   #define pi acos(-1.0)
   #define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
   #define fl freopen ("output.txt","w",stdout);freopen ("input.txt","r",stdin)
   #define no1s(x) __builtin_popcount(x)
   #define parity(x) __builtin_parity(x)
   #define leadingZeros(x) __builtin_clz(x)
#define fr(a,b) for(int i = a; i < b; i++)

#define lp(i, n) for(int i = 0; i < (int)(n); ++i)

   #define trailingZeros(x) __builtin_ctz(x)
     const int maxn = 1e5, maxt = 1e5;
     const int mod = 1e9 + 7;
ll dp[maxn + 1];

   #define mod 1000000007
 #define             pf                          printf


     using namespace std;
     int flag=0;
      ll gcd(ll a, ll b)
      {
        if(b==0)
          return a;
        return gcd(b,a%b);
      }
     ll isPrime(ll n)
     {
         ll flag=1;
       for(ll i=2; i<n; i++)
        {if(n%i==0)
          flag=0;}

        return flag;


     }
     float newPrecision(float n, float i)
{
    return floor(pow(10,i)*n)/pow(10,i);
}
char upper(char s)
{
  return (s+'a'-'A');
}
void inputarray(ll A[], ll n)
{


  for(ll i=0; i<n; i++)
    cin>>A[i];
}

ll power_optimised(ll a, ll n)
{
   ll ans=1;
   while(n>0)
   {
      int last_bit=(n&1);
      if(last_bit)
        ans*=a;
      a=a*a;
      n=n>>1;

   }
   return ans;


}
 ll isOrdinary(ll n)
{
    
    ll arr[10];
    for (int i=0; i<10; i++)
        arr[i] = 0;
 
    while (n > 0)
    {
         int digit = n%10;
 
         if (arr[digit])
           return 0;
 
         arr[digit] = 1;
 
         n = n/10;
    }
    return 1;
}
ll finds(ll r,ll a,ll b)
{
   ll lcm=(a*b)/__gcd(a,b);
   ll times=r/lcm;
   ll remainder=r%lcm+1;
   ll tot=times*b+min(remainder,b);
   return (r-tot);
}
ll isTriangle(ll n)
{ 
      ll sum=0;
     for(int i=1; i<=n; i++)
     {
           sum+=i;
           if(sum==n)
            return 1;
     }
     return 0;

 

}
    

void solve()
{
    
     ll n,m,x,i,j,k,q;

        cin >> n;
        vector<ll> dp(n+1, 0);
        dp[0] = 1;
        fr(1,n+1)
        {
            for(int x = 1; x <= 6; x++)
            {
                if(x > i)
                    break;
                dp[i] = (dp[i] + dp[i-x]) % mod;
            }
        }
        cout << dp[n];
   }

 
 
 
 
 
}
 






    



  

  


    
 


  
  








 
 




    
 int main()
    {
        fastio;
        cout<<fixed;
        cout<<setprecision(10);
    #ifndef ONLINE_JUDGE
  fl;
  #endif

        ll t=1;
      //cin>>t;
        for(int i=1;i<=t;i++)
                    
           solve();
      
        return 0;
    }
