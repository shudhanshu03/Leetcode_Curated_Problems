class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>v;
        
        int l = 0;
        int h = numbers.size()-1;
        
        while(l<=h)
        {
            if(numbers[l]+numbers[h]==target)
            {
                v={l+1,h+1};
                break;
            }
            else if(numbers[l]+numbers[h] > target)
            {
                h--;
            }
            else{
                l++;
            }
            
        }
        return v;
    }
};