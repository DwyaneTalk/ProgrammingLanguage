#	FileName : Chapter4_7.py
'''
迭代器对象的切片：
迭代器对象事先事先无法确认元素个数，因此无法通过索引操作，也就无法通过索引切片，可以通过itertools.islice()函数实现
itertools.islice通过遍历迭代器对象的元素，实现切片操作，但是该函数会丢弃被遍历到的迭代器元素
'''

if __name__ == "__main__":
	def count(n):
		while True:
			yield n
			n += 1

	cnt = count(0);
	print(cnt)
	import itertools
	for val in itertools.islice(cnt, 0, 20, 3):
		print(val, end=' ')
	print('\n' , cnt)
	for val in itertools.islice(cnt, 0, 20, 3):
		print(val, end=' ')