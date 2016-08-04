#	FileName : Chapter2_4.py
'''
字符串匹配：
特定的匹配：str.startswith(),str.endswith(),str.find(),fnmatch, fnmatchcase等
正则表达式匹配：re.match(), pat = re.compile(), pat.match(), pat.findall(), pat.finditer()
'''

import re
if __name__ == '__main__':
	text = 'yeah, but no, but yeah, but no, but yeah'
	print(text == 'yeah')
	print(text.startswith('yeah'))
	print(text.endswith('yeah'))
	print(text.find('but'))

	text1 = '11/27/2012'
	text2 = 'Nov 27, 2012'
	print(re.match(r'\d+/\d+/\d+', text1))
	print(re.match(r'\d+/\d+/\d+', text2))

	pat = re.compile(r'\d+/\d+/\d+')
	print(pat.match(text1))
	print(pat.match(text2))

	newText = 'Today is 11/27/2012. PyCon starts 3/13/2013.'
	print(pat.findall(newText))
	print([data.group() for data in pat.finditer(newText)])

	pat = re.compile(r'(\d+)/(\d+)/(\d+)')
	print(pat.match(text1).group())
