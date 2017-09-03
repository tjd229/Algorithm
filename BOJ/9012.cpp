//category : implementation

#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	int n;
	string s;
	
	//'('
	cin>>T;
	for(int i=0;i<T;i++){		
		cin>>s;
		n=0;
		for(int j=0;j<s.size();j++){
			if(s[j]=='('){
				n++;
			}
			else{
				n--;
				if(n<0)
					break;
			}
		}
		if(n==0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}