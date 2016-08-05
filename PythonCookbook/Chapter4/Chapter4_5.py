#	FileName : Chapter4_5.py
'''
反向迭代：通过reversed()函数作用一个可迭代对象，返回一个迭代器
要求可迭代对象必须实现了__reversed__()函数
'''

if __name__ == '__main__':
	a = [1, 2, 3, 4]
	for val in a:
		print(val, end=' ')
	print()
	for val in reversed(a):
		print(val, end=' ')
	print()
	with open(r'..\work\text.txt') as f:
		for line in f:
			print(line, end='')
		for line in reversed(list(f)):
			print(line, end='')
	print()
	
	class CountDown:
		def __init__(self, value):
			self._value = value
		def __reversed__(self):
			n = 1
			while n <= self._value:
				yield n
				n += 1
		def __iter__(self):
			n = self._value
			while n > 0:
				yield n
				n -= 1
	for value in CountDown(5):
		print(value, end=' ')
	print()
	for value in reversed(CountDown(5)):
		print(value, end=' ')
	print()