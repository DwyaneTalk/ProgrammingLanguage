#	FileName : Chapter8_8.py
'''
子类中扩展父类的property
'''
if __name__ == '__main__':
	class Person:
		def __init__(self, name):
			self.name = name

		@property
		def name(self):
			return self._name
		@name.setter
		def name(self, value):
			if not isinstance(value, str):
				raise TypeError('Expected a string')
			self._name = value
		@name.deleter
		def name(self):
			raise AttributeError('Cannot delete attribute')

	class SubPerson1(Person):
		@property
		def name(self):
			print('SubPreson1 getting name')
			return super().name
		@name.setter
		def name(self, value):
			print('SubPerson1 setting name')
			super(SubPerson1, SubPerson1).name.__set__(self, value)
		@name.deleter
		def name(self):
			print('SubPerson1 deleting name')
			super(SubPerson1, SubPerson1).name.__delete__(self)
	class SubPerson2(Person):
		@Person.name.getter
		def name(self):
			print('SubPerson2 getting name')
			return super().name
		@Person.name.setter
		def name(self, value):
			print('SubPerson2 setting name')
			if not isinstance(value, str):
				raise TypeError('Expected a string')
			super(SubPerson2, SubPerson2).name.__set__(self, value)
	s = SubPerson1('Guido')
	print(s.name)
	s.name = 'Larry'
	s = SubPerson2('Guido')
	print(s.name)
	s.name = 'Larry'