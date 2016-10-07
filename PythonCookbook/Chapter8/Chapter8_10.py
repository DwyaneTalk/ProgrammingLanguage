#	FileName : Chapter8_10.py
'''

'''

if __name__ == '__main__':
	class lazy:
		def __init__(self, func):
			print('lazy init')
			self.func = func
		def __get__(self, instance, owner):
			print('lazy getting')
			if instance is None:
				return  self
			else:
				value = self.func(instance)
				setattr(instance, self.func.__name__, value)
				return value
	import math
	class Circle:
		def __init__(self, radius):
			self.radius = radius
		@lazy
		def area(self):
			print('Computing area')
			return math.pi * self.radius ** 2

		@lazy
		def perimeter(self):
			print('Computing perimeter')
			return 2 * math.pi * self.radius
	# c = Circle(4.0)
	# print(c.radius)
	# print(vars(c))
	# print(c.area)
	# print(c.area)
	# print(c.perimeter)
	# print(c.perimeter)
	# print(vars(c))
	# del c.area
	# print(vars(c))
	def lazy(func):
		print('new lazy init1')
		name = '_layz_' + func.__name__
		@property
		def lz(self):
			print(name)
			if hasattr(self, name):
				return getattr(self, name)
			else:
				value = func(self)
				setattr(self, name, value)
				return value
		return lz

	class Point1:
		def __init__(self, radius):
			self.radius = radius
		@lazy
		def area(self):
			print('Computing area')
			return math.pi * self.radius ** 2
		@lazy
		def perimeter(self):
			print('Computing Perimeter')
			return 2 * math.pi * self.radius
	c = Point1(4.0)
	print(vars(c))
	print(c.area)
	print(c.area)
	print(vars(c))