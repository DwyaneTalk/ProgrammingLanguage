#	FileName : Chapter4_14.py
'''
递归展开嵌套序列：
yield from:当想从生成器中调用其他生成器时使用
'''

if __name__ == '__main__':
	from collections import Iterable
	def flatten(items, ig_type = (str, bytes)):
		for x in items:
			if isinstance(x, Iterable) and not isinstance(x, ig_type):
				yield from flatten(x)
			else:
				yield x
	items = [1, 2, [3, 4, [5, 6], 7], 8]
	for item in items:
		print(item, end=' ')
	print()
	for item in flatten(items):
		print(item, end=' ')
	print()
	items = ['Dave', 'Paula', ['Thomas', 'Lewis']]
	for item in flatten(items):
		print(item, end=' ')