#	FileName : Chapter4_9.py
'''
迭代遍历集合中元素的排列组合
itertools.permutations,itertools.combinations()和itertools.combinations_with_replacement()分别产生所有的排列。所有的组合，所有的元素可重复组合
'''

if __name__ == '__main__':
	from itertools import permutations, combinations, combinations_with_replacement
	items = ['a', 'b', 'c']
	for p in permutations(items):
		print(p, end=' ')
	print()
	for p in combinations(items, 3):
		print(p, end=' ')
	print()
	for p in combinations(items, 2):
		print(p, end=' ')
	print()
	for p in combinations_with_replacement(items, 3):
		print(p, end=' ')
	print()
	for p in combinations_with_replacement(items, 2):
		print(p, end=' ')
	print()