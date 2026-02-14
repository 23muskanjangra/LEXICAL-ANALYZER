#include <stdio.h>
#include <math.h>
int main(){
    printf("Enter number:");
    int num, dCount =0, sum =0;
    scanf("%d",&num);

    int temp=num;
    while(temp>0){
        dCount++;
        temp/=10;
    }
    temp=num;
    while(num>0){
        int rem=num%10;
        num/=10;
        sum+=pow(rem, dCount);
        
    }
    if(sum==temp){
        printf("%d is an Armstrong number.",temp);
    }else{
        printf("%d is not an Armstrong number.",temp);
        
    }
}