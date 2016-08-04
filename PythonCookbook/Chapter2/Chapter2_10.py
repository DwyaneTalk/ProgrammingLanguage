#	FileName : Chatper2_10.py
'''
郑则中的Unicode问题
'''

if __name__ == '__main__':
	import re
	num = re.compile('\d+')
	print(num.match('123'))
	print(num.match('\u0661\u0662\u0663'))