#	FileName : Chapter4_1.py
'''
遍历迭代器：
1、for * in *
2、通过iter()/next()函数遍历，并捕获StopInteration异常结束
'''

def manual_iter1(values):
	valiter = iter(values)
	try:
		while True:
			value = next(valiter)
			print(value, end=' ')
	except StopIteration:
		pass
def manual_iter2(values):
	valiter = iter(values)	#执行对象的__iter__()
	while True:
		value = next(valiter, None)	#执行对象的__next__()
		if value is None:
			break
		print(value, end=' ')

if __name__ == '__main__':
	items = [1, 2, 3, 4]
	manual_iter1(items)
	manual_iter2(items)