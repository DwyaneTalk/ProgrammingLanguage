#	FileName : Chapter4_2.py
'''
自定义包含序列对象的容器对象，定义容器对象的迭代方式
'''

if __name__ == '__main__':
	class Node:
		def __init__(self, value):
			self._value = value
			self._children = []
		def __repr__(self):
			return 'Node({!r})'.format(self._value)
		def __iter__(self):
			return iter(self._children)
		def add_child(self, childNode):
			self._children.append(childNode)

	root = Node(0)
	root.add_child(Node(1))
	root.add_child(Node(2))

	for node in root:
		print(node)