#include<iostream>
using namespace std;
int main()
{
     freopen ("myfile.txt","w",stdout);
    int x[100], i,c,a,m,n;
    cout<<"Total random number we have to generate:\n";
    cin>>n;

    a=67,c=7,m=100;
    x[0]=27;
    cout<<x[0]<<" ";
    for(i=1;i<n;i++){
        x[i]=(a*x[i-1]+c)%m;

        cout<<x[i]<<" ";

    }
    return 0;
}
