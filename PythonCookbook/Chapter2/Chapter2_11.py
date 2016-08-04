#	FileName : Chapter2_11.py
'''
删除字符串中不需要的字符：
str.strip(), str.lstrip(), str.rstrip()删除字符串开头、结尾的指定字符
对于内部的指定格式的字符，可以通过字符替换方式，替换成空字符。
'''

if __name__ == '__main__':
	s = '  hello     world \n  '
	print(s.strip())
	print(s.rstrip())
	print(s.lstrip())

	t = '-----hello====='
	print(t.strip('-='))

	print(s.replace(' ', ''))
	import  re
	print(re.sub('\s+', ' ', s))