class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int sum = 0;
        int maxSum = 0;
        int i = 0;
        int j = i + 1;

        while (j < prices.size())
        {
            if (prices[i] > prices[j])
            {

                i = j;
                j = i + 1;
            }
            else
            {
                sum = prices[j] - prices[i];
                maxSum = max(maxSum, sum);
                j++;
            }
        }
        if (maxSum < 0)
        {
            maxSum = 0;
        }
        return maxSum;
    }
};