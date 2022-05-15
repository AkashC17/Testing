class Puzzle:

    def __init__(self):
        self.rows = 3
        self.cols = 3
        self.inital = [['1', '2', '3'], ['-', '4', '6'], ['7', '5', '8']]
        self.final = [['1', '2', '3'], ['4', '5', '6'], ['7', '8', '-']]

    def read_input(self):
        self.inital.clear()
        self.final.clear()

        print("Enter Intial state")
        for row in range(3):
            values = []
            for col in range(3):
                print("Enter value for positions", row, col, end=" ")
                values.append(input())

            self.inital.append(values)

        print("Enter Final state")
        for row in range(3):
            values = []
            for col in range(3):
                print("Enter value for positions", row, col, end=" ")
                values.append(input())

            self.final.append(values)

        self.rows = 3
        self.cols = 3

    def display(self, grid):
        for i in grid:
            print(*i)

        print()

    def copy_grid(self, grid):
        copy_grid = []
        for j in grid:
            copy_grid.append(j.copy())

        return copy_grid

    def calculate_h(self, grid):
        ans = 0
        final = self.final
        for i in range(3):
            for j in range(3):
                if grid[i][j] != final[i][j]:
                    ans += 1

        return ans

    def valid_move(self, x, y):
        return 0 <= x < 3 and 0 <= y < 3

    def find_empty_space(self, grid):
        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] == '-':
                    return i, j

        return -1, -1

    def move(self, r1, c1, r2, c2, grid):
        temp = grid[r1][c1]
        grid[r1][c1] = grid[r2][c2]
        grid[r2][c2] = temp

        return

    def Sort_Tuple(self,tup): 
        lst = len(tup) 
        for i in range(0, lst):     
            for j in range(0, lst-i-1): 
                if (tup[j][0] > tup[j + 1][0]): 
                    temp = tup[j] 
                    tup[j]= tup[j + 1] 
                    tup[j + 1]= temp 
        return tup 

    def solve(self):
        h = self.calculate_h(self.inital)
        g = 0
        f = g + h

        open = [(int(g),h, self.copy_grid(self.inital))]
        moves = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        temp1 = []
        temp2 = []

        while open:
            cg,ch, current_state = open.pop()

            self.display(current_state)
            temp1.append(current_state)
            crow, ccol = self.find_empty_space(current_state)

            for dr, dc in moves:
                nrow, ncol = crow + dr, ccol + dc

                if self.valid_move(nrow, ncol):
                    copy_cs = self.copy_grid(current_state)

                    temp = copy_cs[nrow][ncol]
                    copy_cs[nrow][ncol] = copy_cs[crow][ccol]
                    copy_cs[crow][ccol] = temp

                    h = self.calculate_h(copy_cs)

                    if h == 0:
                        self.display(copy_cs)
                        return

                    temp2.append((h,copy_cs))

            self.Sort_Tuple(temp2)
            bestGrid = []
            minH=-1
            for m,n in temp2:
                if n not in temp1:
                    bestGrid = n
                    minH = m
                    break
            open.append((cg+1,minH,bestGrid))

s = Puzzle()

while True:
    print('''
    Enter 1 to create new puzzle
    Enter 2 to solve puzzle
    Enter 3 to break''')

    option = int(input())

    if option == 1:
        s.read_input()

    elif option == 2:
        print("Intial state")
        s.display(s.inital)

        print("Goal state")
        s.display(s.final)
        
        print("Solving...........")
        s.solve()

    else:
        break