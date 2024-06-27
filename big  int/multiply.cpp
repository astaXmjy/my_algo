#include<bits/stdc++.h>
using namespace std;

void multiply(vector<int>&a,int no, int& size){
    int carry=0;
    for(int i=0;i<size;i++){
        int porduct=a[i]*no+carry;
        a[i]=porduct%10;
        carry=porduct/10;
    }

    while (carry)
    {
        a[size]=carry%10;
        carry=carry/10;
        size++;
    }


    
}

void bigFact(int n){
    vector<int> a(10000,0);
    a[0]=1;
    int  size=1;
    for (int i = 2;i<=n; i++)
    {
        multiply(a,i,size);
    }

   for(int i=size-1;i>=0;i--){
    cout<<a[i];
   }
   cout<<endl;
    

}


int main(int argc, char const *argv[])
{
   bigFact(1000);
    return 0;
}
