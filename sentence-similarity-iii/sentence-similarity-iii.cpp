class Solution {
public:
    vector<string> vect(string sentence){
        istringstream ss(sentence);
        vector<string> ans;
        string word; // for storing each word

        // Traverse through all words
        // while loop till we get 
        // strings to store in string word
        while (ss >> word) 
        {
            // print the read word
            // cout << word << "\n";
            ans.push_back(word);
        }
        return ans;
    }
    bool help(vector<string>& a1, vector<string>& a2){
        int n = a1.size();
        int m = a2.size();
        int lo = 0, hi = a1.size()-1;
        int s = 0, e = a2.size()-1;
        while(lo<n && s<m && a1[lo]==a2[s]){
            cout<<a1[lo]<<endl;
            lo++;
            s++;
        }
        while(hi>=0 && e>=0 && a1[hi]==a2[e]){
            cout<<a1[hi]<<endl;
            hi--;
            e--;
        }
        return lo > hi;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> a1 = vect(sentence1);
        vector<string> a2 = vect(sentence2);
        if(a1.size()<a2.size()){
            return help(a1, a2);
        }
        else{
            return help(a2, a1);
        }
        // return false;
    }
};