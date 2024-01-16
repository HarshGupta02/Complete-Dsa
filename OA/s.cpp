string check(string s, string t){
  vector<int> freq1(26, 0);
  vector<int> freq2(26, 0);

  for(int i=0; i<s.size(); i++){
    freq1[s[i]-'a']++;
    freq2[t[i]-'a']++;
  }

  for(int i=0; i<26; i++){
    if(abs(freq1[i]-freq2[i])>3){
        return "NO";
    }
  }
  return "YES";
}

vector<string> func(vector<string> s, vector<string> t){
    int  n= s.size();
    vector<string> ans(n);
    for(int i=0; i<n; i++){
         ans[i] = check(s[i], t[i]);
    }

    return ans;
}