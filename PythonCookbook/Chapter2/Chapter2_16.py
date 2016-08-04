#	FileName : Chapter2_16.py
'''
以指定列宽格式化字符串
textwrap()，可以指定列宽、首行缩进（initial_indent）、其他行缩进(subsequent_indent)
'''

if __name__ == '__main__':
	s = "Look into my eyes, look into my eyes, the eyes, the eyes, \
    the eyes, not around the eyes, don't look around the eyes, \
    look into my eyes, you're under."
	import textwrap
	print(textwrap.fill(s, 70))
	print(textwrap.fill(s, 40))
	print(textwrap.fill(s, 40, initial_indent = 'XXXX'))
	print(textwrap.fill(s, 40, subsequent_indent = 'SSS'))
