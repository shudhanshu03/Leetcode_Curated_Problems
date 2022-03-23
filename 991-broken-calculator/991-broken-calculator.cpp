class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int c = 0;
        
        while(target > startValue)
        {
            if(target%2==0)
            {
                target = target/2;
            }
            else{
                target++;
            }
            c++;
        }
        return c+(startValue-target);
    }
};