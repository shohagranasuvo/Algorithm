#include <bits/stdc++.h>
using namespace std;
int diagonalDifference(vector<vector<int>> arr) {
      int rows = arr.size(); // Number of rows
    int cols = arr[0].size(); 
    int k = cols ;
    int sumd1 =0 ,sumd2= 0 ;
    
    for(int i = 0 ; i<rows ;i++)
    {
        for(int  j =  0 ; j<cols;j++)
        {
            if(i==j)
            {
                sumd1+=arr[i][j] ;
                
            }
        }  //cout<<k<<endl;
                sumd2+=arr[i][k-1];
              //  cout<<"For k ,value"<<k<<"    "<<arr[i][k-1] <<endl;
            
            k-- ;
        
    }
   // cout<<sumd1<<"\n"<<sumd2<<endl ;

    int diff = abs(sumd1-sumd2);
    cout<<sumd1<<endl<<sumd2<<endl;
    return diff ;


}

int main()
{
    vector<vector<int>> arr = {{11,2,4}, {4,5,6},{10,8,-12}};
    
  int k =   diagonalDifference(arr);
  cout<<k<<endl;
   
    return 0;
}
