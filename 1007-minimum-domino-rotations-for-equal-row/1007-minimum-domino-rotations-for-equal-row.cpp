class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int,int>m;
        
        for(int i=0;i<tops.size();i++)
        {
            m[tops[i]]++;
        }
        int m1=INT_MIN;
        int v1;
        for(auto i:m)
        {
            if(m1<i.second)
            {
                m1 = i.second;
                v1 = i.first;
            }
        }
        int m2 = INT_MIN;
        int v2;
        map<int,int>mm;
        
        for(int i=0;i<bottoms.size();i++)
        {
            mm[bottoms[i]]++;
        }
        for(auto i:mm)
        {
            if(m2<i.second)
            {
                m2 = i.second;
                v2 = i.first;
            }
        }
        int c= 0;
        if(m1>m2)
        {
            for(int i=0;i<tops.size();i++)
            {
                if(tops[i]!=v1)
                {
                    if(bottoms[i]!=v1)
                    {
                        return -1;
                    }
                    else{
                        c++;
                    }
                }
            }
        }
        else{
            for(int i=0;i<tops.size();i++)
            {
                if(bottoms[i]!=v2)
                {
                    if(tops[i]!=v2)
                    {
                        return -1;
                    }
                    else{
                        c++;
                    }
                }
            }
        }
        return c;
        
    }
};