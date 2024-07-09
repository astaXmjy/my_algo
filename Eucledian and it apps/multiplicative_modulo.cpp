#include<iostream>
#include<vector>
using namespace std;

vector<int> extendedGCD(int a,int b){

	if(b==0){
		//return the values of x and y 
		return {1,0,a};
	}
	vector<int> result = extendedGCD(b, a%b);

	// After recursive call is over
	int smallX = result[0];
	int smallY = result[1]; 
	int gcd  = result[2];

	int x = smallY;
	int y = smallX - (a/b)*smallY;

	return {x,y, gcd};
}

int modInverse(int a,int m){

	vector<int> result = extendedGCD(a, m);
	int x = result[0];
	int gcd = result[2];

	if(gcd!=1){
		cout<<"Multiplicative Modulo Inverse doesn't exist";
		return -1;
	}

	int ans = (x%m + m)%m;
	return ans;
}
int main(){
	int a,m;
	cin>> a >> m; //relatively prime
	cout << modInverse(a,m) <<endl;


	return 0;
}