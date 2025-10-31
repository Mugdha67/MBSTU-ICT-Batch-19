import java.util.Scanner;

public class Main {
    static char[][] board = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
    };

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char currentPlayer = 'X';
        boolean gameEnded = false;

        while (!gameEnded) {
            printBoard();
            int row = -1;
            int col = -1;

            // Read a valid move
            while (true) {
                System.out.println("Player " + currentPlayer + ", enter your move (row and column 0, 1, or 2):");

                if (!scanner.hasNextInt()) {
                    System.out.println("Invalid input. Please enter numbers 0, 1, or 2.");
                    scanner.next(); // consume invalid token
                    continue;
                }
                row = scanner.nextInt();

                if (!scanner.hasNextInt()) {
                    System.out.println("Invalid input. Please enter numbers 0, 1, or 2.");
                    scanner.next(); // consume invalid token
                    continue;
                }
                col = scanner.nextInt();

                if (row < 0 || row > 2 || col < 0 || col > 2) {
                    System.out.println("Out of range. Rows/columns must be 0, 1, or 2.");
                    continue;
                }

                if (board[row][col] != ' ') {
                    System.out.println("This cell is already taken. Try again.");
                    continue;
                }

                break; // valid move
            }

            board[row][col] = currentPlayer;
            if (checkWinner(currentPlayer)) {
                printBoard();
                System.out.println("Player " + currentPlayer + " wins!");
                gameEnded = true;
            } else if (isBoardFull()) {
                printBoard();
                System.out.println("It's a draw!");
                gameEnded = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
        scanner.close();
    }

    static void printBoard() {
        System.out.println("---------");
        for (char[] row : board) {
            System.out.print("| ");
            for (char c : row) {
                System.out.print(c + " ");
            }
            System.out.println("|");
        }
        System.out.println("---------");
    }

    static boolean checkWinner(char player) {
        // Rows, Columns and Diagonals
        for (int i = 0; i < 3; i++)
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                    (board[0][i] == player && board[1][i] == player && board[2][i] == player))
                return true;

        return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
                (board[0][2] == player && board[1][1] == player && board[2][0] == player);
    }

    static boolean isBoardFull() {
        for (char[] row : board)
            for (char c : row)
                if (c == ' ')
                    return false;
        return true;
    }
}