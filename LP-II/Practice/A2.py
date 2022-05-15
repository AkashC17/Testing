class Puzzle:
    def __init__(self):
        self.rows = 3
        self.cols = 3
        self.initial = [['1','2','3'],['4','5','6'],['-','7','8']]
        self.final = [['1','2','3'],['4','5','6'],['7','8','-']]

    def read_input(self):
        self.initial.clear()
        self.final.clear()

        print("\nEnter for initial state :\n")
        for i in range(3):
            v=[]
            for j in range(3):
                print("Enter value for position ",i,j,end=" ")
                k = input()
                v.append(k)
            self.initial.append(v)

        print("\nEnter for final state :\n")
        for i in range(3):
            v=[]
            for j in range(3):
                print("Enter value for position ",i,j,end=" ")
                k = input()
                v.append(k)
            self.final.append(v)
        
    def valid_move(self,row,col):
        return 0<=row<3 and 0<=col<3

    def move(self,r1,c1,r2,c2,grid):
        tmp = grid[r1][c1]
        grid[r1][c1] = grid[r2][c2]
        grid[r2][c2] = tmp
        return

    def copy_grid(self,grid):
        copy=[]
        for i in grid:
            copy.append(i.copy())
        return copy
    
    def cal_h(self,grid):
        final = self.final
        ans=0
        for i in range(3):
            for j in range(3):
                if(final[i][j]!=grid[i][j]):
                    ans+=1
        return ans
    
    def sort_tup(self,tup):
        lst = len(tup)
        for i in range(0,lst):
            for j in range(0,lst-i-1):
                if(tup[j][0]>tup[j+1][0]):
                    tmp = tup[j]
                    tup[j]=tup[j+1]
                    tup[j+1]=tmp
        return tup

    def find_empty(self,grid):
        for i in range(3):
            for j in range(3):
                if(grid[i][j]=='-'):
                    return i,j
        return -1,-1

    def display(self,grid):
        for i in grid:
            print(*i)
        print()

    def solve(self):
        g = 0
        h = self.cal_h(self.initial)
        f = g+h

        open = [(int(g),h,self.copy_grid(self.initial))]    
        moves = [(1,0),(-1,0),(0,1),(0,-1)]  

        tmp1 = []
        tmp2 = []

        while(open):
            cg,ch,curG = open.pop()
            self.display(curG)
            tmp1.append(curG)
            cr,cc = self.find_empty(curG)

            for dr,dc in moves:
                nr = cr+dr
                nc = cc+dc

                if(self.valid_move(nr,nc)):
                    copyCS = self.copy_grid(curG)
                    hv = self.cal_h(copyCS)

                    temp = copyCS[nr][nc]
                    copyCS[nr][nc] = copyCS[cr][cc]
                    copyCS[cr][cc] = temp

                    if(hv==0):
                        self.display(copyCS)
                        return
                    
                    tmp2.append((hv,copyCS))

            self.sort_tup(tmp2)
            bstG = []
            mnH = -1

            for p,q in tmp2:
                if(q not in tmp1):
                    bstG = q
                    mnH = p
                    break
            open.append((cg+1,mnH,bstG))

s = Puzzle()

while True:
    print("1]Create new \n 2] Solve \n 3] Exit \n Enter choice =>")
    op = int(input())

    if(op==1):
        s.read_input()
    elif(op==2):
        print("\nInitial\n")
        s.display(s.initial)
        print("\nFinal\n")
        s.display(s.final)
        print("\n Solving.........\n")
        s.solve()
    else:
        break