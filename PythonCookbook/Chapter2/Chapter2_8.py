#	FileName : Chapter2_8.py
'''
正则匹配换行：((?:.|\n))、((?:.|\n)*)、((?:.|\n)*?)或者使用re.DOTALL标志
'''

if __name__ == '__main__':
	import re
	comment = re.compile(r'/\*(.*?)\*/')
	text1 = '/* this is a comment */'
	text2 = '''/* this is a
	... multiline comment */
	... '''
	print(comment.findall(text1))
	print(comment.findall(text2))
	comment = re.compile(r'/\*((?:.|\n)*?)\*/')
	print(comment.findall(text1))
	print(comment.findall(text2))
	comment = re.compile(r'/\*(.*?)\*/', re.DOTALL)
	print(comment.findall(text1))
	print(comment.findall(text2))
