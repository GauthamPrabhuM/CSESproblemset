    #include <iostream>
    #include <bits/stdc++.h>
    #include<stdio.h> 
    #include<string.h>

     #define ll long long
    using namespace std;
     int flag=0;
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

     
    void solve() 
    {
     
     ll  n;
     cin>>n;
     vector<ll> v;

     for(int i=0; i<n-1; i++)
     {
        ll a;
        cin>>a;
        v.push_back(a);

     }    

     ll sum=0;
     for(ll i=0; i<n-1; i++)
     sum+=v[i];
      ll ans=((n*(n+1))/2)-sum;
     cout<<ans;
    }


       





    
 int main()
    {
        ios::sync_with_stdio(0);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout<<fixed;
        cout<<setprecision(10);
            // freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ll t=1;
       //cin>>t;
        for(int i=1;i<=t;i++)
                    
           solve();
      
        return 0;
    }