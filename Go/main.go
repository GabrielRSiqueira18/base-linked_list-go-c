package main

import linkedlist "list/LinkedList"

func main() {
	list := linkedlist.LinkedList{}

	list.InsertNext(10)
	list.InsertNext(20)
	list.InsertNext(30)
	list.InsertNext(40)

	list.InsertPrev(1)
	list.InsertPrev(2)
	list.InsertPrev(3)
	list.InsertPrev(4)

	list.Display()
}
