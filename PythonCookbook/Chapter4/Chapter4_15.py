#	FileName : Chapter4_15.py
'''
合并排序的多个序列并迭代：heapq.merge实现，内部通过堆实现，但是要保证原始的序列必须是有序的，heapq.merge只是每次取出最小的
'''
if __name__ == '__main__':
	import heapq
	a = [1, 4, 7, 10]
	b = [2, 5, 6, 11]
	for c in heapq.merge(a, b):
		print(c, end=' ')
	print()
	b = [6, 5, 2, 11]
	for c in heapq.merge(a, b):
		print(c, end=' ')
	print()