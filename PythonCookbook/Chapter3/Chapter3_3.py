#	FileName : Chapter3_3.py
'''
数字的格式化输出：
format()，可以指定位数、四舍五入、对齐、千位分隔符等
格式：'[<>^]?width[,]?(.digits)?[eE]?'， ?表示可选部分
'''

if __name__ == '__main__':
	x = 1234.56789
	print(format(x, '0.2f'))
	print(format(x, '>10.1f'))
	print(format(x, '<10.1f'))
	print(format(x, '^10.1f'))
	print(format(x, ','))
	print(format(x, '0,.1f'))
	print(format(x, 'e'))
	print(format(x, '0.2e'))

	print('value is {:^10,.2f}'.format(x))

