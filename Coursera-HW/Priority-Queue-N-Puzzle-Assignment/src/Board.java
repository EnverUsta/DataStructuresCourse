import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;




public final class Board {
    private final int[][] tiles;
    private final int[][] twinTiles;

    private int[][] exch(int rowP, int colP, int rowQ, int colQ) {
        int[][] newTiles = new int[tiles.length][tiles.length];
        for (int row = 0; row < tiles.length; row++){
            for(int col = 0; col < tiles.length; col++){
                newTiles[row][col] = tiles[row][col];
            }
        }
        int temp = newTiles[rowP][colP];
        newTiles[rowP][colP] = newTiles[rowQ][colQ];
        newTiles[rowQ][colQ] = temp;
        return newTiles;
    }

    private List<Integer> findEmptyTilePosition(int[][] tiles) {
        List<Integer> position = new ArrayList<>();
        boolean isFound = false;
        for (int row = 0; row < this.dimension(); row++)
            for(int col = 0; col < this.dimension(); col++){
                if(tiles[row][col] == 0){
                    position.add(row);
                    position.add(col);
                    isFound = true;
                    break;
                }
                if(isFound) break;
            }
        return position;
    }

    // create a board from an n-by-n array of tiles,
    // where tiles[row][col] = tile at (row, col)
    public Board(int[][] tiles) {
        this.tiles = new int[tiles.length][tiles.length];
        for (int i = 0; i < tiles.length; i++)
        {
            for(int j = 0; j < tiles.length; j++){
                this.tiles[i][j] = tiles[i][j];
            }
        }
        List<Integer> positionOfEmptyTile = findEmptyTilePosition(tiles);
        int rowEmpty = positionOfEmptyTile.get(0);
        int colEmpty = positionOfEmptyTile.get(1);
        int rowP, colP, rowQ = 0, colQ = 0;
        do{
            rowP = StdRandom.uniform(1, dimension());
            colP = StdRandom.uniform(0, dimension());
            rowQ = rowP - 1;
            colQ = colP;
        }while((rowP == rowEmpty && colP == colEmpty) || (rowQ == rowEmpty && colQ == colEmpty));
        twinTiles = exch(rowP, colP, rowQ, colQ);
    }

    // string representation of this board
    public String toString() {
        StringBuilder s = new StringBuilder();
        s.append(this.dimension() + "\n");
        for (int i = 0; i < tiles.length; i++) {
            for (int j = 0; j < tiles.length; j++) {
                s.append(String.format("%2d ", tiles[i][j]));
            }
            s.append("\n");
        }
        return s.toString();
    }

    // board dimension n
    public int dimension() {
        return tiles.length;
    }

    // number of tiles out of place
    public int hamming(){
        int hammingCount = 0;
        for (int row = 0; row < tiles.length; row++)
        {
            for(int col = 0; col < tiles.length; col++)
            {
                if(tiles[row][col] == 0) continue;
                int numberThatShouldBeThere = row * tiles.length + col + 1;
                if(tiles[row][col] != numberThatShouldBeThere)  hammingCount++;
            }
        }
        return hammingCount;
    }

    // sum of Manhattan distances between tiles and goal
    public int manhattan() {
        int manhattanNumber = 0;
        for (int row = 0; row < tiles.length; row++) {
            for (int col = 0; col < tiles.length; col++) {
                if(tiles[row][col] == 0) continue;
                int rowFuture = tiles[row][col] / tiles.length;
                if(tiles[row][col] % tiles.length == 0) rowFuture--;
                int colFuture = tiles[row][col] % tiles.length;
                if(colFuture % tiles.length == 0) colFuture = tiles.length-1;
                else colFuture--;

                int rowDistance = Math.abs(row - rowFuture);
                int colDistance = Math.abs(col - colFuture);
                manhattanNumber += rowDistance + colDistance;
            }
        }
        return  manhattanNumber;
    }

    // is this board the goal board?
    public boolean isGoal(){ return hamming() == 0; }

    // does this board equal y?
    public boolean equals(Object y){
        if(y == this) return true;
        if(y == null) return false;
        if(y.getClass() != this.getClass()) return false;
        Board that = (Board) y;
        if(that.dimension() != this.dimension()) return false;
        return Arrays.deepEquals(that.tiles, this.tiles);
    }

    // all neighboring boards
    public Iterable<Board> neighbors(){
        Stack<Board> stack = new Stack<>();
        List<Integer> positionEmptyTile = findEmptyTilePosition(tiles);
        int rowOfEmptyTile = positionEmptyTile.get(0);
        int colOfEmptyTile = positionEmptyTile.get(1);
        if(rowOfEmptyTile-1 >= 0){
            int[][] newBoard = exch(rowOfEmptyTile, colOfEmptyTile, rowOfEmptyTile-1, colOfEmptyTile);
            stack.add(new Board(newBoard));
        }
        if(rowOfEmptyTile+1 < tiles.length){
            int[][] newBoard = exch(rowOfEmptyTile, colOfEmptyTile, rowOfEmptyTile+1, colOfEmptyTile);
            stack.add(new Board(newBoard));
        }
        if(colOfEmptyTile-1 >= 0){
            int[][] newBoard = exch(rowOfEmptyTile, colOfEmptyTile, rowOfEmptyTile, colOfEmptyTile-1);
            stack.add(new Board(newBoard));
        }
        if(colOfEmptyTile+1 < tiles.length){
            int[][] newBoard = exch(rowOfEmptyTile, colOfEmptyTile, rowOfEmptyTile, colOfEmptyTile+1);
            stack.add(new Board(newBoard));
        }
        return stack;
    }

    // a board that is obtained by exchanging any pair of tiles
    public Board twin(){
        return new Board(twinTiles);
    }

    // unit testing (not graded)
    public static void main(String[] args)
    {
        int[][] tiles = new int[][]{
                {1,4,3},
                {2,0,6},
                {7,5,8}
        };
        Board board = new Board(tiles);
        for(Board elem : board.neighbors()){
            StdOut.println(elem.toString());
        }
    }
}
