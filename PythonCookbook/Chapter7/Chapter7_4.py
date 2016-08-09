#	FileName : Chapter7_4.py
'''
函数返回多个值：实际上就是返回一个元组(tuple)，然后返回结果可以赋给一个或多个值
'''

if __name__ == '__main__':
	def myfun():
		return (1, 2, 3, 4)

	a, b, c, d = myfun()
	print(a, b, c, d)
	a = myfun()
	print(a)
	a, *b = myfun()
	print(a, b)