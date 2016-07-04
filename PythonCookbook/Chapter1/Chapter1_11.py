#	FileName : Chapter1_11.py
'''
命名切片：避免大量、重复的硬编码切片下标
关键点：
slice函数返回一个命名切片对象
slice函数可以设置、查看切片的起点、终点和步长
slice.indices()可以调整切片的长度（保持起点和步长不变）,返回包含起点、终点和步长的3个元素的tuple，可以通过'*'解压缩后作为range函数的参数
'''

if __name__ == '__main__':
	record = '....................100 .......513.25 ..........'
	cost_1 = int(record[20:23]) * float(record[31:37])
	shares = slice(20,23)	#默认不长为1
	prices = slice(31,37)
	cost_2 = int(record[shares]) * float(record[prices])
	print(shares)
	print(prices)
	print(cost_1)
	print(cost_2)

	items = [0, 1, 2, 3, 4, 5, 6]
	a = slice(2, 4)
	print(items[2 : 4])
	print(items[a])
	print(items)
	del items[a]
	print(items)

	a = slice(5, 50, 2)
	print(a.start)
	print(a.stop)
	print(a.step)

	s = 'HelloWorld'
	a.indices(len(s))
	print(a)
	print(a.indices(len(s)))
	for i in range(*a.indices(len(s))):
		print(s[i])