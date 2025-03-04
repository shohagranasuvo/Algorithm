#include <bits/stdc++.h>
using namespace std;

int main() {
    int  x ; 
    cout<<"How many number You  want to add "<<endl; 
    cin>>x ;

    int arr [x] ; 
    for(int i = 0  ; i <x; i++)
    {
        cin>>arr[i];

    }
    cout<<"Which number You want to search "<<endl ;
    int key ;
    cin>>key ;
    bool cheak = false ;
    for( int i = 0 ; i< x ; i++)
    {
        if (key== arr[i])
        {
            cout<<key <<" has been found "<<endl ;
             cheak =true ;
            break ;
           
        }

    }

    if(cheak == false )
    {
        cout<<key <<" not found "<<endl ;
    }


    
    return 0;
}