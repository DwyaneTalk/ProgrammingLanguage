#	FileName : Chapter4_12.py
'''
不同集合上 元素的迭代：itertools.chain()可以实现在不同类型的不同集合上顺序 迭代
'''

if __name__ == '__main__':
	from  itertools import chain
	a = [1, 2, 3, 4]
	b = ['x', 'y', 'z']
	for val in a + b:
		print(val, end=' ')
	print()
	for val in chain(a, b):
		print(val, end=' ')
