// TC: O(sqrt(n))

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1)
    {
        cout << n;
    }
    return 0;
}

// TC: O(n)

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	
	for(int i = 2;i<=n;i++){
	    if(n%i == 0){
	        while(n%i==0){
	            cout<<i<<" " ;
	            n= n/i;
	        }
	    }
	}
return 0;
}

// TC: O(n log(log n))

#include <bits/stdc++.h>
using namespace std;

vector<int> buildSPF(int n){
    
    vector<int>vec(n+1);
    
    for(int i =0;i<=n;i++){
        vec[i]=i;
    }
    
    for( int i =2;i*i<=n;i++){
        if(vec[i] == i){
            for(int j = i*i;j<=n;j+=i){
                vec[j] = min(vec[j] , i);
            }
        }
    }
    return vec;
}

int main() {
	int c;
	cin>>c;
	
	vector<int> spf = buildSPF(c);
	
	while(c != 1){
	    cout<<spf[c]<<" ";
	    
	    c/= spf[c];
	}

}

