class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        for i in range(m+n):
            if nums1[i] == 0 :
                n -= 1
                if n < 0 : break
                nums1[i] = nums2[n]
        nums1.sort()
        return nums1
        