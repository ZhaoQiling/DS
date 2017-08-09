package mylist;

public class Node <T>{
	private T data;
	private Node<T> next;
	
	public Node() {
		data = null;
		next = null;
	}
	public Node(T data, Node<T> next) {
		this.data = data;
		this.next = next;
	}
	
	public void setData(T data) {
		this.data = data;
	}
	public void setNext(Node<T> next) {
		this.next = next;
	}
	
	public T getData() {
		return this.data;
	}
	public Node<T> getNext(){
		return next;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}

}
