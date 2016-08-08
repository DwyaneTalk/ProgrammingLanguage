#	FileName : Chapter4_11.py
'''
同时迭代多个序列：
使用zip/itertools.zip_longest可以输入多个序列，然后返回元素的迭代器，元素中元素分别来自不同的序列
'''

if __name__ == '__main__':
	from itertools import zip_longest
	xpts = [1, 5, 4, 2, 10, 7]
	ypts = [101, 78, 37, 15, 62, 99]
	for x, y in zip(xpts, ypts):
		print(x, y)

	keys = [1, 2, 3]
	vals = ['a', 'b', 'c', 'd' ]
	for key, val in zip(keys, vals):
		print(key, val)
	for key_val in zip(keys, vals):
		print(key_val)
	for key_val in zip_longest(keys, vals):
		print(key_val)
