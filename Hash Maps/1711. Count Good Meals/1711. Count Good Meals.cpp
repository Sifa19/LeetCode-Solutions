
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {

      long long count=0;

	vector<int> powerOfTwoList(22);
	for(int i=0;i<=21;i++){
		powerOfTwoList[i]=pow(2,i);
	}

	map<int,int> frequecy;
	for(int x:deliciousness){
		frequecy[x]++;
	}

	for(int x:deliciousness){
        //so that x shouldnt make a pair with itself
		frequecy[x]=frequecy[x]-1;
        
		for(int i=0;i<=21;i++){
			int target = powerOfTwoList[i]-x;

			if(frequecy.count(target)){
				count=count+frequecy[target];
			}
		}
	}

	return count % 1000000007;
        
    }
};
