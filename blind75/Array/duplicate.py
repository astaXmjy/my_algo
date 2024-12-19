def containsDuplicate(nums):
    hashmap={}
    for i in nums:
        if i in hashmap:
            return True
        hashmap[i]=1
    return False

print(containsDuplicate([1,2,3,1]))