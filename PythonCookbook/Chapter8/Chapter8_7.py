#	FileName : Chapter8_7.py
'''
子类调用父类的方法：
super()函数
'''

if __name__ == '__main__':
	class A:
		def __init__(self):
			self.x = 0
		def spam(self):
			print('A : spam')
	class B(A):
		def __init__(self):
			super().__init__()
			self.y = 1
		def spam(self):
			super().spam()
			print('B : spam')
	a = A()
	b = B()
	a.spam()
	b.spam()
	print(a.__dict__)
	print(b.__dict__)
	print()

	class Base:
		def __init__(self):
			print('Base.__init__')
		def show(self):
			print('Base show')
	class A(Base):
		def __init__(self):
			Base.__init__(self)
			print('A.__init__')
		def show(self):
			super().show()
			print('A show')
	class B(Base):
		def __init__(self):
			Base.__init__(self)
			print('B.__init__')
		def show(self):
			super().show()
			print('B show')
	class C(A, B):
		def __init__(self):
			A.__init__(self)
			B.__init__(self)
			print('C.__init__')
		def show(self):
			super().show()
			print('C show')
	c = C()
	c.show()
