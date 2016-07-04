#	FileName : Chapter1_9.py
'''
寻找两个字典中的相同点
关键点：
集合操作（&：并集，-：差集）
dict类的key,items返回的键视图对象、键值对视图对象支持集合操作，values函数返回的值视图对象不支持集合操作（因为可能不是set，sethe tuble不一样）
集合操作可以用来过滤元素
'''

if __name__ == '__main__':
	a = {
		'x' : 1,
		'y' : 2,
		'z' : 3
	}
	b = {
		'w' : 10,
		'x' : 11,
		'y' : 2
	}

	print(a.keys() & b.keys())
	print(a.keys() - b.keys())
	print(a.items() & b.items())
	print(a.items() - b.items())

	c = {key : a[key] for key in a.keys() - {'z', 'w'}}
	print(c)