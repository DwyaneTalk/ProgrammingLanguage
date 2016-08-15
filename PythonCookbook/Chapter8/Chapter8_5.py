#	FileName : Chapter8_5.py
'''
类中封装实例的私有数据：
python中没有访问控制，所以可以通过一定的属性、方法命名规则来达到这个目的：
'_name'、'__name'和'__name__'的区别
'''
if __name__ == '__main__':
	class A:
		def __init__(self):
			self.value 		= 'value'
			self._value 	= '_value'
			self.__value	= '__value'
			self.__value__	= '__value__'
		def method(self):
			print('Method')
		def _method(self):
			print('_Method')
		def __method(self):
			print('__Method')
		def __methon__(self):
			print('__Method__')
	a = A()
	print(a.value)
	print(a._value)
	print(a._A__value)
	print(a.__value__)
	a.method()
	a._method()
	a._A__method()
	a.__methon__()

	class B:
		def __init__(self):
			self.__private = 0
		def __private_method(self):
			print('B : private_method')
		def public_method(self):
			print('B : public_method')
			self.__private_method()
	class C(B):
		def __init__(self):
			super().__init__()
			self.__private = 1
		def __private_method(self):
			print('C : private_method')
		def public_method(self):
			print('C: public_method')
			self.__private_method()
			super().public_method()
	b = B()
	c = C()
	print(b.__dict__)
	print(c.__dict__)
	b.public_method()
	c.public_method()

