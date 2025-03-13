//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans ;

        sort(candies , candies+N);
        int min = 0,minInx =0 ,maxindx=N-1 ; 
        int max =0 ;

        while(minInx<=maxindx)
        {
            min+=candies[minInx++];
            maxindx-=K;
        }
        int maxBuy=0 ,maxFree=N-1 ;

         while(maxFree>=maxBuy)
        {
            max+=candies[maxFree--];
            maxBuy+=K;
        }
        
        ans.push_back(min);
        ans.push_back(max) ;



        return ans ;
        
    }



//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    int N, K;
    while (t--)
    {
        
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }


      
         candyStore(candies, N, K);
    }
    
}
// } Driver Code Ends