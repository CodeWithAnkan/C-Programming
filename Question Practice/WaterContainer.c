#include <stdio.h>
#include <stdlib.h>
/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store. Notice that you may not slant the container.
*/

/* BRUTE FORCE
int maxArea(int* height, int heightSize) {
    int maxWater = 0;
    for (int i = 0; i < heightSize; i++)
    {
        for (int j = i + 1; j < heightSize; j++)
        {
            int w = j - i;
            int ht = min(height[i], height[j]);
            int currWater = w * ht;
            maxWater = max(maxWater, currWater);
        }

    }
    return maxWater;

}
*/

// OPTIMAL SOLUTION - 2 pointer approach

int maxArea(int *height, int heightSize)
{
    int lp = 0, rp = heightSize - 1, maxWater = 0;
    while (lp < rp)
    {
        int w = rp - lp;
        int ht = fmin(height[lp], height[rp]);
        int currWater = w * ht;
        maxWater = fmax(maxWater, currWater);

        height[lp] < height[rp] ? lp++ : rp--;

    }
    return maxWater;
}