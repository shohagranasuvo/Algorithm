#include <iostream>
using namespace std;

int main()
{ bool check =true; 
    while(check==true)
    {
        int sum = 0 ;

         int a , b ;
         cin>>a>>b ; 
         if(a<=0 || b<=0)
         {
            check=false ;
            break ; }
            else
            {
                int minn =(min(a,b));
                int maxx=(max(a,b));
                for(int i =minn  ;i<=maxx;i++)
                {
                    sum=sum+i;
                    cout<<i<<" ";

                }
                cout<<"Sum="<<sum <<endl;
            }

         

    }
   


    
   
    return 0;
}
