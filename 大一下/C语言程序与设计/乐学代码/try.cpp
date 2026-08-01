#include <stdio.h> 
#define N 100 
void sort(int a[], int n) 
{ 
 for(int i=0; i<n-1; i++) 
 for(int j=0; j<n-1; j++) 
 if(a[j]>a[j+1]){ 
 int t=a[j+1];a[j+1]=a[j]; a[j]=t; 
 } 
} 
int main() 
{ 
 int n, a[N], b[N],i,h,t, score=0; 
 scanf("%d", &n); 
 for(i=0 ; i<n; i++){scanf("%d",&a[i]); // 输入甲的赛马  for(i=0 ; i<n; i++)
 scanf("%d",&b[i]);} // 输入乙的赛马  //排序 
 sort(a, n); 
 sort(b, n); 
 //开始赛马 
 h=0; t=n-1; //乙队头马 h， 乙队尾马 t 
 for(i=0; i<n; i++){ 
 if(a[i]<=b[h]) {t--; score--;} //甲队当前 i 马赢 
 else {h++; score++;}//甲队当前 i 马输 
 }  printf("%d\n", score); } 