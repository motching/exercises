/* Given an array of integers, return indices of the two numbers */
/*  such that they add up to a specific target. */
/* You may assume that each input would have exactly one solution, */
/*  and you may not use the same element twice. */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*brute force */
int* twoSum(int* nums, int numsSize, int target) {
  int *res;
  res = calloc(2,sizeof(int));
  for (int i=0;i<numsSize;i++){
    for (int j=i+1;j<numsSize;j++){
      if (target == nums[i] + nums[j]) {
        res[0]=i;
        res[1]=j;
        return res;
      }
    }
  }
  return res;
}

/*beats 90.12%*/
/*hash table solution: faster on larger arrays*/
/*C does not have a standard hashtable so this is just a hack*/
int* twoSum_hash(int* nums, int numsSize, int target) {
  int *res = malloc(2*sizeof(int));

  int min, max;
  if (nums[0]>nums[1]){
    min = nums[1];
    max = nums[0];
  } else {
    min = nums[0];
    max = nums[1];
  }
  for (int i=0;i<numsSize;i++){
    if (nums[i] >  max) {max = nums[i];}
    if (nums[i] <  min) {min = nums[i];}
  }

  int hashTableSize = max-min+1;
  int hashInitValue = -1;
  int *hashTable = malloc(hashTableSize * sizeof(int));
  for (int i=0;i<hashTableSize;i++) {hashTable[i]=hashInitValue;}

  for (int currentIndex=0;currentIndex<numsSize;currentIndex++){
    int currentElem = nums[currentIndex];
    int hashIndex = currentElem-min;
    int hashTargetIndex = target-currentElem-min;
    if (hashTargetIndex < hashTableSize &&
        hashTargetIndex > -1) {
      if (hashInitValue != hashTable[hashTargetIndex]) {
        res[0] = hashTable[hashTargetIndex];
        res[1] = currentIndex;
        return res;
      } else {
        hashTable[hashIndex] = currentIndex;
      }
    }
  }
  return res;
}

int main () {
  int nums[] = {3,2,3};
  int target = 6;
  int len = sizeof(nums)/sizeof(int);
  int *res;
  res = twoSum(nums, len, target);
  printf("res_bf: %d, %d\n", *res, *(res+1));
  res = twoSum_hash(nums, len, target);
  printf("res_hash: %d, %d\n", *res, *(res+1));
  free(res);
  return 0;
}
