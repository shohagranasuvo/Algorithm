#include <bits/stdc++.h>
using namespace std;
class items {
    public :
    int val ;
    int wt ;
    items (int v ,int w){
        val=v ;
        wt=w;
    }

};
class cmp {
    public:
    bool operator()(pair<double,items> a, pair<double,items> b) {
        return a.first > b.first;
    }
};
class Solution {
  public:

 // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<items> it;
        for(int i = 0; i < val.size(); i++) {
            it.push_back(items(val[i], wt[i]));
        }
        
       vector<pair<double,items>> vec ;
       for(int i = 0 ; i<val.size();i++)
       {
           double d = (double)it[i].val / it[i].wt;
           vec.push_back(make_pair(d, it[i]));
       }
       sort(vec.begin(), vec.end(), cmp());
       double current = 0;
       double ans = 0 ;
       int i = 0 ;
    while(current<=capacity && i<vec.size()){
        if(current+vec[i].second.wt <=capacity){
           ans= ans+vec[i].second.val ;
           current+=vec[i].second.wt ;
            i++;
           // cout<<"Current :"<<current<<endl;

        }
        else
        {
            double le = capacity-current ;
           // cout<<le<<endl ;
            ans =ans+(le*(vec[i].first)) ;
            current+=vec[i].second.wt ;
             i++;
        }
       
    }

    return ans ;


    }
    
};

int main()
{
    vector<int> vec1 = {60,100,120};
    vector<int> vec2 = {10,20,30};
    Solution sol;
    double d = sol.fractionalKnapsack(vec1, vec2, 50);
    cout<<d<<endl;
    return 0;
}
