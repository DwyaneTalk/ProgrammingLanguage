#	FileName : Chapte2_3.py
'''
通配符匹配：fnmatch模块的fnmatch（大小写是否敏感根据操作系统）和fnmatchcase（大小写敏感）函数
'''

from fnmatch import fnmatch, fnmatchcase

if __name__ == '__main__':
	print(fnmatch('foo.txt', '*.txt'))
	print(fnmatch('foo.txt', '?oo.txt'))
	print(fnmatch('Dat45.csv', 'Dat[0-9]*'))
	print(fnmatchcase('foo.txt', '*.TXT'))
	names = ['Dat1.csv', 'Dat2.csv', 'config.ini', 'foo.py']
	print([name for name in names if fnmatch(name, 'Dat*.csv')])

	addresses = [
		'5412 N CLARK ST',
		'1060 W ADDISON ST',
		'1039 W GRANVILLE AVE',
		'2122 N CLARK ST',
		'4802 N BROADWAY',
	]
	print([addr for addr in addresses if fnmatch(addr, '* ST')])
	print([addr for addr in addresses if fnmatch(addr, '54[0-9]*')])