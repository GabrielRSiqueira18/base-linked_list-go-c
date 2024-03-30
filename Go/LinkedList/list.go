package linkedlist

import "fmt"

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
		return
	}

	current := l.head

	for current.next != nil {
		current = current.next
	}

	current.next = newNode
	newNode.prev = current
}

func (l *LinkedList) InsertPrev(data int) {
	newNode := &node{prev: nil, data: data, next: nil}

	if l.head == nil {
		l.head = newNode
	}

	newNode.next = l.head
	l.head.prev = newNode
	l.head = newNode
}

func (l *LinkedList) Display() {
	if l.head == nil {
		fmt.Print("Empty list!")
		return
	}

	current := l.head

	for current != nil {
		fmt.Printf("Valor: %v\n", current.data)
		current = current.next
	}
}
