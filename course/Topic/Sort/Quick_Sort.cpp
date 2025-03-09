#include <bits/stdc++.h>
using namespace std;

int  partition(int *arr ,int s ,int e)
{
    int pivot =arr[s] ;
    int count = 0 ; 
    
    for(int i = s+1 ; i<=e ; i++)
    {
        if(pivot>arr[i]){
            count++ ;

        }

    }
    int p=s+count;
    swap(arr[s], arr[p]);
    int i=s, j=e;
    while(i<p && j>p)
    {
        while(arr[i]<=pivot)
        {
            i++ ;
        }
        while (arr[j]>pivot)
        {
            j--;
        }
        if(i<p && j>p)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }


return p;
}

void quickSort(int *arr,int s ,int e)

{
    if(s>=e)
    {
        return ;
    }
    int p =partition(arr,s , e) ;
    //left side 
    quickSort(arr , s ,p-1) ;
    //right side
    quickSort(arr , p+1 ,e) ;



}


int main() {
    int arr[8]={10,2,3,2,2,6,8,1};
    int n= 8 ;
    quickSort(arr , 0 , n-1);

    for(int i = 0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }

    
    
    return 0;
}