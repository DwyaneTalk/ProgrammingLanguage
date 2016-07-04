#	FileName : Chapter1_12.py
'''
统计序列中元素出现的次数
关键点：
collections.Counter针对hashable的序列元素，统计每个元素出现的次数，内部是通过一个dict进行存储的
Counter.most_common(N)返回出现次数最多(value值最大)的N个元素
此外，Counter的结果可以通过'+','-'对value进行增减操作
'''

from collections import Counter

if __name__ == '__main__':
	words = [
		'look', 'into', 'my', 'eyes', 'look', 'into', 'my', 'eyes',
		'the', 'eyes', 'the', 'eyes', 'the', 'eyes', 'not', 'around', 'the',
		'eyes', "don't", 'look', 'around', 'the', 'eyes', 'look', 'into',
		'my', 'eyes', "you're", 'under'
	]
	word_counts = Counter(words)
	top_three = word_counts.most_common(3)
	print(word_counts)
	print(top_three)

	for key, value in word_counts.items():
		print('key: %s, value: %d' %(key, value))

	morewords = ['why','are','you','not','looking','in','my','eyes']
	for word in morewords:
		word_counts[word] += 1
	print(word_counts)
	word_counts.update(morewords)
	print(word_counts)

	counter_a = Counter(words)
	counter_b = Counter(morewords)
	counter_c = counter_a + counter_b
	counter_d = counter_a - counter_b
	print(counter_a)
	print(counter_b)
	print(counter_c)
	print(counter_d)