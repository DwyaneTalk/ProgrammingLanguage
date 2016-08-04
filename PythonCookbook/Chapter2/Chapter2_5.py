#	FileName : Chapter2_5.py
'''
字符串搜索、替换(大小写敏感)：
简单替换：str.replace(ori, new)
负责替换：re.sub(ori, new), re.subn(ori, new)，可以指定替换模式或者通过回调函数指定替换方式
'''
import  re
if __name__ == '__main__':
	text = 'yeah, but no, but yeah, but no, but yeah'
	print(text.replace('yeah', 'yep'))

	text = 'Today is 11/27/2012. PyCon starts 3/13/2013.'
	print(re.sub(r'(\d+)/(\d+)/(\d+)', r'\3-\2-\1', text))
	pat = re.compile(r'(\d+)/(\d+)/(\d+)')
	print(pat.sub(r'\3-\2-\1', text))

	def change_data(m):
		from calendar import month_abbr
		mon_name = month_abbr[int(m.group(1))]
		return '{} {} {}'.format(m.group(2), mon_name, m.group(3))
	print(pat.sub(change_data, text))