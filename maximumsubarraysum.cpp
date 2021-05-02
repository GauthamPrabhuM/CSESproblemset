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
void inputarray(ll A[], ll n)
{


  for(ll i=0; i<n; i++)
    cin>>A[i];
}

     
    void solve() 
    {
     
     ll n;
     cin>>n;
     ll a[n];
     inputarray(a,n);
     ll max_so_far = INT_MIN, max_ending_here = 0;

 
    for (ll i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    cout<< max_so_far;

     
    } 


       





    
 int main()
    {
        ios::sync_with_stdio(0);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout<<fixed;
        cout<<setprecision(10);
        //  freopen("input.txt", "r", stdin);
      //freopen("output.txt", "w", stdout);

        ll t=1;
       //cin>>t;
        for(int i=1;i<=t;i++)
                    
           solve();
      
        return 0;
    }
