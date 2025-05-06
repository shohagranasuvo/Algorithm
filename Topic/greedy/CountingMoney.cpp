#include<bits/stdc++.h>
using namespace std;

int main(){
  int arr[10] = {1000, 500, 200, 100, 50 , 20, 10 , 5 , 2,1};
  int x;
  cin>>x;
  int count = 0;
  int i = 0;
  while(x > 0){
    if(x >=arr[i]){
      x = x - arr[i];
      count++;
    }
    else{
      i++;
    }
  }
  cout<<count;
  return 0;
}