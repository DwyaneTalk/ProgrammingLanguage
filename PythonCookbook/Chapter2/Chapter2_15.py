#	FileName : Chapter2_15.py
'''
在字符串中插入变量：
1、通过str(val)将变量转化成字符串，然后进行字符串连接
2、通过str.format()和str.format_map()进行替换
通过__missing__()函数解决变量不存在的情况
'''

if __name__ == '__main__':
	s = '{name} has {n} messages.'
	print(s.format(name = 'Guido', n = 37))
	name = 'Guido'
	n = 37
	print(s.format_map(vars()))

	class INFO:
		def __init__(self, name, n):
			self.name = name
			self.n = n

	a = INFO('Guido', 37)
	print(s.format_map(vars(a)))

	class safeSub(dict):
		def __missing__(self, key):
			return '{' + key + '}'

	import sys
	def newSub(text):
		return text.format_map(safeSub(sys._getframe(1).f_locals))
	print(newSub('Hello {name}'))
	print(newSub('You have {n} messages'))
	print(newSub('You are {age} years lod?'))

	print('%s has %d messages' %(name, n))
