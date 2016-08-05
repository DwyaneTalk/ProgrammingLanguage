#	FileName : Chapter3_6.py
'''
python的复数操作：
复数定义：complex(real, imag)或者real + imag j
复数运算：+、-、*、/以及常见数学操作(cmath模块里，math模块里不行)
python标准数学函数模块都不能产生复数、可以使用cmath模块
'''

if __name__ == '__main__':
	a = complex(2, 4)
	b = 3 - 5j
	print(a)
	print(b)
	print(a + b)
	print(a - b)
	print(a * b)
	print(a / b)
	print(a.real)
	print(a.imag)
	print(a.conjugate())

	import cmath
	print(cmath.sin(a))
	print(cmath.cos(a))
	print(cmath.exp(a))
	print(3 + cmath.sqrt(-1))
