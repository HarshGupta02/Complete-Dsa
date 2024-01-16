int calculateNumOfProfitableMonths(vector<int>& stockPrices, int k)
{
    int numOfProfitableMonths = 0;
    int stockPriceLen = stockPrices.size();
    vector<int> profitableMonthsArr = { stockPrices[0] };
    if(k == 1) numOfProfitableMonths ++;
    for (int i = 1; i < stockPriceLen; i += 1) 
    {
        const int currStockPrice = stockPrices[i];
        if (currStockPrice > profitableMonthsArr.back())
         {
            if (profitableMonthsArr.size() == k)
             {
              profitableMonthsArr.erase(profitableMonthsArr.begin());
            }
            profitableMonthsArr.push_back(currStockPrice);
        } 
        else 
        {
            profitableMonthsArr = { currStockPrice };
        }
      
        if (profitableMonthsArr.size() == k) 
        {
            numOfProfitableMonths += 1;
        }
    }
  
    return numOfProfitableMonths;
}