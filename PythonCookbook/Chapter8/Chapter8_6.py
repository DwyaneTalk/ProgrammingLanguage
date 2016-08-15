#	#	FileName : Chapter8_6.py
'''
创建可管理的属性：
使用@property，将方法定义为property
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
			del self._name
	p = Person('lutao')
	print(Person.__dict__)
	print(p.__dict__)
	#p.name = 10
	p.name = 'DwyaneTalk'
	print(p.__dict__)
	print(p.name)
	del p.name
	#print(p.name)
	print(p.__dict__)
	p.name = 'lutao'
	print(p.__dict__)
	print()

	class newPerson:
		def __init__(self, name):
			self.set_name(name)
		def get_name(self):
			return self._name
		def set_name(self, value):
			if not isinstance(value, str):
				raise TypeError('Expected a string')
			self._name = value
		def del_name(self):
			del self._name
		name = property(get_name, set_name, del_name)
	p = newPerson('lutao')
	print(newPerson.__dict__)
	print(p.__dict__)
	#p.name = 10
	p.name = 'DwyaneTalk'
	print(p.__dict__)
	print(p.name)
	del p.name
	# print(p.name)
	print(p.__dict__)
	p.name = 'lutao'
	print(p.__dict__)

