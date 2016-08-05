#	FileName : Chapter4_4.py
'''
自定义迭代顺序：树的深度遍历
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
		def add_child(self, node):
			self._children.append(node)
		def dfs_traverse1(self):
			yield self
			for child in self._children:
				yield from child.dfs_traverse1()
		def dfs_traverse2(self):
			return DFS_Traverse(self)
	class DFS_Traverse:
		def __init__(self, start_node):
			self._node = start_node
			self._children_iter = None
			self._childiter = None
		def __iter__(self):
			return self
		def __next__(self):
			if self._children_iter is None:
				self._children_iter = iter(self._node)
				return self._node
			elif self._childiter:
				try:
					nextChild = next(self._childiter)
					return nextChild
				except StopIteration:
					self._childiter = None
					return next(self)
			else:
				self._childiter = next(self._children_iter).dfs_traverse2()
				return  next(self)


	root = Node(0)
	child1 = Node(1)
	child2 = Node(2)
	root.add_child(child1)
	root.add_child(child2)
	child1.add_child(Node(3))
	child1.add_child(Node(4))
	child2.add_child(Node(5))
	for child in root.dfs_traverse1():
		print(child, end=' ')
	print()
	for child in root.dfs_traverse2():
		print(child, end=' ')
