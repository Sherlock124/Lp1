#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bestfit(int block[],int process[],int b, int p){
  int allocation[b]={0};
  int index = INT_MAX;
  int minempty = INT_MAX;
  
  for(int i=0;i<b;i++){
    index= INT_MAX;
    minempty = INT_MAX;
    
    for(int j=0;j<p;j++){
      if(block[j]>=process[i]){
        if((block[j]- process[i])<minempty){
          minempty = block[j]- process[i];
          index=j;
        }
      }
    }
    if(index != INT_MAX){
      block[index] = block[index] - process[i];
      allocation[i] = index +1;
    }
  }
  cout<<"process\t"<<"allocated block"<<endl;
  
  for(int i=0;i<p;i++){
    if(allocation[i] != 0){
      cout<<process[i]<<"\t "<<allocation[i]<<endl;
    }
    else{
      cout<<process[i]<<"\t "<<"Not allocated"<<endl;
    }
  }
}
int main(){
  int block[5] = {100,80,150,50,200};
  int process[5] = {60,40,140,150,20};
  
  int b = sizeof(block)/sizeof(block[0]);
  int p = sizeof(process)/sizeof(process[0]);
  
  bestfit(block,process,b,p);
  return 0;
}
