/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target,int *returnSize)
{
    int temp;
    int *ans=NULL;
    ans=(int *)malloc(sizeof(int)*2);
    for(int i=0;i<numsSize-1;i++)
    {
        temp=target-nums[i];
        for(int j=i+1;j<numsSize;j++)
            if(temp==nums[j])
                {ans[0]=i;ans[1]=j;}
                *returnSize=2;
    }
return ans;
}
