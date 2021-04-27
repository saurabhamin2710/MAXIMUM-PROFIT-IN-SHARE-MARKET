
// C++ program to find out maximum profit by
// buying and selling a share atmost k times
// given stock price of n days
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
//Array to for the memoization 
vector<vector<int > > t;

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
{   int mp;
    if(n==0||k==0){
        return 0;//termination condition for the recursive calls
    }

    //if the t[n][k] array has updated the value the return it directly
    if(t[n][k]!=INT_MIN){
        return t[n][k];
    }
    
     mp = mp_until(price,n-1,k);
     //memoization of the result in t array
     t[n][k] = max(maxProfit(price,n-1,k),mp);


return t[n][k];
    
}

//function to find the maximum profit until the n-1 days
//from the k transitions
int mp_until(int price[],int n,int k){

    int mp=INT_MIN;
    
    int test;

     //From this for loop we find the maximum profit until the n-1 days
    for(int j=0;j<n;j++){

        test = price[n] - price[j] + maxProfit(price,j,k-1);

        if(test>mp){

            mp = test;

        }
    }
return mp;
}
  
// Driver code
int main()
{
    int k = 2;

    int price[] = { 5,10,22,75,65,80 };

    int n = sizeof(price) / sizeof(price[0]);

    t.resize(n+1);

    //storing all elemts of t register with int_min
    for(int i=0;i<n+1;i++){

        t[i].resize(n+1);

        for(int j=0;j<k+1;j++){

           t[i][j] = INT_MIN;

        }
    }

    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for (int i = 0; i <= k; i++)
        t[i][0] = 0;
  
    // profit is 0 if we don't do any transation
    // (i.e. k =0)
    for (int j = 0; j <= n; j++)
        t[0][j] = 0;

    cout << "Maximum profit is: "
         << maxProfit(price, n, k);
  
    return 0;
}
