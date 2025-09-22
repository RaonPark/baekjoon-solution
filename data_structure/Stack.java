class Node {
    public int value;
    public Node next;
    
    public Node(int value) {
        this.value = value;
        this.next = null;
    }
}

public class Stack {
    private Node top;
    private int size;
    
    public Stack() {
        top = null;
        size = 0;
    }
    
    public void push(int value) {
        Node node = new Node(value);
        node.next = top;
        top = node;
        size++;
    }
    
    public int pop() {
        if(size == 0) {
            return -1001;
        }
        
        Node temp = top;
        top = top.next;
        size--;
        
        return temp.value;
    }
    
    public int peek() {
        if(size == 0) {
            return -1001;
        }
        return top.value;
    }
    
    public int size() {
        return size;
    }
    
    public static void main(String[] args) {
        Stack st = new Stack();
        st.push(100);
        st.push(200);
        st.push(300);
        
        System.out.println(st.size() == 3);
        System.out.println(st.peek());
        System.out.println(st.pop());
        System.out.println(st.pop());
        System.out.println(st.pop());
        System.out.println(st.pop());
    }
}
