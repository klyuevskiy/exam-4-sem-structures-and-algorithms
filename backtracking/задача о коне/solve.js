function findPath(matrix, n, x0, y0) {
  matrix.forEach((arr) => {
    for (let i = 0; i < n; i++) arr[i] = 0;
  });

  matrix[x0][y0] = 1;

  const a = [-1, 1, 2, 2, 1, -1, -2, -2],
    b = [-2, -2, -1, 1, 2, 2, -1, 1];

  let q = false;

  function tryFind(i, x, y) {
    for (let j = 0; j < a.length && !q; j++) {
      const u = x + a[j],
        v = y + b[j];

      if (u < 0 || u >= n || v < 0 || v >= n || matrix[u][v] !== 0) continue;

      matrix[u][v] = i;

      if (i < n * n) {
        tryFind(i + 1, u, v);
        if (!q) matrix[u][v] = 0;
      } else {
        q = true;
      }
    }
  }

  tryFind(2, x0, y0);
}

function input(message) {
  return Number.parseInt(prompt(message));
}

const n = input("Введите размеры матрицы");

const matrix = new Array(n);
for (let i = 0; i < n; i++) matrix[i] = new Array(n);

const x0 = input("Введите x"),
  y0 = input("Введите y");

findPath(matrix, n, x0, y0);

matrix.forEach((arr) => console.log(arr));
