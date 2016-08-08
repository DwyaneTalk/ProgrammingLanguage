#	FileName : Chapter4_13.py
'''
创建数据处理管道
'''
if __name__ == '__main__':
	import os, fnmatch, gzip, bz2, re
	def gen_find(filepat, top):
		for path, dirlist, filelist in os.walk(top):
			for filename in fnmatch(filelist, filepat):
				yield os.path.join(path, filename)
	def gen_opener(filenames):
		for filename in filenames:
			if filename.endswith('.gz'):
				f = gzip.open(filename)
			elif filename.endswith('bz2'):
				f = bz2.open(filename)
			else:
				f = open(filename)
			yield f
			f.close()
	def gen_concatenate(iterators):
		for it in iterators:
			yield from it
	def gen_grep(pattern, lines):
		pat = re.compile(pattern)
		for line in lines:
			if pat.search(line):
				yield line