#	FileName : Chapter3_1.py
'''
数字的四舍五入：
round(num, ndigits)，ndigit指定保留的位数，当大于0时表示保留ndigits位小数，当小于0时对应保留整数位
'''

if __name__ == '__main__':
	a = 54321.12345
	print(a)
	print(round(a,  3))
	print(round(a,  2))
	print(round(a,  1))
	print(round(a,  0))
	print(round(a, -1))
	print(round(a, -2))
	print(round(a, -3))

	print(format(a, '0.2f'))
	print('value is {:0.2f}'.format(a))