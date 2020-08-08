import edu.princeton.cs.algs4.MinPQ;
import edu.princeton.cs.algs4.StdOut;

import edu.princeton.cs.algs4.Stack;


public class Solver {
    private boolean m_isSolvable = true;
    private Node finalNode;

    private class Node implements Comparable<Node>{
        private final Board board;
        private final int manhattanNumber;
        private final int move;
        private final int priority;
        private final Node prev;
        public Node(Node prev,Board b, int move){
            this.board = b;
            this.move = move;
            this.manhattanNumber = board.manhattan();
            this.priority = move + manhattanNumber;
            this.prev = prev;
        }

        @Override
        public int compareTo(Node n) {
            if(this.priority <  n.priority) return -1;
            else if(this.priority > n.priority) return 1;
            else {
                if(this.manhattanNumber < n.manhattanNumber) return -1;
                else if(this.manhattanNumber > n.manhattanNumber) return 1;
                else return 0;
            }
        }
    }

    // find a solution to the initial board (using the A* algorithm)
    public Solver(Board initial){
        if(initial == null) throw new IllegalArgumentException("You can't initialize with null argument.");
        MinPQ<Node> pqNodes = new MinPQ<>();
        MinPQ<Node> parallelSearch = new MinPQ<>();
        pqNodes.insert(new Node(null, initial, 0));
        parallelSearch.insert(new Node(null, initial.twin(), 0));
        do {
            Node willBeDeletedNode = pqNodes.delMin();
            Node parallelDeletedNode = parallelSearch.delMin();
            Board willBeDeletedBoard = willBeDeletedNode.board;
            Board parallelDeletedBoard = parallelDeletedNode.board;
            if(willBeDeletedBoard.isGoal()) {
                finalNode = willBeDeletedNode;
                break;
            }
            if(parallelDeletedBoard.isGoal()){
                m_isSolvable = false;
                break;
            }
            for(Board element : willBeDeletedBoard.neighbors()){
                Node cross = willBeDeletedNode;
                boolean isAdded = false;
                while(cross != null){
                    if(cross.board.equals(element)) isAdded = true;
                    cross = cross.prev;
                }
                if(!isAdded){
                    Node newNode = new Node(willBeDeletedNode, element, willBeDeletedNode.move+1);
                    pqNodes.insert(newNode);
                }
            }
            for(Board element : parallelDeletedBoard.neighbors()){
                Node cross = parallelDeletedNode;
                boolean isAdded = false;
                while(cross != null){
                    if(cross.board.equals(element)) isAdded = true;
                    cross = cross.prev;
                }
                if(!isAdded){
                    Node newNode = new Node(parallelDeletedNode, element, parallelDeletedNode.move+1);
                    parallelSearch.insert(newNode);
                }
            }
        }while(true);
    }

    // is the initial board solvable? (see below)
    public boolean isSolvable(){
        return m_isSolvable;
    }

    // min number of moves to solve initial board
    public int moves(){
        if(isSolvable())
            return finalNode.move;
        return -1;
    }

    // sequence of boards in a shortest solution
    public Iterable<Board> solution(){
        Stack<Board> stack = new Stack<>();
        if(!isSolvable()){
            return null;
        }
        Node cross = finalNode;
        while(cross != null){
            stack.push(cross.board);
            cross = cross.prev;
        }
        return stack;
    }

    // test client (see below)
    public static void main(String[] args){
        int[][] tiles = new int[][]{
                {6,3,2},
                {7,5,4},
                {1,8,0}
        };
        /*5  6  2
         1  8  4
         7  3  0*/
        Board initial = new Board(tiles);
        // solve the puzzle
        Solver solver = new Solver(initial);

        // print solution to standard output
        if (!solver.isSolvable())
            StdOut.println("No solution possible");
        else {
            StdOut.println("Minimum number of moves = " + solver.moves());
            for (Board board : solver.solution())
                StdOut.println(board.toString());
        }

    }
}
