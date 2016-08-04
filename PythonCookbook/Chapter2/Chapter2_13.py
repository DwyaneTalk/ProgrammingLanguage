#	FileName : Chapter2_13.py
'''
字符串对齐：str.ljust()/str.rjust()/str.center()可以实现左/右/居中对齐，并可以指定填充后总长度长度和填充字符（默认为空格）
format()函数也提供了对齐字符串的功能，同时可以对多个字符串进行对其操作，并可以对齐非字符串变量（整数、小数等）
'''

if __name__ == '__main__':
	text = 'Hello World!'
	print(text.ljust(len(text) + 6, '='))
	print(text.rjust(len(text) + 6))
	print(text.center(len(text) + 6, '+'))

	print(format(text, ''.join(['=<', str(len(text) + 6)])))
	print(format(text, ''.join(['=<', str(len(text) + 6)])))
	print(format(text, '=<' + str(len(text) + 6)))
	print('{:+>8} {:=<9}'.format('Hello', 'World!'))

	x = 1.2345
	print(format(x, '>10'))