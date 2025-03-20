/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

//Time Complexity -- O(length of string)

class Solution {
    public int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}
