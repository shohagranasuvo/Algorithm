#include<bits/stdc++.h>
using namespace std ;

void staircase(int n) {
    for(int  i = 0; i<n ;i++)
    { 
        for(int j = 0 ; j<n;j++)
        {if(n-i >j+1)
        {
            cout<<" " ;
            
        }
        else{
            cout<<"#" ;
        }
            
            
        }
        cout<<endl; 
        
        
    }

}
 int main ()
 {
    staircase(4);


    return 0 ; 
 }