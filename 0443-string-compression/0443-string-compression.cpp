class Solution {
public:
    int compress(vector<char>& chars) {
        int c = 1;
        char ch = chars[0];

        for (int i =1; i< chars.size(); i++){
            if (chars[i] == ch){
                c++;
                chars.erase(chars.begin()+i);
                i--;
            }
            else{
                if(c!=1){
                    string add = to_string(c);
                    for(int j = 0; j<add.size(); j++){
                        char ne = add[j];                    
                        chars.insert(chars.begin()+i, ne);
                        i++;
                    }
                }
                c = 1;
                ch = chars[i];
            }
        }
        if (c!=1){
            string add = to_string(c);
            for(int j = 0; j<add.size(); j++){
                char ne = add[j];                    
                chars.push_back(ne);
            }
        }

        return chars.size();
    }
};