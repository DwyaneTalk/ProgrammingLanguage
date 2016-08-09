#	FileName : Chatyer7_6.py
'''
定义匿名或内敛函数：
通过lambda定义匿名函数，一般用于回调函数
'''
if __name__ == '__main__':
	def add1(x, y):
		return x + y
	add2 = lambda x, y : x + y
	print(add1(1, 2))
	print(add2(1, 2))

	names = ['David Beazley', 'Brian Jones', 'Raymond Hettinger', 'Ned Batchelder']
	newNames = sorted(names, key = lambda name : name.split()[-1].lower())
	print(newNames)