class Solution {
public:
   int minPartitions(string n) {
	int maxDigit = n[0] - '0';
	int nn = n.size();
	for(int i = 1; i<nn; i++) {
		maxDigit = max(maxDigit, n[i] - '0');
	}
	return maxDigit;
   }
};