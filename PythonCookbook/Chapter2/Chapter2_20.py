#	FileName : Chapter2_20.py
'''
字节字符串和字节数组相关操作：
字节字符串和字节数组，可以类似文本数组进行大部分操作（如切片、查找、正则匹配、分割、替换等，单需要同样的字节字符串作为参数）
不同在于：1、字节字符串索引操作返回整数而不是字符；2、字节字符串不能提供或打印美观的字符串表示，因此也不能格式化操作（可以与ascii互相转换）；
'''

if __name__ == '__main__':
	data = b'Hello World'
	print(data[0:5])
	print(data.startswith(b'Hello'))
	print(data.split())
	print(data.replace(b'Hello', b'Hello Cruel'))

	data = bytearray(b'Hello World')
	print(data[0:5])
	print(data.startswith(b'Hello'))
	print(data.split())
	print(data.replace(b'Hello', b'Hello Cruel'))

	data = b'FOO:BAR,SPAM'
	import re
	print(re.split(b'[:,]', data))
	print(data.decode('ascii'))

	print('{:10s} {:10d} {:10.2f}'.format('ACME', 100, 490.1).encode('ascii'))