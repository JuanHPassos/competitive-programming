#include <bits/stdc++.h>

using namespace std;

bool eh_primo(int x){
    if(x == 1)
        return 0;
    for(int i = 2; i<sqrt(x); i++)
        if(x%i == 0)
            return 0;
    return 1;
}

int main(){
	int x;

	cin>>x;

	if(eh_primo(x)){
		cout << "S" << "\n";
	}else{
		cout << "N" << "\n";
	}
}
