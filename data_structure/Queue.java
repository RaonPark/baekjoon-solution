class Node {
    public int value;
    public Node next;
    
    public Node(int value) {
        this.value = value;
        this.next = null;
    }
}

public class Queue {
    private Node front;
    private int size;
    
    public Queue() {
        front = null;
        size = 0;
    }
    
    public void push(int value) {
        Node node = new Node(value);
        
        if(front == null) {
            front = node;
        } else {
            Node temp = front;
            while(temp.next != null) {
                temp = temp.next;
            }
            
            temp.next = node;
        }
        
        size++;
    }
    
    public int pop() {
        Node temp = front;
        front = front.next;
        size--;
        
        return temp.value;
    }
    
    public int peek() {
        return front.value;
    }
    
    public int size() {
        return size;
    }
    
    public static void main(String[] args) {
        Queue q = new Queue();
        
        q.push(100);
        q.push(200);
        q.push(300);
        
        System.out.println(q.size() == 3);
        System.out.println(q.peek() == 100);
        System.out.println(q.pop());
        System.out.println(q.pop());
        System.out.println(q.pop());
    }
}
