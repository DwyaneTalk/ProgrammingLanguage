#	FileName : Chapter3_4.py
'''
整数进制处理：
bin()/oct()/hex()将整数转换成2、8、16进制
format可以将整数按2、8、16进制输出
int()可以将不同进制表示的整数字符串转换成整数
'''

x = 1234
print(bin(x))
print(oct(x))
print(hex(x))

print(format(x, 'b'))
print(format(x, 'o'))
print(format(x, 'x'))

x = -1234
print(format(2**32 + x, 'b'))
print(format(2**32 + x, 'o'))
print(format(2**32 + x, 'x'))

print(int('4d2', 16))
print(int('10011010010', 2))