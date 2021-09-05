class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = nums1.size();
        for(int i=m-1;i>=0;i--){
            nums1[i-m+l] = nums1[i];
        }
        int i = l-m;
        int j = 0;
        int k = 0;
        while(i<l && j<n){
            if(nums1[i]<nums2[j]){
                nums1[k++] = nums1[i++];
            }
            else{
                nums1[k++] = nums2[j++];
            }
        }
        while(i<l){
            nums1[k++] = nums1[i++];
        }
        while(j<n){
            nums1[k++] = nums2[j++];
        }
    }
};