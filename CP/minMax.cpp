#include <bits/stdc++.h>

using namespace std;



void miniMaxSum(vector<long long> arr) {
    sort(arr.begin(),arr.end());
    long long min =0 ,max= 0 ;
    for(long long i = 0 ; i<arr.size()-1; i++){
        min+=arr[i];
    }
     for(long long i = 1 ; i<arr.size(); i++){
        max+=arr[i];
    }
    cout<<min <<" "<<max<<endl;

}

int main()
{

   vector<long long> arr ={256741038 ,623958417, 467905213, 714532089, 938071625};
   miniMaxSum(arr);
   return 0 ; 
}
