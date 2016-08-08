#	FileName : Chapter4_10.py
'''
序列上索引值的迭代：
通过enumrate函数跟踪被迭代的元素的索引值，且可以指定首个元素的索引值
'''
if __name__ == '__main__':
	from collections import defaultdict
	my_list = ['a', 'b', 'c']
	for idx, val in enumerate(my_list):
		print(idx, val)
	for idx, val in enumerate(my_list, 2):
		print(idx, val)

	word_cnt = defaultdict(list)
	with open(r'..\work\text.txt') as f:
		lines = f.readlines()

	for idx, line in enumerate(lines):
		words = [word.strip().lower() for word in line.split()]
		for word in words:
			word_cnt[word].append(idx)
	print(word_cnt)