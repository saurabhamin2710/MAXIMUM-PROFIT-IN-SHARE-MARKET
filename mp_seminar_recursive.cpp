
// C++ program to find out maximum profit by
// buying and selling a share atmost k times
// given stock price of n days
#include <climits>
#include <iostream>
using namespace std;
  
//fuction to find maximum of two numbers
int max(int a,int b){
    if(a>b){
        return a;                               
    }else return b;
}

int mp_until(int price[],int n,int k);


// Function to find out maximum profit by buying
// & selling a share atmost k times given stock
// price of n days
int maxProfit(int price[], int n, int k)
{   
    int mp;  

    if(n==0||k==0){

        return 0;//terminate condition for the recursive calls

    }else{

       mp = mp_until(price,n-1,k);//calling mp_until function
      
       return max(maxProfit(price,n-1,k),mp);
    }
}

//function to find the maximum profit until the n-1 days
//from the k transitions
int mp_until(int price[],int n,int k){

    int mp=-10000;

    int test;
    //From this for loop we find the maximum profit until the n-1 days
    for(int j=0;j<n;j++){
        
        test = price[n] - price[j] + maxProfit(price,j,k-1);

        if(test>mp){

            mp = test;

        }
    }
    //returning the max profit up to i-1 days with k transitions
    return mp;
}
  
// The main function
int main()
{
    int k = 3;
    int price[] = { 12,14,17,10,14,13,12,15 };
    int n = sizeof(price) / sizeof(price[0]);
  
    cout << "Maximum profit is: "
         << maxProfit(price, n, k);
  
    return 0;
}