#include<bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
int main()
{
     ofstream fp;
     ofstream fp_out;
     fp.open("s2.txt");
    int a,c,m=1000,n,opt,x[10000],number[10000],i,runs=0;
    int mean,variance;
    double z;
    cout<<"select an option\n";
    cin>>opt;
    cout<<"total random numbers:\n";
    cin>>n;

    if(opt==1){
         a=17,c=47,m;
        x[0]=27;
       fp<<x[0]<<" ";
        for(i=1;i<n;i++){
            x[i]=(a*x[i-1]+c)%m;
            fp<<x[i]<<" ";
        }
    }
    else{
        srand(time(0));
        for (i=0;i<n;i++){
            x[i] = rand()%999;
            fp<< x[i]<<" ";
        }
    }
    fp.close();
    fp_out.open("f2.txt");
    int cnt=-1;
    for (i=0;i<n-1;i++){
        if(x[i] <= x[i+1]){
            fp_out<<'+';
            if(cnt != 0){
                runs++;
            }
            cnt=0;
        }
        else{
            fp_out<<'-';
            if(cnt != 1){
                 runs++;
            }
            cnt=1;
        }
    }
    mean=(2*n-1)/3;
    variance=(16*n-29)/90;
    z=((double)runs - mean)/sqrt(variance);

    fp_out<<"\n Total number: "<<n<<endl;
    fp_out<<"\n Total runs:";
    fp_out<<runs<<"\n";
    fp_out<<"mean: "<<mean<<"\n";
    fp_out<<"variance: "<<variance<<"\n";
    fp_out<<"z: "<<z<<"\n";

      if(z>=-1.96 && z <= 1.96){
        fp_out<<"Result : ACCEPTED\n";
    }
    else{
        fp_out<<"Result : NOT ACCEPTED\n";
    }
    return 0;
}
