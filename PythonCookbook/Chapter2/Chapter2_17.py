#	FileName : Chapter2_17.py
'''
字符串中处理html、xml
'''

if __name__ == '__main__':
	import html
	s = 'Elements are written as "<tag>text</tag>".'
	print(s)
	print(html.escape(s))
	print(html.escape(s, quote=False))

	s = 'Spicy Jalapeño'
	print(s)
	print(s.encode('ascii', errors='xmlcharrefreplace'))

	s = 'Spicy &quot;Jalape&#241;o&quot.'
	from html.parser import HTMLParser
	p = HTMLParser()
	print(p.unescape(s))
	t = 'The prompt is &gt;&gt;&gt;'
	from xml.sax.saxutils import unescape
	print(unescape(t))