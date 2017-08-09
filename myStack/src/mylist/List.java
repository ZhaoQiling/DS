package mylist;

public class List <T>{
	
	private Node<T> head = null;
	private Integer length = 0;
	
	public List() {
		
	}
	public Node<T> insertHead(T val) {
		if(head == null) {
			head = new Node<T>(val, null);
			return head;
		}
		Node<T> nodeTemp = new Node<T>(val, head);
		head = nodeTemp;
		return nodeTemp;
	}
	public Node<T> insertNode(int loc, T val) 
			throws ArrayIndexOutOfBoundsException, NegativeArraySizeException, NullPointerException{
		if(val == null)
			throw new NullPointerException();
		if(loc > this.length)
			throw new ArrayIndexOutOfBoundsException();
		if(loc < 0)
			throw new NegativeArraySizeException();
		if(loc == 0) {
			length++;
			return insertHead(val);
		}

		Node<T> nodePrev = head;
		for(int i = 0; i < loc - 1; i++) {
			nodePrev = nodePrev.getNext();
		}
		Node<T> nodeTemp = new Node<T>(val, (nodePrev.getNext() == null) ? null : nodePrev.getNext());
		nodePrev.setNext(nodeTemp);
		length++;
		return nodePrev;
	}
	
//	public Node<T> insertNode(T val){
//		return insertNode(length, val);
//	}
	
	public void traversal() {
		Node<T> pointer = head;
		while(pointer != null) {
			System.out.println(pointer.getData());
			pointer = pointer.getNext();
		}
	}
	public void deleteHead() {
		head = head.getNext();
	}
	public void deleteNodeByIndex(int index) 
			throws ArrayIndexOutOfBoundsException, NegativeArraySizeException, EmptyListExcepiton{
		if(head == null)
			throw new EmptyListExcepiton();
		if(index >= length)
			throw new ArrayIndexOutOfBoundsException();
		if(index < 0)
			throw new  NegativeArraySizeException();
		
		if(index == 0)
		{
			deleteHead();
			length--;
			return;
		}
		Node<T> nodePrev = head;
		for(int i = 0; i < index - 1; i++) {
			nodePrev = nodePrev.getNext();
		}
		nodePrev.setNext(nodePrev.getNext().getNext());
		length--;
	}
	
	public boolean isEmpty() {
		return length == 0;
	}
	public int length() {
		return length;
	}
	
	public T getfirstData() throws EmptyListExcepiton
	{
		if(head == null)
		{
			throw new EmptyListExcepiton();
		}
		return head.getData();
	}
	public static void main(String[] args) throws EmptyListExcepiton{
		// TODO Auto-generated method stub
		List<Integer> mylist = new List<>();
		mylist.insertNode(0, 1);
		mylist.insertNode(1, 4);
		mylist.insertNode(2, 8);
		mylist.insertNode(3, 7);
		
		mylist.insertNode(0, 6);
		mylist.insertNode(5, 111);
		mylist.traversal();
		System.out.println("==============");
		mylist.deleteNodeByIndex(0);
		mylist.deleteNodeByIndex(mylist.length() - 1);
		mylist.traversal();
		System.out.println("==============");
		System.out.println(mylist.getfirstData());
	}
   
}
