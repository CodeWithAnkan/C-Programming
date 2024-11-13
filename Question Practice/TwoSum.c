#include <stdio.h>
#include <stdlib.h>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.


Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/

// * Note: The returned array must be malloced, assume caller calls free().

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    int *result = (int *)malloc(2 * sizeof(int));

    if (result == NULL || nums == NULL || numsSize < 2)
    {
        *returnSize = 0;
        return NULL;
    }

    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                *returnSize = 2;
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    *returnSize = 0;
    free(result);
    return NULL;
}

int main()
{
    int rs, target = 9;
    int a[] = {2, 7, 11, 15};
    int *p = NULL;
    p = twoSum(a, sizeof(a) / sizeof(a[0]), target, &rs);

    if (rs == 0)
    {
        printf("Target not found\n");
    }
    else
    {
        printf("Target found at indices %d and %d\n", p[0], p[1]);
        free(p);
    }

    return 0;
}