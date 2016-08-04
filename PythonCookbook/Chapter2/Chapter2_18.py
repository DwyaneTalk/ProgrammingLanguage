#	FileName : Chapter2_18.py
'''
字符串令牌解析：通过re.compile()获取模式对象，然后使用模式对象的scanner()方法获得token解析
'''

if __name__ == '__main__':
	import re
	from collections import namedtuple
	text = 'foo = 23 + 42 * 10'
	NAME = r'(?P<NAME>[a-zA-Z_][a-zA-Z_0-9]*)'
	NUM = r'(?P<NUM>\d+)'
	PLUS = r'(?P<PLUS>\+)'
	TIMES = r'(?P<TIMES>\*)'
	EQ = r'(?P<EQ>=)'
	WS = r'(?P<WS>\s+)'
	pat = re.compile('|'.join([NAME, NUM, PLUS, TIMES, EQ, WS]))

	def generate_tokens(pat, text):
		Token = namedtuple('Token', ['type', 'value'])
		scanner = pat.scanner(text)
		for m in iter(scanner.match, None):
			yield Token(m.lastgroup, m.group())

	for token in (tok for tok in generate_tokens(pat, text) if tok.type != 'WS'):
		print(token)