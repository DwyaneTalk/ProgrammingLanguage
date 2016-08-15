#	FileName : Chapter8_1.py
'''
对象的字符串显示：__str__()和__repr__()
__str__()对应str(),print();__repr__()对应repr()。对于format，'!r'表示用repr结果格式化，'!s'表示用str结果格式化
'''
if __name__ == '__main__':
	class Pair:
		def __init__(self, x, y):
			self.x = x
			self.y = y
		def __str__(self):
			return '({0.x!s}, {0.y!s})'.format(self)
		def __repr__(self):
			return 'Pair({0.x}, {0.y})'.format(self)
	p = Pair(3, 4)
	print(p)
	print(str(p))
	print(repr(p))
	print('p is {!r}'.format(p))
	print('p is {!s}'.format(p))
	print(eval(repr(p)))
	print(eval(str(p)))
	print(eval(repr(p)) == p)
	print(eval(str(p)) == p)