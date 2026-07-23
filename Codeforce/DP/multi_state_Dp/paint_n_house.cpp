// #include<bits/stdc++.h>;
// using namespace std;
// class Solution {
//   public:
//   using ll=long long ;
// //   vector<
  
//     inline ll solver(int n,int col,int prev, int r[],int g[],int b[],vector<vector<long long>>& dp){
        
//         if(col>=n)return 0;
        
//         if(dp[col][prev+1]!=-1)
//         {
//             return dp[col][prev+1];
//         }
//         ll minValue=1e18;
        
        
//         for(int row=0;row<3;row++){
            
//             if(row!=prev){
//                 int value=0;
//                 if(row==0)value=r[col];
//                 else if(row==1)value=g[col];
//                 else if(row==2)value=b[col];
                
//                 minValue=min(minValue,value+solver(n,col+1,row,r,g,b,dp));
                
//             }
            
            
//         }
//         return dp[col][prev+1]=minValue;
        
//     }
//     long long int distinctColoring(int N, int r[], int g[], int b[]) {
        
//         vector<vector<ll> dp(N,vector<ll>(4,-1));
        
//         return solver(N,0,-1,r,g,b,dp);

        
//     }
// };