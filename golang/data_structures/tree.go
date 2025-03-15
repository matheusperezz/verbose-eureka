package main

const (
	RED   = true
	BLACK = false
)

type Node struct {
	value  int
	color  bool
	left   *Node
	right  *Node
	parent *Node
}

type RBTree struct {
	root *Node
}

func (t *RBTree) rotateLeft(x *Node) {
	y := x.right
	x.right = y.left
	if y.left != nil {
		t.root = y
	} else if x == x.parent.left {
		x.parent.left = y
	} else {
		x.parent.right = y
	}
	y.left = x
	x.parent = y
}

func main() {

}
