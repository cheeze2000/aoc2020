const fs = require("fs");
let [xs, ys, zs] = fs.readFileSync("input.txt", "utf8").split("\n\n");

function f(xs) {
  const ys = [];
  xs.forEach(x => {
    ys.push([x[1], x[2]]);
    ys.push([x[3], x[4]]);
  });

  ys.sort((a, b) => a[0] - b[0]);

  const zs = [];
  ys.forEach(y => {
    if (zs.length === 0) {
      zs.push(y);
    } else {
      const [a, b] = zs[zs.length - 1];
      if (y[0] > b) {
        zs.push(y);
      } else {
        zs.pop();
        zs.push([a, Math.max(b, y[1])]);
      }
    }
  });

  return zs;
}

function g(xs, rs) {
  return xs.every(x => {
    return rs.some(r => r[0] <= x && x <= r[1]);
  });
}

function h(n, xs) {
  return (xs[1] <= n && n <= xs[2])
      || (xs[3] <= n && n <= xs[4]);
}

function m(xs, ys) {
  let i;
  for (i = 0; i < xs.length; i++) {
    if (xs[i] == ys[i]) continue;
    else return Math.min(xs[i], ys[i]);
  }

  return ys[i];
}

xs = xs.split("\n").map(x => {
  const y = x.split(/: |-| or /);
  return y.map((e, i) => i > 0 ? parseInt(e) : e);
});

const rs = f(xs);

ys = ys.split("\n")[1].split(",").map(Number);

zs = zs.split("\n").slice(1)
  .map(z => z.split(",").map(Number))
  .filter(z => g(z, rs));
zs = Array(xs.length).fill().map((_, i) => zs.map(z => z[i]));

const ws = [];
for (let i = 0; i < xs.length; i++) {
  const ts = [];
  const z = zs[i];
  for (let j = 0; j < xs.length; j++) {
    if (z.every(n => h(n, xs[j]))) ts.push(j);
  }
  ws.push([i, ts]);
}

ws.sort((a, b) => a[1].length - b[1].length);

let ans = 1;
for (let i = 0; i < ws.length; i++) {
  let y = 1;
  if (i == 0) {
    y = ws[0][1][0];
    if (y > 5) y = 1;
  } else {
    const v = m(ws[i - 1][1], ws[i][1]);
    if (v < 6) y = ys[ws[i][0]];
  }

  ans *= y;
}

console.log(ans);
