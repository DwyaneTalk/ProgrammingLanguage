#	FileName : Chapter1_4.py
'''
在含有M个元素的查找最大/小的N个元素
技术点：
heapq:一个heap库， 包含：nlargest，nsmallest， heapify，heappop
min，max函数查找列表、元组、字典的最小、大值，key指定Dict大小属性依据
iter：迭代器函数
zip：压缩/解压缩
lambda：定义简单的函数
当N<<M时，用min,max；当N~=M时，通过heapq
'''
import heapq
nums = [1, 8, 2, 23, 7, -1, 18, 23, 42, 37, 2]
print('largest  %d members:' %3 ,heapq.nlargest(3 , nums))
print('samllest %d members:' %3 ,heapq.nsmallest(3, nums))

portfolio = [
	{'name': 'IBM', 'shares': 100, 'price': 91.1},
	{'name': 'APL', 'shares': 50,  'price': 543.22},
	{'name': 'FB',  'shares': 200, 'price': 21.09},
	{'name': 'HPQ', 'shares': 35,  'price': 31.75},
	{'name': 'YHO', 'shares': 45,  'price': 16.35},
	{'name': 'ACM', 'shares': 75,  'price': 115.65}
]
cheap = heapq.nsmallest(3, portfolio, key = lambda s : s['price'])
expensive = heapq.nlargest(3, portfolio, key = lambda s : s['shares'])
print('cheapest 3 companies:',cheap)
print('expensive 3 companies',expensive)

def myNSmallest(size, nums):
	nLen = len(nums)
	size = min([size, nLen])
	it = iter(nums)
	if size == 1:
		return min(it)
	newNums = nums[:]
	heapq.heapify(newNums, )
	result = []
	while size > 0:
		result.append(heapq.heappop(newNums))
		size = size - 1
	return result

print(myNSmallest(3, nums))
