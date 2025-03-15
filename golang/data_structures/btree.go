package main

import "fmt"

// T Define the minimum degree of the B-Tree
const T = 2

type BTreeNode struct {
	keys     []int
	children []*BTreeNode
	leaf     bool
	n        int
}

type BTree struct {
	root *BTreeNode
}

func NewBTreeNode(leaf bool) *BTreeNode {
	return &BTreeNode{
		keys:     make([]int, 2*T-1),
		children: make([]*BTreeNode, 2*T),
		leaf:     leaf,
		n:        0,
	}
}

// Insert inserts a new key into the B-Tree
func (t *BTree) Insert(k int) {
	r := t.root
	if r.n == 2*T-1 {
		s := NewBTreeNode(false)
		t.root = s
		s.children[0] = r
		t.splitChild(s, 0)
		t.insertNonFull(s, k)
	} else {
		t.insertNonFull(r, k)
	}

}

// insertNonNull inserts a key into a non-full node
func (t *BTree) insertNonFull(x *BTreeNode, k int) {
	i := x.n - 1
	if x.leaf {
		for i >= 0 && k < x.keys[i] {
			x.keys[i+1] = x.keys[i]
			i--
		}
		x.keys[i+1] = k
		x.n++
	} else {
		for i >= 0 && k < x.keys[i] {
			i--
		}
		i++
		if x.children[i].n == 2*T-1 {
			t.splitChild(x, i)
			if k > x.keys[i] {
				i++
			}
		}
		t.insertNonFull(x.children[i], k)
	}
}

// splitChild splits a full child node into two nodes
func (t *BTree) splitChild(x *BTreeNode, i int) {
	y := x.children[i]
	z := NewBTreeNode(y.leaf)
	x.children[i+1] = z
	z.n = T - 1
	for j := 0; j < T-1; j++ {
		z.keys[j] = y.keys[j+T]
	}
	if !y.leaf {
		for j := 0; j < T; j++ {
			z.children[j] = y.children[j+T]
		}
	}
	y.n = T - 1
	for j := x.n; j >= i+1; j-- {
		x.children[j+1] = x.children[j]
	}
	for j := x.n - 1; j >= i; j-- {
		x.keys[j+1] = x.keys[j]
	}
	x.keys[i] = y.keys[T-1]
	x.n++
}

func main() {
	t := &BTree{root: NewBTreeNode(true)}
	t.Insert(10)
	t.Insert(20)
	t.Insert(5)
	t.Insert(6)
	t.Insert(12)
	t.Insert(30)
	t.Insert(7)
	t.Insert(17)

	fmt.Println("B-Tree root keys:", t.root.keys[:t.root.n])
}
