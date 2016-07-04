#	FileName : Chapter1_16.py
'''
过滤序列元素
关键点：
列表式推导1：[fun(x) for n in mylist]
列表式推导2：[fun(x) for n in mylist if T(x)]
列表式推导3：[fun1(x) if T(x) else fun2(x) for n in mylist]
filter(fun, data):以迭代器的方式返回data中使fun(data[i])为True的元素
try/raise/except相当于C++中try/throw/catch
itertools.compress(data, selector)：以迭代器方式返回selector中为True的元素在data中对应的元素
	selector必须是Boolen的列表，data是iterable
迭代器和生成器的使用：http://www.cnblogs.com/kaituorensheng/p/3826911.html
'''
if __name__ == '__main__':
	mylist = [1, 4, -5, 10, -7, 2, 3, -1]
	print([n for n in mylist if n > 0])
	print([n for n in mylist if n < 0])

	genPos = (n for n in mylist if n > 0)
	genNeg = (n for n in mylist if n < 0)
	for val in genPos:
		print(val, ' ', end='')
	print('')
	for val in genNeg:
		print(val, ' ', end='')
	print('')

	def is_int(val):
		try:
			x = int(val)
			return True
		except ValueError:
			return False
	values = ['1', '2', '-3', '-', '4', 'N/A', '5']
	ivals = list(filter(is_int, values))
	print(ivals)

	import math
	sqrt_list = [math.sqrt(n) for n in mylist if n > 0]
	clip_pos = [n if n > 0 else 0 for n in mylist]
	clip_neg = [n if n < 0 else 0 for n in mylist]

	addresses = [
		'5412 N CLARK',
		'5148 N CLARK',
		'5800 E 58TH',
		'2122 N CLARK'
		'5645 N RAVENSWOOD',
		'1060 W ADDISON',
		'4801 N BROADWAY',
		'1039 W GRANVILLE',
	]
	counts = [ 0, 3, 10, 4, 1, 7, 6, 1]
	from itertools import compress
	is_more5 = [n > 5 for n in counts]
	print(is_more5)
	is_more5 = [True if n > 5 else False for n in counts]
	print(is_more5)
	print(list(compress(addresses, is_more5)))
