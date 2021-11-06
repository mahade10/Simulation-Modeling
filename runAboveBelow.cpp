#include<bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
int main()
{
    int s[10000];
    int i,n,a=17,c=43,m=1000,k=10,opt;
    cout<<"Total numbers\n";
    cin>>n;
    cout<<"option\n";
    cin>>opt;
    ofstream f;
    f.open("p4.txt");
    s[0]=27;
    if(opt==1){
        f<<s[0]<<" ";
        for(i=1;i<n;i++){
            s[i] = (a*s[i-1] +c)%m;
            f<<s[i]<<" ";;
        }
    }
    else{
        srand(time(0));
        for(i=0;i<n;i++){
            s[i] = (rand()%999)+1;
            f<<s[i]<<" ";
        }
    }
    f.close();
    ofstream f1 ;
    f1.open("p5.txt");
    double  d_mean,mean, variance,z;
    int n1=0,n2=0,cnt,runs=0;
    d_mean = ((double)m-1+0)/2.0;
    cnt =-1;
    for(i=0;i<n;i++){
        if(s[i]>= d_mean){
            f1<<"+";
            n1++;
            if(cnt!=0){
                runs++;
            }
            cnt=0;
        }
        else{
            f1<<"-";
            n2++;
            if(cnt!= 1){
                runs++;
            }
            cnt =1;
        }

    }
     mean = 2*n1*n2/n + .5;
     variance = 2*n1*n2*(2*n1*n2 - n)/n*n*(n-1);
     cout<<n1<<" "<<n2<<" "<<n<<" "<<variance;
     z = ((double)runs - mean)/sqrt(variance);

     f1<<"\n\n";
     f1<<"total runs"<<"\t"<<"above mean"<<"\t"<<"below mean"<<"\t"<<"d_mean\n";
    f1<<runs<<"\t\t"<<n1<< "\t\t"<<n2<<"\t\t"<<d_mean<<endl;
    f1<<"mean" <<"\t\t" <<"sqrt(variance)" <<"\t" <<"z0"<<endl;
    f1<<mean<<"\t\t" <<sqrt(variance)<<"\t\t"<<z<<endl;
      if(z>=-1.96 && z <= 1.96){
        f1<<("Result : ACCEPTED");
    }
    else{
        f1<<("Result : NOT ACCEPTED");
    }

    f1.close();

}
