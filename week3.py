M = int(input())
nums = []
for i in range(0, M):
    nums.append(input())
N = int(input())
val = [N] * M

for i in range(0, M):
    val[i] -= nums[i]

print val