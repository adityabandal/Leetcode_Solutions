class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        
        istringstream ss(s);
  
        string word; // for storing each word

        // Traverse through all words
        // while loop till we get 
        // strings to store in string word
        int itr = 0;
        while (ss >> word && itr<k) 
        {
            // print the read word
            ans.append(word);
            ans.push_back(' ');
            // cout << word << "\n";
            itr++;
        }
        ans.pop_back();
        return ans;
    }
};