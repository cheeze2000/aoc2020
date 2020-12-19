const fs = require("fs");
let [xs, ys] = fs.readFileSync("input.txt", "utf8").split("\n\n");

const dp = [];
const ns = [];

xs.split("\n").forEach(x => {
  let [n, m] = x.split(": ");

  if (n == "8") {
    const zs = [...Array(6).keys()];
    m = zs.map(i => "42 ".repeat(i + 1)).join("|");
  } else if (n == "11") {
    const zs = [...Array(6).keys()];
    m = zs.map(i => "42 ".repeat(i + 1) + "31 ".repeat(i + 1)).join("|");
  }

  if (m[0] === '"') {
    dp[n] = m[1];
    ns[n] = m[1];
  } else {
    ns[n] = m;
  }
});

function dfs(ns, i) {
  if (dp[i]) return dp[i];

  const n = ns[i];
  dp[i] = '(' + n.replace(/\d+/g, d => dfs(ns, d)) + ')';
  return dp[i];
}

dfs(ns, 0);
dp[0] = '^' + dp[0].replace(/ /g, "") + '$';

const r = new RegExp(dp[0]);
const ans = ys.split("\n").filter(y => r.test(y)).length;
console.log(ans);
