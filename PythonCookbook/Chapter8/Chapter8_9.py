#	FileName : Chapter8_9.py
'''
描述器：__get__()、__set__()和__delete__()等方法
'''
if __name__ == '__main__':
	class Integer:
		def __init__(self, name):
			self.name = name
		def __get__(self, instance, owner):
			print('Getting Integer')
			if instance is None:
				return  self
			else:
				return instance.__dict__[self.name]
		def __set__(self, instance, value):
			print('Setting Integer')
			if not isinstance(value, int):
				raise TypeError('Expected a int')
			instance.__dict__[self.name] = value
		def __delete__(self, instance):
			print('Deleting Integer')
			del instance.__dict__[self.name]
	class Point:
		x = Integer('x')
		y = Integer('y')
		def __init__(self, x, y):
			self.x = x
			self.y = y
	a0 = Integer('x')
	a1 = Integer('y')
	a2 = Integer('z')
	p0 = Point(3, 4)
	print(p0.__dict__)
	print(p0.x)
	p0.x = 2
