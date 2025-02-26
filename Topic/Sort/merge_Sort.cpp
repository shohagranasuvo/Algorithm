#include <bits/stdc++.h>
using namespace std;

void mergeSS (int * arr , int s , int e ){


     int mid = s+((e-s)/2);
     int length1 = mid-s+1 ;
     int length2 = e- mid ; 
     int * first = new int[length1];
     int * second = new int[length2];
     int mainArrayindex=s ;


     //copy all data in two array

     for(int i = 0 ; i<length1 ; i++)
     {
        first[i]=arr[mainArrayindex++];
     }
     for(int i = 0 ; i<length2 ; i++)
     {
        second[i]=arr[mainArrayindex++];
     }
     int ind1= 0 ; 
     int ind2= 0 ;
     mainArrayindex=s;

     while (ind1<length1 && ind2<length2)
     {

        if(first[ind1]<second[ind2])
        {
            arr[mainArrayindex++]=first[ind1++] ;
        }
        else
        {
            arr[mainArrayindex++]=second[ind2++];

        }
     }
     while(ind1<length1)
     {
        arr[mainArrayindex++]=first[ind1++];


     }
      while(ind2<length2)
     {
        arr[mainArrayindex++]=second[ind2++];


     }
     delete[] first;
     delete[] second;






}

void mergeSort(int * arr , int s ,int e){
    if(s>=e)
    {
        return ; 
    }

    int mid = s+((e-s)/2);
    //for left side 
    mergeSort(arr, s , mid);
    //for right side 
    mergeSort(arr,mid+1 , e) ;
    mergeSS(arr, s,e);


}



void printarr(int * arr,int sizeArr)
{
    for(int i = 0  ; i<sizeArr ;i++)
    {
        cout<<arr[i]<<" " ;
    }cout<<endl; 
}


int main() {
    int arr[14]={3,2,1,6,9,55,5,5,18,1,0,-1,-1,-99};
    int sizeArr = 14;
    int s= 0 ; 
    mergeSort(arr,s, sizeArr-1) ;
    printarr(arr,sizeArr);
    
    
    return 0;
}