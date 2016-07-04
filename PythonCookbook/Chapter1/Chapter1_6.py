#	FileName : Chapter1_6.py
from collections import defaultdict

if __name__ == '__main__':
	pairs = [
		['a', 1],
		['b', 2],
		['a', 2],
		['c', 4],
		['a', 2]
	]
	dictList = defaultdict(list)
	dictSet  = defaultdict(set)
	dict1	 = {}
	dict2	 = {}
	for key, value in pairs:
		dictList[key].append(value)
		dictSet[key].add(value)
		dict1.setdefault(key, []).append(value)
		if key not in dict2:
			dict2[key] = set()
		dict2[key].add(value)
	print(dictList)
	print(dictSet)
	print(dict1)
	print(dict2)