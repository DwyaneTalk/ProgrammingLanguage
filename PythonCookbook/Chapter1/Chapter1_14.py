#	FileName : Chapter1_14.py
'''
需要不支持原生比较的对象序列
关键点：
类似于1_13，不过attrgetter是针对基于类对象的属性进行排序，itemgetter是针对基于字典的值进行排序
lambda可以达到itemgetter和attrgetter的功能，但是效率略低
除了sorted函数外，还可以用于min,max等函数
'''
from operator import itemgetter
from operator import attrgetter
class User:
	def __init__(self, uid, fname, lname):
		self.uid, self.fname, self.lname = [uid, fname, lname]
	def __repr__(self):
		return 'Repr_User({!r}-{!s}-{!s})'.format(self.uid, self.fname, self.lname)
	def __str__(self):
		return 'Str_User({!r})'.format(self.uid)


if __name__ == '__main__':
	users = [User(23, 'fname1', 'lname1'), User(3, 'fname2', 'lname2'), User(99, 'fname3', 'lname3')]
	sorted_users1 = sorted(users, key = attrgetter('uid'))
	sorted_users2 = sorted(users, key = lambda u : u.uid)
	print(users)
	print(sorted_users1)
	print(sorted_users2)
	print(min(users, key = lambda k : k.uid))
	print(max(users, key = lambda k : k.uid))