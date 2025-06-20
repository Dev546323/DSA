#include<iostream>
#include<vector>

using namespace std;

int best(vector<int> prices){
    int price=0;
    int maxprofit=0;
    for(int i=0;i<prices.size();i++){
    price = min(price,prices[i]);
         if(prices[i]>price){
            maxprofit=max(prices[i],maxprofit);
        }
    }
    return maxprofit;
}
