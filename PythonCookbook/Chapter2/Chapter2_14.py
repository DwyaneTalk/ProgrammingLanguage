#	FileName : Chapter2_14.py
'''
合并连接字符串：
str.join()连接list、tuble等里面多个字符串，str是分隔符。
此外对于简单的链接，可以简单的使用'+'运算符
此外format也可以实现字符串链接
'''

if __name__ == '__main__':
	parts = ['Is', 'Chicago', 'Not', 'Chicago?']
	print(' '.join(parts))
	print(','.join(parts))
	print(''.join(parts))

	a = 'Is Chicago'
	b = 'Not Chicago?'
	print(a + ' ' + b)

	print('{} {}'.format(a, b))

	def sample():
		yield 'Is'
		yield 'Chicago'
		yield 'Not'
		yield 'Chicago?'
	' '.join(sample())