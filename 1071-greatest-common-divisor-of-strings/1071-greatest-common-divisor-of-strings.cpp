class Solution {
	bool is_valid(string &str1, string &str2, string &ans){
		string s = "";
		while(s.length() < str1.length()) s += ans;
		if(s != str1) return false;

		s = "";
		while(s.length() < str2.length()) s += ans;
		if(s != str2) return false;

		return true;
	}
public:
    string gcdOfStrings(string str1, string str2) {
		int n = str1.length();
		int m = str2.length();
		int k = min(n,m);
        string ans = "";

		for(int i = 0;i<k;i++){
			if(str1[i] == str2[i]){
				string s = str1.substr(0,i + 1);
				if(is_valid(str1,str2,s)) ans = s;
			}
			else return "";
		}

		return ans;
    }
};