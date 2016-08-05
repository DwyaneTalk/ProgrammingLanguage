#	FileName : Chapter3_2.py
'''
精确的浮点运算：
通过decimal的Decimal模块
'''

if __name__ == '__main__':
	a = 4.2
	b = 2.1
	print(a + b)
	print(a + b == 6.3)

	from decimal import  Decimal, localcontext
	a = Decimal('4.2')
	b = Decimal('2.1')
	print(a + b)
	print(a + b == '6.3')
	print(a + b == Decimal('6.3'))

	a = Decimal('1.3')
	b = Decimal('1.7')
	print(a / b)
	with localcontext() as ctx:
		ctx.prec = 50
		print(a / b)
		ctx.prec = 3
		print(a / b)

	nums = [1.23e+18, 1, -1.23e+18]
	print(sum(nums))
	import math
	print(math.fsum(nums))