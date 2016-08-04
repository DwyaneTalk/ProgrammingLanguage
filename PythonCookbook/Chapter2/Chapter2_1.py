#	FileName : Chapter2_1.py
'''
字符串分割：re.split()
字符串连接：''.join()
'''
import re
if __name__ == '__main__':
	line = 'asdf fjdk; afed, fjek,asdf, foo'
	lines = re.split(r'[;,\s]\s*', line)
	print(lines)
	fields = re.split(r'(;|,|\s)\s*', line)
	print(fields)
	values = fields[::2]
	delimiters = fields[1::2] + ['']
	print(values)
	print(delimiters)
	newLine = ''.join(v + d for v, d in zip(values, delimiters))
	print(newLine)
	print(re.split(r'(?:;|,|\s)\s*', line))