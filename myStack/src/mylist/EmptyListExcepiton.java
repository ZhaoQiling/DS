package mylist;

public class EmptyListExcepiton extends Throwable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	public EmptyListExcepiton() {
		
	}
	public EmptyListExcepiton(String s) {
		super(s);
	}
}
