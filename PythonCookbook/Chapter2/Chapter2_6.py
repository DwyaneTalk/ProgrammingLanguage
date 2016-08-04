#	FileName : Chapter2_6.py
'''
字符串搜索、替换（忽略大小写）
使用re.sub时，提供re.IGNORECASE标志
'''

if __name__ == '__main__':
	text = 'UPPER PYTHON, lower python, Mixed Python'
	import re
	print(re.findall('python', text))
	print(re.findall('python', text, flags = re.IGNORECASE))
	print(re.sub('python', 'snake', text))
	print(re.sub('python', 'snake', text, flags = re.IGNORECASE))