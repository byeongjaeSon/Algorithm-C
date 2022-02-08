class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        min_val = sys.maxsize
        profit = 0
        
        for price in prices:
            min_val = min(min_val,price)
            profit = max(profit,price-min_val)
            
        return profit
