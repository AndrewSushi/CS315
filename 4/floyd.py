mat = [[0,  9999,  9999,  9999, -1,  9999],
        [1,  0,  9999,  2,  9999,  9999],
        [9999,  2,  0,  9999,  9999, -8],
        [-4, 9999,  9999,  0,  3,  9999],
        [9999,  7,  9999,  9999,  0,  9999],
        [9999,  5,  10, 9999,  9999,  0]]

mat2 = [[0, 3, 9999, 7],
        [8, 0, 2, 9999],
        [5, 9999, 0, 1],
        [2, 9999, 9999, 0]]

def floyd(mat):
    n = len(mat)
    for k in range(n):
        for i in range(n):
            for j in range(n):
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j])
        for row in mat:
            print(row)
        print("\n")
    return mat

floyd(mat)