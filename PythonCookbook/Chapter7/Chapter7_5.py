#	FileName : Chapter7_5.py
'''
定义有默认参数的函数：
默认参数、None/''/0的判断、默认参数值不能改变、object()
'''

if __name__ == '__main__':
	def spam1(a, b = 42):
		print(a, b)
	spam1(1)
	spam1(1, 2)

	def spam2(a, b = None):
		if b is None:
			b = []
		print(a, b)
	spam2(1)
	spam2(1, 2)

	_no_object_ = object()
	def spam3(a, b = _no_object_):
		if b is _no_object_:
			print('No b value')
		print(a, b)
		return b
	c = spam3(1)
	spam3(1, 2)
	spam3(1, None)

	_no_object_ = 42
	spam3(1)
	print(c)
	c = 42
	print(_no_object_)