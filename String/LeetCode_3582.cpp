/*You are given a string caption representing the caption for a video.

The following actions must be performed in order to generate a valid tag for the video:

Combine all words in the string into a single camelCase string prefixed with '#'. A camelCase string is one where the first letter of all words except the first one is capitalized. All characters after the first character in each word must be lowercase.

Remove all characters that are not an English letter, except the first '#'.

Truncate the result to a maximum of 100 characters.

Return the tag after performing the actions on caption.*/

class Solution {
public:
    string generateTag(string caption) {
        string result;
        result.push_back('#');
        int n = caption.size();
        bool spacemila = false;
        bool pehlaletter = false;
        for(int i=0;i<n;i++){
            if(caption[i]==' '&&!pehlaletter){
                continue;
            }
            else if(caption[i]==' '&&pehlaletter){
                if(caption[i+1]>='a'&&caption[i+1]<='z'){
                    caption[i+1]=caption[i+1]-32;
                }
                spacemila=true;
                continue;
            }
            else if(!spacemila&&!pehlaletter){
                if(caption[i]>='A'&&caption[i]<='Z'){
                    caption[i]=caption[i]+32;
                }
                pehlaletter=true;
            }
            else if(caption[i-1]!=' '&&(caption[i]>='A'&&caption[i]<='Z')){
                caption[i]=caption[i]+32;
            }
            result.push_back(caption[i]);
            if(result.size()==100){
                break;
            }
        }
        return result;
    }
};
