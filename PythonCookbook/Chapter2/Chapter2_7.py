#	FileName : Chapter2_7.py
'''
正则中：(.)可以匹配除换行符之外的任何字符，(.*)可以匹配多个除换行符之外的任意字符串（尽可能长）,(.*?)可以匹配除换行符外的任意字符串（尽可能短）
'''

import  re
if __name__ == '__main__':
	str_pat1 = re.compile(r'\"(.*)\"')
	str_pat2 = re.compile(r'\"(.*?)\"')
	text1 = 'Computer says "no"'
	text2 = 'Computer says "no." Phone says "yes."'
	print(str_pat1.findall(text1))
	print(str_pat1.findall(text2))
	print(str_pat2.findall(text1))
	print(str_pat2.findall(text2))