#	FileName : Chapter7_7.py
'''
匿名函数捕获变量值
对于lambda中捕获某些变量值，是在运行时捕获变量的值，可以通过指定默认值的方式变成定义时指定
对于def函数中捕获某些参数的默认值，是在定义时捕获变量值
'''
if __name__ == '__main__':
	x = 10
	def add1(y):
		return x + y
	def add2(y, x = x):
		return x + y
	add3 = lambda y : x + y
	add4 = lambda y, x = x : x + y
	print(add1(20))
	print(add2(20))
	print(add3(20))
	print(add4(20))
	x = 20
	print()
	print(add1(20))
	print(add2(20))
	print(add3(20))
	print(add4(20))