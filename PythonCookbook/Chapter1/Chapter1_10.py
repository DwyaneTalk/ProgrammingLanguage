#	FileName : Chapter1_10.py
'''
删除序列中重复的元素（保持剩下元素顺序不变）
关键点：
hashable的概念：dict不是hashable，list/tuple等序列是hashable
set(a):生成一个集合，但是集合中保留的元素顺序和a中并不一定一致
'''

def dedupe(items, key = None):
	seen = set()
	for item in items:
		val = item if key == None else key(item)
		if val not in seen:
			yield item
			seen.add(val)

if __name__ == '__main__':
	a = [1, 5, 2, 1, 9, 1, 5, 10]
	setA = set(a)
	print(setA)
	print(list(dedupe(a)))

	d = [
		{'x' : 1, 'y' : 2},
		{'x' : 1, 'y' : 3},
		{'x' : 1, 'y' : 2},
		{'x' : 2, 'y' : 4}
	]
	print(list(dedupe(d, lambda d : (d['x'], d['y']))))
	print(list(dedupe(d, lambda d : d['x'])))