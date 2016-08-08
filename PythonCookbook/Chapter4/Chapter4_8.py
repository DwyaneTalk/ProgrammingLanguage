#	FileName: Chapter4_8.py
'''
跳过迭代器对象的开始部分：
1、正常迭代，显示判断去除；
2、通过itertools.islice进行切片，去除开始部分
3、通过itertools.dropwhile()
'''

if __name__ == "__main__":
	from itertools import islice, dropwhile
	with open(r'..\work\test.txt') as f:
		for line in f:
			print(line, end='')

	with open(r'..\work\test.txt') as f:
		for line in f:
			if not line.startswith('#'):
				print(line, end='')

	with open(r'..\work\test.txt') as f:
		for line in islice(f, 2, None):
			print(line, end='')

	with open(r'..\work\test.txt') as f:
		for line in dropwhile(lambda line: line.startswith('#'), f):
			print(line, end='')

