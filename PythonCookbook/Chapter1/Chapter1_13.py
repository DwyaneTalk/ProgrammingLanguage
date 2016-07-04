#	FileName : Chapter1_13.py
'''
根据某(几)个关键字对字典进行排序
lambda和itemgetter都可以实现该功能，但itemgetter稍稍快一些
该功能可以用于sorted,min,max等需要key参数的函数
'''

from operator import itemgetter
if __name__ == '__main__':
	rows = [
		{'fname': 'Brian', 'lname': 'Jones', 'uid': 1003},
		{'fname': 'David', 'lname': 'Beazley', 'uid': 1002},
		{'fname': 'John', 'lname': 'Cleese', 'uid': 1001},
		{'fname': 'Big', 'lname': 'Jones', 'uid': 1004}
	]
	rows_by_fname = sorted(rows, key = itemgetter('fname'))
	rows_by_uid = sorted(rows, key = itemgetter('uid'))
	rows_by_name = sorted(rows, key = itemgetter('fname', 'lname'))
	print(rows_by_fname)
	print(rows_by_uid)
	print(rows_by_name)

	rows_by_fname = sorted(rows, key = lambda k : k['fname'])
	rows_by_uid = sorted(rows, key = lambda k : k['uid'])
	rows_by_name = sorted(rows, key = lambda k : (k['fname'], k['lname']))

	min_uid = min(rows, key = itemgetter('uid'))
	max_uid = max(rows, key = lambda k : k['uid'])
	print(rows_by_fname)
	print(rows_by_uid)
	print(rows_by_name)
	print(min_uid)
	print(max_uid)