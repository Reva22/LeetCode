//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here  
        long long int l=0,h=x;
        if(x==0){
            return 0;
        }
        if(x==1){
            return 1;
        }
        
        long long int close=-1;
        
        while(l<=h){
            long long int m = (l+h)/2;
            long long int o = m*m;
            long long int p = close*close;
            
            if(o<=x){
                if((x-o)<=(x-p)){
                    close=m;
                }
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        
        return close;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends