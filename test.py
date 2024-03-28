def print_board(board):
    for row in board:
        print(" ".join(row))
# gpt hehe
def check_win(board):
    # check horizontal spaces
    for row in board:
        if row.count(row[0]) == len(row) and row[0] != ' ':
            return True

    # check vertical spaces
    for col in range(len(board)):
        check = []
        for row in board:
            check.append(row[col])
        if check.count(check[0]) == len(check) and check[0] != ' ':
            return True

    # check diagonals
    if board[0][0] == board[1][1] == board[2][2] != ' ':
        return True
    if board[0][2] == board[1][1] == board[2][0] != ' ':
        return True

    return False        
# function that will keep the game running
def tictactoe():
    board = [[' ' for _ in range(3)] for _ in range(3)]
    player = 'X'

    while True:
        print_board(board)
        print("Player", player, "turn")
        row = int(input("Enter row (0-2): "))
        col = int(input("Enter column (0-2): "))
        
        if row not in [0, 1, 2] or col not in [0, 1, 2]:
            print("Invalid move, try again.")
            continue
        if board[row][col] != ' ':
            print("Invalid move, try again.")
            continue

        board[row][col] = player
        if check_win(board):
            print("Player", player, "wins!")
            break
        player = 'O' if player == 'X' else 'X'

tictactoe()