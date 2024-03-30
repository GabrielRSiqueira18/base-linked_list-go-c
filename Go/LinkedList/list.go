package linkedlist

type node struct {
	prev *node
	data int
	next *node
}

type LinkedList struct {
	head *node
}

func (l *LinkedList) InsertNext(data int) {
	newNode := &node{prev: nil, data: data, next: nil}

	if l.head == nil {
		l.head = newNode
	}

	current := l.head

	for current.next != nil {
		current = current.next
	}

	current.next = newNode
	newNode.prev = current
}
