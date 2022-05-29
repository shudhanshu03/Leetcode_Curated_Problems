class Solution {
public:
    int maxProduct(vector<string>& words) {
        bool alpha[26], check;
        int ans=0;
        
        for(int i=0;i<words.size()-1;++i){
           memset(alpha,0,sizeof(alpha));
           for(char c : words[i]) alpha[c-'a']=1;
           for(int j=i+1;j<words.size();++j){
              check=0;
				 for(char c : words[j]) 
				  if(alpha[c-'a']){check=1;break;}
              if(check)continue; 
              ans=max(ans,int(words[i].length()*words[j].length()));
           }
        }
        return ans;
    }
};