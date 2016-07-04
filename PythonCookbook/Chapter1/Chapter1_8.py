#	FileName : Chapter1_8.py
'''
对数据字典进行计算操作（求最大/小值，排序等）
关键点：
字典排序/比较是以键进行操作的
sorted是库函数，sort是list、tuple，dict等类型的成员函数
zip()函数返回的是只能访问依次的迭代器
min/max/sorted等函数的key参数和lambda定义简单函数
'''

if __name__ == '__main__':
	prices = {
		'ACME' : 45.23,
		'AAPL' : 612.78,
		'IBM'  : 205.55,
		'HPQ'  : 37.20,
		'FB'   : 10.75,
		'MS'   : 205.55
	}

	zip_price = zip(prices.values(), prices.keys())
	min_price = min(zip(prices.values(), prices.keys()))
	max_price = max(zip(prices.values(), prices.keys()))
	sorted_price = sorted(zip(prices.values(), prices.keys()))
	print(zip_price)
	print(min_price)
	print(max_price)
	print(sorted_price)

	min_price = prices[min(prices, key = lambda k : prices[k])]
	max_price = prices[max(prices, key = lambda k : prices[k])]
	print(min_price)
	print(max_price)