// filename Main.java
class Test {
	protected int x, y;
}

class Main {
	public static void main(String args[]) {
		Test t = new Test();
		System.out.println(t.x + " " + t.y);
	}
}
