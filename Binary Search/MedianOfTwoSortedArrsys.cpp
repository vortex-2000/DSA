//https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    int total = n1 + n2;

    int i = 0, j = 0, count = 0;
    double prev = 0, curr = 0;

    while (count <= total / 2) {
        prev = curr;
        if (i < n1 && (j >= n2 || nums1[i] <= nums2[j])) {
            curr = nums1[i++];
        } else {
            curr = nums2[j++];
        }
        count++;
    }

    if (total % 2 == 0) {
        return (prev + curr) / 2.0; // Average of two middle elements
    } else {
        return curr; // Middle element
    }
}
};