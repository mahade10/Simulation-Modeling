#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
int main()
{
    freopen("o.txt","w",stdout);
    int n,i,x[100];
    cout<<"Total random number we have to generate:\n";
    cin>>n;
     srand(time(0));
    for(i=0;i<n;i++){
       x[i]= (rand()%100)+1;
       cout<<x[i]<<" ";
    }
    return 0;
}
