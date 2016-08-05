#	FileName : Chapter3_8.py
'''
分数操作：
通过fractions模块定义分数
'''
if __name__ == '__main__':
	from fractions import Fraction
	a = Fraction(5, 4)
	b = Fraction(7, 16)
	c = a * b

	print(a + b)
	print(a * b)
	print(c.numerator)
	print(c.denominator)
	print(float(c))
	print(c.limit_denominator(8))
	x = 3.75
	print(Fraction(*x.as_integer_ratio()))