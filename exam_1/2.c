// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numSize, int target, int *returnSize, int *isSuccess)
{
    int *result = (int *)malloc(numSize * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numSize - 1; i++)
    {
        for (int j = 0; j < *returnSize - 1; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *isSuccess = 1;
                return result;
            }
        }
    }
    *isSuccess = 0;
    return result;
}

int main()
{
    int nums[10] = {1, 2, 3, 4, 5};
    int target = 0;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize, isSuccess;

    int *result = twoSum(nums, numsSize, target, &returnSize, &isSuccess);

    int i;

    if (isSuccess == 1)
    {
        printf("Indices: ");
        for (i = 0; i < returnSize; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    else
    {
        printf("No two numbers add up to the target");
    }
    return 0;
}

/*
โปรแกรมต้นแบบมีการประกาศตัวแปลแบบ Dynamic และจัดการตัวแปลอย่างเหมาะสมหรือไม่ เพราะเหตุใด

ตอบ: ไม่เหมาะสม เพราะบางตัวแปลไม่จำเป็นต้องใช้ Pointer เช่น returnSize, isSuccess, result แต่ nums สามารถเป็น Dynamic หรือไม่ก็ได้
*/