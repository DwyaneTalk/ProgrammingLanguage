#	FileName : Chapter1_7.py
'''
创建一个在迭代和序列化时，保持插入顺序的字典
关键点：
collections.OrderedDict
json.dump()
'''

from collections import OrderedDict
import json

if __name__ == '__main__':
	orderDict = OrderedDict()
	orderDict['foo'] = 1
	orderDict['bar'] = 2
	orderDict['spam'] = 3
	orderDict['grok'] = 4
	orderDict['foo'] = 5
	for key, value in orderDict.items():
		print('key: %s, value: %d' %(key, value))

	print(json.dumps(orderDict))