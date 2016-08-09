#	FileName : Chapter7_12.py
'''
访问闭包中的变量：
1、通过闭包内的函数进行访问；2、将闭包的内部实例复制到一个类的字典实例中，并返回
'''

if __name__ == '__main__':
	def sample():
		n = 0
		def func():
			print('n = ', n)
		def get_n():
			return n
		def set_n(newN):
			nonlocal n
			n = newN
		func.get_n = get_n
		func.set_n = set_n
		return func
	f = sample()
	f()
	f.set_n(2)
	f()
	print('n = ', f.get_n())

	import sys
	class ClosureInstance:
		def __init__(self, locals=None):
			if locals is None:
				locals = sys._getframe(1).f_locals
			self.__dict__.update((key, value) for key, value in locals.items() if callable(value))

		def __len__(self):
			return self.__dict__['size']()

	def Stack():
		items = []
		def pop():
			return items.pop()
		def push(item):
			items.append(item)
		def size():
			return len(items)
		def show():
			print(items)
		return ClosureInstance()
	s = Stack()
	s.push(10)
	s.show()
	s.push(20)
	s.show()
	print(len(s))
