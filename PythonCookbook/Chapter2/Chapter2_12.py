#	FileName : Chapter2_12.py
'''
审查清理字符串：
str.upper()、str.lower()、str.replace()、re.sub()、unicodedata.normalize()等实现不同功能的基础处理
str.translate()通过构造替换字典进行处理
'''

if __name__ == '__main__':
	s = 'pýtĥöñ\fis\taWesome\r\n'
	print(s)
	print(s.upper())
	print(s.lower())
	print(s.replace('W', 'w'))

	remap = {
		ord('\t') : ' ',
		ord('\f') : ' ',
		ord('\r') : None
	}
	a = s.translate(remap)
	print(a)

	import unicodedata, sys
	cmb_chrs = dict.fromkeys(c for c in range(sys.maxunicode) if unicodedata.combining(chr(c)))
	b = unicodedata.normalize('NFD', a)
	print(b)
	print(b.translate(cmb_chrs))

	x = '\u0661\u0662\u0663'
	digitmap = {c : ord('0') + unicodedata.digit(chr(c)) for c in range(sys.maxunicode) if unicodedata.category(chr(c)) == 'Nd'}
	print(len(digitmap))
	print(x.translate(digitmap))
	print(b.encode('ascii', 'ignore').decode('ascii'))