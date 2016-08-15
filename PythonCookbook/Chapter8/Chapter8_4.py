#	FileName: Chapter8_4.py
'''
对象实例动态绑定属性和方法，并通过__slot__限制可绑定的属性
__slot__、MethodType
'''

if __name__ == '__main__':
	class Student:
		pass
	s = Student()
	print(s.__dict__)
	s.name = 'Micheal'
	print(s.__dict__)
	def set_age(self, age):
		self.age = age
	from types import MethodType
	s.set_age = MethodType(set_age, s)
	print(s.__dict__)
	s.set_age(25)
	print(s.__dict__)

	def set_score(self, score):
		self.score = score
	Student.set_score = set_score
	Student.score = 10
	s1 = Student()
	s1.set_score(20)
	s.set_score(30)
	print(Student.__dict__)
	print(s1.__dict__)
	print(s.__dict__)

	class Date:
		__slots__ = ['year', 'month', 'day']
		def __init__(self, year, month):
			self.year = year
			self.month = month
	d = Date(2012, 12)
	#d.week = 'Mon'
	d.day = 21
