#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
    //fstream my_f;
    freopen("s1.txt","w",stdout);
    int a,c,m=1000,n,opt,x[10000],i;
    cout<<"select an option\n";
    cin>>opt;
    cout<<"total random numbers:\n";
    cin>>n;

    if(opt==1){
         a=17,c=47,m;
        x[0]=27;
        cout<<x[0]<<" ";
        for(i=1;i<n;i++){
            x[i]=(a*x[i-1]+c)%m;
            cout<<x[i]<<" ";
        }
    }
    else{
        srand(time(0));
        for (i=0;i<n;i++){
            x[i] = rand()%999;
            cout<< x[i]<<" ";
        }
    }
    fclose(stdout);
    freopen("s1.in", "r", stdin);

    freopen("my_f.txt","w",stdout);
    int k=10,E[12],O[12],d,expect,in,low=0;
    double result =0.0;
     expect = n/k;
     d = m/k;

    for(i=1;i<=k;i++){
        E[i]= expect;
    }

    for(i=0;i<n;i++){
        scanf("%d",&x[i]); // it is not necessary;
        in = (x[i]/d)+1;
        O[in]++;
    }

    cout<<"SL No"<<"\t"<<"class"<<"\t\t"<<"observed"<<"\t"<<"expected"
    <<"\t"<<"(Oi-Ei)^2"<<"\t"<<"((Oi-Ei)^2)/Ei"<<endl;
    cout<<"*************************************************************\n";
    for(i=1;i<=k;i++){
        cout<<i<<"\t"<<low<<"-"<<low+d-1<<"\t\t"<<O[i]<<
        "\t\t"<<E[i]<<"\t\t"<<((O[i]-E[i])*(O[i]-E[i]))<<"\t\t"
        <<(double)((O[i]-E[i])*(O[i]-E[i]))/E[i]<<endl;
        low+=d;
        result = result + (double)((O[i]-E[i])*(O[i]-E[i]))/E[i];
    }
    cout<<"\n"<<"chi-square value: "<<result<<"\n";
    if(result>=1.73 && result <= 23.6){
        cout<<("Result : ACCEPTED\n");
    }
    else{
        cout<<("Result : NOT ACCEPTED\n");
    }

    fclose(stdout);
    return 0;
}
