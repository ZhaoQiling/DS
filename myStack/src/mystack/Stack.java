package mystack;
import mylist.EmptyListExcepiton;
import mylist.List;
import mylist.EmptyListExcepiton;
public class Stack <T>{
	List<T> list = null;
	public Stack() {
		list = new List<T>();
	}
	public void push(T val) {
		list.insertHead(val);
	}
	public void pop() {
		list.deleteHead();
	}
	public int size() {
		return list.length();
	}
	
	//this is test method
	public void checkItem() {
		list.traversal();
	}
	
	public T peek() throws EmptyListExcepiton {
		return list.getfirstData();
	}
	
	public boolean isEmpty() {
		return list.length() == 0;
	}
	public void emptyStack() {
		list = null;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack<Integer> mystack = new Stack<>();
		mystack.push(1);
		mystack.push(2);
		mystack.push(5);
		mystack.push(7);
		mystack.checkItem();
		mystack.pop();
		mystack.pop();
		mystack.push(555);
		mystack.checkItem();
		mystack.pop(); mystack.pop();mystack.pop(); 
		mystack.push(1);
		mystack.checkItem();
		try {
			System.out.println(mystack.peek());
		} catch (EmptyListExcepiton e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
