#	FileName : Chapter1_20.py
'''
合并多个字典或映射
关键点：
collections.ChainMap：合并多个字典但不产生新的字典数据，所以增删改会影响源字典
dict.update：合并多个字典并产生新的字典，数据独立存储
'''
from collections import ChainMap
if __name__ == '__main__':
	a = {'x' : 1, 'z' : 3}
	b = {'y' : 2, 'z' : 4}
	c = ChainMap(a, b)
	print(a)
	print(b)
	print(c)
	print(len(c))
	print(list(c.keys()))
	print(list(c.values()))

	c['z'] = 10
	c['w'] = 40
	del c['x']
	b['y'] = 20
	print(a)
	print(b)
	print(c)

	values = ChainMap()
	values['x'] = 1
	values = values.new_child()
	values['x'] = 2
	values = values.new_child()
	values['x'] = 3
	print(values)
	print(values['x'])
	values = values.parents
	print(values)
	print(values['x'])
	values = values.parents
	print(values)
	print(values['x'])

	a = {'x' : 1, 'z' : 3}
	b = {'y' : 2, 'z' : 4}
	merged = dict(b)
	merged.update(a)
	print(a)
	print(b)
	print(merged)
	a['x'] = 13
	print(merged)