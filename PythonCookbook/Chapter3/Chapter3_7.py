#	FileName : Chapter3_7.py
'''
无穷大与NaN:
定义：通过float()定义；
计算：具有传播性
'''
if __name__ == '__main__':
	a = float('inf')
	b = float('-inf')
	c = float('nan')

	print(a)
	print(b)
	print(c)
	import  math
	print(math.isinf(a))
	print(math.isinf(b))
	print(math.isnan(c))
	print(a + 45)
	print(a - 45)
	print(a * 45)
	print(a / 45)
	print(a / a)
	print(a + b)
	print(c == c)
	print(c is float('nan'))
	print(math.isnan(c))