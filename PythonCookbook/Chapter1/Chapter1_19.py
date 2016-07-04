#	FileName : Chapter1_19.py
'''
转换并同时计算数据
关键点：
生成器列表，key,lambda
'''
import os
if __name__ == '__main__':
	files = os.listdir(r'.\\')
	if any(name.endswith('.py') for name in files):
		print('There be python!')
	else:
		print('Sorry, no python')

	s = ('ACME', 50, 123.45)
	print(','.join(str(x) for x in s))
	portinfo = [
		{'name': 'GOOG', 'shares': 50},
		{'name': 'YHOO', 'shares': 75},
		{'name': 'AOL', 'shares': 20},
		{'name': 'SCOX', 'shares': 65}
	]
	print(min(s['shares'] for s in portinfo))

	nums = [1, 2, 3, 4, 5]
	print(sum(x * x for x in nums))
	print(sum((x * x for x in nums)))
	print(sum([x * x for x in nums]))