#	FileName : Chapter2_2.py
'''
检查字符串开头结尾：str.startswith(), str.endswith()
还可以通过切片 + '=='运算符 或者re.match方式
'''
import os

if __name__ == '__main__':
	print('spam.txt'.startswith('file:'))
	print('spam.txt'.endswith('.txt'))
	print('http://www.python.org'.startswith('http://'))

	filenames = os.listdir('.')
	[print(name) for name in filenames if name.endswith(('1.py', '2.py'))]
	print(any(name for name in filenames))

	from urllib.request import urlopen

	def read_data(name):
		if name.startswith(('http:', 'https:', 'ftp:')):
			return urlopen(name).read()
		else:
			with open(name) as f:
				return f.read()

	#print(read_data('http://www.Python.org'))
	ll = [1, 2, 3, 4, 3]
	print(ll)
	print(set(ll))
	print(list(set(ll)))
	import re
	print(re.match('http:|https:|ftp:', 'http://Python.org'))