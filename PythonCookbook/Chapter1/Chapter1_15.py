#	FileName : Chapter1_15.py
'''
通过某个字段将字典、实例的序列进行分组：
关键点：
1、先通过sorted或者序列自带sort函数，利用lambda/itemgetter/attrgetter根据某字段进行排序
2、然后用itertools.groupby函数进行分组后返回迭代对象
'''
from operator import itemgetter
from itertools import groupby

if __name__ == '__main__':
	rows = [
		{'address': '5412 N CLARK', 'date': '07/01/2012'},
		{'address': '5148 N CLARK', 'date': '07/04/2012'},
		{'address': '5800 E 58TH', 'date': '07/02/2012'},
		{'address': '2122 N CLARK', 'date': '07/03/2012'},
		{'address': '5645 N RAVENSWOOD', 'date': '07/02/2012'},
		{'address': '1060 W ADDISON', 'date': '07/02/2012'},
		{'address': '4801 N BROADWAY', 'date': '07/01/2012'},
		{'address': '1039 W GRANVILLE', 'date': '07/04/2012'},
	]
	rows.sort(key = itemgetter('date'))
	for data, items in groupby(rows, key=itemgetter('date')):
		print(data, ':')
		for item in items:
			print(' ', item)

