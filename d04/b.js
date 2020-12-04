const fs = require("fs");

const xs = fs.readFileSync("input.txt", "utf8").split("\n\n");
const ys = xs.map(x => {
  const ms = new Map();
  const zs = x.split(/\s+/);
  zs.forEach(z => {
    const [a, b] = z.split(":");
    ms.set(a, b);
  });
  return ms;
});

const fn = [
  xs => {
    if (xs.has("byr")) {
      const n = parseInt(xs.get("byr"));
      return 1920 <= n && n <= 2002;
    } else {
      return false;
    }
  },
  xs => {
    if (xs.has("iyr")) {
      const n = parseInt(xs.get("iyr"));
      return 2010 <= n && n <= 2020;
    } else {
      return false;
    }
  },
  xs => {
    if (xs.has("eyr")) {
      const n = parseInt(xs.get("eyr"));
      return 2020 <= n && n <= 2030;
    } else {
      return false;
    }
  },
  xs => {
    if (xs.has("hgt")) {
      const ys = xs.get("hgt");
      if (/^\d+cm$/.test(ys)) {
        const n = parseInt(ys);
        return 150 <= n && n <= 193;
      } else if (/^\d+in$/.test(ys)) {
        const n = parseInt(ys);
        return 59 <= n && n <= 76;
      }
    } else {
      return false;
    }
  },
  xs => {
    if (xs.has("hcl")) {
      const ys = xs.get("hcl");
      return /^#[0-9a-f]{6}$/.test(ys);
    } else {
      return false;
    }
  },
  xs => {
    if (xs.has("ecl")) {
      const ys = "amb blu brn gry grn hzl oth".split(" ");
      return ys.includes(xs.get("ecl"));
    } else {
      return false;
    }
  },
  xs => {
    if (xs.has("pid")) {
      return /^\d{9}$/.test(xs.get("pid"));
    } else {
      return false;
    }
  }
];

console.log(ys.filter(y => fn.every(f => f(y))).length);
