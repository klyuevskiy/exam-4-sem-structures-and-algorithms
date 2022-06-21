// n - кол-во строк/столбцов/ферзей

// поиск первого возможного решения
function findOneSolution(n) {
  const x = new Array(n),
    a = new Array(n),
    b = new Array(2 * n - 2),
    c = new Array(2 * n - 2);

  for (let i = 0; i < n; i++) {
    a[i] = true;
  }

  for (let i = 2 * n - 2; i >= 0; i--) {
    b[i] = true;
    c[i] = true;
  }

  let q = false;

  function trySolve(i) {
    for (let j = 0; j < n && !q; j++) {
      if (!a[j] || !b[i + j] || !c[i - j + n - 1]) continue;
      x[i] = j;
      a[j] = false;
      b[i + j] = false;
      c[i - j + n - 1] = false;

      if (i + 1 < n) {
        trySolve(i + 1);
        if (!q) {
          a[j] = true;
          b[i + j] = true;
          c[i - j + n - 1] = true;
        }
      } else q = true;
    }
  }

  trySolve(0);
  console.log(n, " board one solution: ", x);

  return x;
}

function isEqual(a, b) {
  for (let i = 0; i < a.length; i++) if (a[i] != b[i]) return false;
  return true;
}

// поиск всех решений
//также проверяет переданное решение, яыляется ли оно решением
function findAll(n, findedSolution) {
  const x = new Array(n),
    a = new Array(n),
    b = new Array(2 * n - 2),
    c = new Array(2 * n - 2);

  for (let i = 0; i < n; i++) {
    a[i] = true;
  }

  for (let i = 2 * n - 2; i >= 0; i--) {
    b[i] = true;
    c[i] = true;
  }

  let isFindOneSolution = false;

  let cnt = 0;
  function trySolve(i) {
    for (let j = 0; j < n; j++) {
      if (!a[j] || !b[i + j] || !c[i - j + n - 1]) continue;

      x[i] = j;
      a[j] = false;
      b[i + j] = false;
      c[i - j + n - 1] = false;

      if (i + 1 < n) trySolve(i + 1);
      else {
        cnt++;
        if (isEqual(x, findedSolution)) isFindOneSolution = true;
      }

      a[j] = true;
      b[i + j] = true;
      c[i - j + n - 1] = true;
    }
  }

  trySolve(0);

  console.log(n, " boards Solutions count: ", cnt);

  if (isFindOneSolution) console.log("One solution is finded");
  else console.log("One solution is not finded");
}

for (let n = 4; n <= 13; n++) {
  findAll(n, findOneSolution(n));
}
