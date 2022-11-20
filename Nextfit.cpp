#include<iostream>
using namespace std;

void nextfit(int block[],int process[],int b, int p){
  int allocation[b]={0};
  int j= 0, count= 0;
  
  for(int i=0;i<p;i++){
    while(j<b){
      if(block[j] >= process[i]){
        allocation[i] = j+1;
        block[j] = block[j] - process[i];
        count=0;
        break;
      }
      count++;
      if(count == b){
        break;
      }
      j=(j+1)%b;
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
  int block[5] = {150,50,60,200,100};
  int process[5] = {100,60,40,150,200};
  
  int b = sizeof(block)/sizeof(block[0]);
  int p = sizeof(process)/sizeof(process[0]);
  
  nextfit(block,process,b,p);
  return 0;
}
