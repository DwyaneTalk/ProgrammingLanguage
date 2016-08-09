#	FileName : Chapter7_3.py
'''
函数注解：给函数增加额外信息
'''

if __name__ == '__main__':
	def add1(x, y):
		return x + y
	def add2(x:int, y:int) ->int:
		return x + y

	print(help(add1))
	print(help(add2))
	print(add1.__annotations__)
	print(add2.__annotations__)