#include<bits/stdc++.h>
using namespace std;

void tower_hanoi(int n,char from,char helper,char to){
    if(n==0) return ;
    tower_hanoi(n-1,from,to,helper);
    cout<<from<<"-->"<<to<<endl;
    tower_hanoi(n-1,helper,from,to);
}

int main(int argc, char const *argv[])
{
      tower_hanoi(3,'A','B','C');
    return 0;
}
